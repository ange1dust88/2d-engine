#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"

Player::Player(sf::Texture* texture, sf::Vector2f imgCount, float switchTime, float speed)
    : animation(texture, imgCount, switchTime){
    this->speed = speed;
    row = 0;
    faceRight = true;
    body.setSize(sf::Vector2f(100.0f, 150.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(400.0f, 400.0f);
    body.setTexture(texture);


}

Player::~Player()
{

}

void Player::Update(float deltaTime){
    sf::Vector2f movement(0.0f, 0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= speed*deltaTime;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += speed*deltaTime;
    if(movement.x == 0.0f){
        row = 0;
    }else{
        row = 1;

        if(movement.x > 0.0f){
            faceRight = true; 
        } else{
            faceRight = false;
        }
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}
void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
}