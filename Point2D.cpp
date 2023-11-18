// point2d.cpp

#include "Point2D.h"

Point2D::Point2D(sf::RenderWindow* _window, sf::Vector2i _pos)
{
    window = _window;
    pos = _pos;
}

void Point2D::setPixel(sf::Color color)
{
    pixel = color;
    sf::Vertex vertex(sf::Vector2f(pos.x, pos.y), color);
    window->draw(&vertex, 1, sf::Points);
}

sf::Color Point2D::getPixel()
{
    return pixel;
}

LineSegment::LineSegment(sf::RenderWindow* _window)
{
    window = _window;
}

void LineSegment::drawLine(int x0, int y0, int x1, int y1, sf::Color color)
{
    int x;
    float dy, dx, y, m;
    dy = y1 - y0;
    dx = x1 - x0;
    m = dy / dx;
    y = y0;
    for (x = x0; x <= x1; x++)
    {
        Point2D(window, sf::Vector2i(x, static_cast<int>(y + 0.5))).setPixel(color);
        y += m;
    }
}