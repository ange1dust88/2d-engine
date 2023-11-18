#include <SFML/Graphics.hpp>

#ifndef COLLIDER_H
#define COLLIDER_H

#pragma once

class Collider
{
public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    void Move(float dx, float dy){ body.move(dx,dy);}
    bool CheckColision(Collider& other, float push);
    sf::Vector2f GetPosition(){ return body.getPosition();}
    sf::Vector2f GetHalfSize(){ return body.getSize() / 2.0f;}
private:
    sf::RectangleShape& body;
};

#endif