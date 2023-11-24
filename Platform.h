#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform {
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position,sf::Color color);
    ~Platform();

    void Draw(sf::RenderWindow& window);
    Collider GetCollider();

private:
    sf::RectangleShape body;
};

#endif