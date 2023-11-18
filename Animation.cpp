#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2f imgCount, float switchTime)
{
    this ->imgCount = imgCount;
    this -> switchTime = switchTime;
    totalTime =0.0f;
    currentImg.x =0;
    uvRect.width = texture->getSize().x / float(imgCount.x);
    uvRect.height = texture->getSize().y / float(imgCount.y)-5;

}

Animation::~Animation()
{

}

void Animation::Update(int row, float deltaTime, bool faceRight){
    currentImg.y = row;
    totalTime += deltaTime;
    if(totalTime>=switchTime){
        totalTime-=switchTime;
        currentImg.x++;
        if(currentImg.x >=imgCount.x){
            currentImg.x = 0;
        }
    }
    
    uvRect.top = currentImg.y * uvRect.height;

    if(faceRight){
        uvRect.left = currentImg.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    } else{
        uvRect.left = (currentImg.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }

}
