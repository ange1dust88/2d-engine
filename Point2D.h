
#ifndef POINT2D_H
#define POINT2D_H
#include "Player.h"
#include <SFML/Graphics.hpp>

class Point2D
{
public:
    sf::RenderWindow* window;
    sf::Vector2i pos;
    sf::Color pixel;

    Point2D(sf::RenderWindow* _window, sf::Vector2i _pos);
    void setPixel(sf::Color color);
    sf::Color getPixel();
};

class LineSegment
{
    sf::RenderWindow* window;

public:
    LineSegment(sf::RenderWindow* _window);
    void drawLine(int x0, int y0, int x1, int y1, sf::Color color);
};

#endif // POINT2D_H