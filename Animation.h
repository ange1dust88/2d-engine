#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#pragma once

class Animation
{
public:
    Animation(sf::Texture* texture, sf::Vector2f imgCount, float switchTime);
    ~Animation();

    void Update (int row, float deltaTime, bool faceRight);

private:


public:
    sf::IntRect uvRect;

private:
    sf::Vector2f imgCount;
    sf::Vector2u currentImg;
    float totalTime;
    float switchTime;

};

#endif