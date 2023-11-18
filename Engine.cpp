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
    bool magenta = true;
    sf::Texture playerTexture;


    if (!playerTexture.loadFromFile("C:/Users/Lev/Desktop/code/build/Debug/tux.png")) {
        logError("Failed to load player texture!");
        return;
    }
    Player player(&playerTexture, sf::Vector2f(3, 9), 0.1f, 100.0f);
    float deltaTime = 0.0f;
    sf::Clock timer;

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

        // Clear the screen at the beginning of each frame
        clear(sf::Color::Black);  // Use the desired background color

        if (timer.getElapsedTime().asSeconds() >= 2) {
            timer.restart();

            if (magenta) {
                
                magenta = false;
            } else {
                
                magenta = true;
            }
        }

        primitiveRenderer.drawCircle(sf::Vector2f(200, 200), 50, sf::Color::Red);


        std::vector<sf::Vector2f> polygonPoints = {
            {200.0f, 200.0f},
            {350.0f, 100.0f},
            {400.0f, 300.0f},
            {150.0f, 150.0f}
        };
        sf::Color polygonColor = sf::Color::Blue;
        primitiveRenderer.drawPolygon(polygonPoints, polygonColor);

        player.Update(deltaTime);
        player.Draw(*this);

        // Display the contents of the render window
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
    // Update game logic based on deltaTime
}

void Engine::render() {
    //support for cleaning the screen (and ultimately any bitmap) to a given color
    clear(sf::Color:: White);  

    // Draw game elements

    display();  
}
void Engine::handleEvents() {
    sf::Event event;
    while (pollEvent(event)) {
        switch (event.type) {
            //closing the game
            case sf::Event::Closed:
                closeGame();
                break;
            //keyboard and mouse support
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    //pause the game, show menu, etc
                }
            break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //perform an action
                }
            break;
        }
    }
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