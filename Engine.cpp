#include "Engine.h"

//initialization of the graphics library
Engine::Engine(unsigned int fps, std::string title, unsigned int w_width, unsigned int w_height)
: sf::RenderWindow(sf::VideoMode(w_width, w_height), title),
buffer1(), buffer2(), displaySprite(), useFirstBuffer(true) {
    //number of animation frames per second
    this->fps = fps;
    setFramerateLimit(fps);
    buffer1.create(w_width, w_height);  
    buffer2.create(w_width, w_height);

    primitiveRenderer = PrimitiveRenderer(this); 
}

Engine::~Engine() {
    closeGame();
}


//main game loop using a timer

void Engine::run() {
    //player
    sf::Texture playerTexture; 
    playerTexture.loadFromFile("C:/Users/Lev/Desktop/code/build/Debug/tux.png");
    Player player(&playerTexture, sf::Vector2f(3, 9), 0.3f, 100.0f);

    //borders
  Platform border1(nullptr, sf::Vector2f(1600.0f, 0.f), sf::Vector2f(0.0f, 0.0f), sf::Color::Magenta);
  Platform border2(nullptr, sf::Vector2f(0.0f, 1200.f), sf::Vector2f(800.0f, 0.0f), sf::Color::Magenta);
  Platform border3(nullptr, sf::Vector2f(0.0f, 1200.f), sf::Vector2f(0.0f, 600.0f), sf::Color::Magenta);
  Platform border4(nullptr, sf::Vector2f(1600.0f, 0.f), sf::Vector2f(800.0f, 600.0f), sf::Color::Magenta);

   //platforms
    Platform platform1(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(100.0f, 500.0f), sf::Color(173, 216, 230));
    Platform platform2(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(300.0f, 500.0f), sf::Color(255, 182, 193));
    Platform platform3(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(500.0f, 500.0f), sf::Color(144, 238, 144));
    Platform platform4(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(700.0f, 500.0f), sf::Color(230, 230, 250));

//sf::Color(173, 216, 230)); sf::Color(255, 182, 193)); sf::Color(144, 238, 144));  sf::Color(230, 230, 250));

    //timer
    float deltaTime = 0.0f;
    sf::Clock timer;
    sf::Clock backgroundTimer;
    bcolor = sf::Color(220, 220, 220);


    while (isOpen()) {
        deltaTime = timer.restart().asSeconds();

        while (pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                close();
            }

            if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Enter) {
                close();
            }

            
        }
        if (backgroundTimer.getElapsedTime().asSeconds() >= 3)
        {
            backgroundTimer.restart();
            bcolor = sf::Color(rand() % 128 + 128, rand() % 128 + 128, rand() % 128 + 128);
        }
        


        // Clear the screen at the beginning of each frame
        clear(sf::Color(bcolor)); 

        //demo start

        //primitiveRenderer
        /* primitiveRenderer.drawCircle(sf::Vector2f(100, 100), 50, sf::Color(50, 150, 255));
        primitiveRenderer.drawPolyline(sf::Vector2i(100,50), sf::Vector2i(56, 125), sf::Vector2i(144, 125), sf::Color(255, 192, 203));
        primitiveRenderer.drawCircle(sf::Vector2f(700, 100), 50, sf::Color(255, 192, 203));
        primitiveRenderer.drawPolyline(sf::Vector2i(656, 75), sf::Vector2i(744, 75), sf::Vector2i(700, 150), sf::Color(50, 150, 255));*/
        primitiveRenderer.animatedCircle(sf::Vector2f(400, 300), 20.0f, 100.0f, 1.0f, sf::Color(173, 216, 230)); 
        primitiveRenderer.animatedCircle(sf::Vector2f(150, 300), 20.0f, 100.0f, 1.0f, sf::Color(255, 182, 193)); 
        primitiveRenderer.animatedCircle(sf::Vector2f(650, 300), 20.0f, 100.0f, 0.0f, sf::Color(144, 238, 144));

        primitiveRenderer.animatedCircle(sf::Vector2f(400, 100), 20.0f, 100.0f, 0.0f, sf::Color(230, 230, 250)); 
        primitiveRenderer.animatedCircle(sf::Vector2f(150, 100), 20.0f, 100.0f, 0.0f, sf::Color(240, 128, 128)); 
        primitiveRenderer.animatedCircle(sf::Vector2f(650, 100), 20.0f, 100.0f, 0.0f, sf::Color(135, 206, 250)); 



        

        

        //border collion
        border1.GetCollider().CheckColision(player.getCollider(), 1.0f);
        border2.GetCollider().CheckColision(player.getCollider(), 1.0f);
        border3.GetCollider().CheckColision(player.getCollider(), 1.0f);
        border4.GetCollider().CheckColision(player.getCollider(), 1.0f);
        //platform collision
        platform1.GetCollider().CheckColision(player.getCollider(), 0.0f);
        platform2.GetCollider().CheckColision(player.getCollider(), 0.4f);
        platform3.GetCollider().CheckColision(player.getCollider(), 0.8f);
        platform4.GetCollider().CheckColision(player.getCollider(), 1.0f);
        //border draw
        border1.Draw(*this);
        border2.Draw(*this);
        border3.Draw(*this);
        border4.Draw(*this);
        //platform draw
        platform1.Draw(*this);
        platform2.Draw(*this);
        platform3.Draw(*this);
        platform4.Draw(*this);
       
        //demo end

        //player
        player.Update(deltaTime);
        player.Draw(*this);

        display();
    }
    
}


//multibuffering technique
void Engine::drawToBuffer() {
    sf::RenderTexture& activeBuffer = (useFirstBuffer) ? buffer1 : buffer2;
    activeBuffer.clear();
    activeBuffer.display();
    displaySprite.setTexture(activeBuffer.getTexture());
    draw(displaySprite);
    useFirstBuffer = !useFirstBuffer; 
}

void Engine::swapBuffers() {
    sf::RenderTexture& activeBuffer = (useFirstBuffer) ? buffer1 : buffer2;
    displaySprite.setTexture(activeBuffer.getTexture());
    draw(displaySprite); 
    useFirstBuffer = !useFirstBuffer;  
}

void Engine::update(sf::Time deltaTime) {
    
}

void Engine::render() {
    
    clear(sf::Color:: White);  

    display();  
}

//parameterizing the graphic mode
void Engine::setFullScreen(bool isFullScreen) {
    if (isFullScreen) {
        create(sf::VideoMode::getFullscreenModes()[0], "Title", sf::Style::Fullscreen);
    } else {
        create(sf::VideoMode::getDesktopMode(), "Title", sf::Style::Default);
    }
}

void Engine::SetResolution(unsigned int new_width, unsigned int new_height) {
    setSize(sf::Vector2u(new_width, new_height));
}

//closing the game
void Engine::closeGame() {
    close(); 
    //
    //
    std::cout << "Game closed" << std::endl;
}

//error handling with the ability to display or log to a file of diagnostic messages
 void Engine::logError(const std::string& errorMessage) {
    std::ofstream logFile("error_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Error: " << errorMessage << std::endl;
        logFile.close();
    } else {
        std::cout << "Error logging failed: Unable to open the log file!" << std::endl;
    }
    std::cout << "Error: " << errorMessage << std::endl;
}