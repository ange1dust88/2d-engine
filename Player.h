#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player {
public:
    Player(sf::Texture* texture, sf::Vector2f imgCount, float switchTime, float speed);
    ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    sf::Vector2f getPos() { return body.getPosition();}
    Collider getCollider() { return Collider(body); }
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};
#endif