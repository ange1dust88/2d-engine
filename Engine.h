#include <SFML/Graphics.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"
#include "Animation.h"
#include <fstream>
#include "Platform.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine : public sf::RenderWindow {
public:
    Engine(unsigned int fps, std::string title, unsigned int w_width, unsigned int w_height);
    ~Engine();
    void run();
    void setFullScreen(bool isFullScreen);  
    void SetResolution(unsigned int new_width, unsigned int new_height);
    void logError(const std::string& errorMessage);
    void closeGame();
    void drawToBuffer();
    void swapBuffers();
    

private:
    unsigned int fps;
    sf::Event evnt;
    void update(sf::Time deltaTime);
    void render();
    void handleEvents();
    sf::RenderTexture buffer1;  
    sf::RenderTexture buffer2;  
    sf::Sprite displaySprite;   
    bool useFirstBuffer;  
    bool isFullscreen;
    sf::Color bcolor;
    
    PrimitiveRenderer primitiveRenderer;  
};

#endif
