#include <SFML/Graphics.hpp>
#include <iostream>
#include "Point2D.h"
#include "Collider.h"
#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#pragma once

class PrimitiveRenderer {
public:
    PrimitiveRenderer(sf::RenderWindow* _window);
    ~PrimitiveRenderer();
    PrimitiveRenderer() = default;  
    sf::RenderWindow* window;
    void drawCircle(sf::Vector2f center, float radius, sf::Color color);
    void drawPolyline(sf::Vector2i p1, sf::Vector2i p2, sf::Vector2i p3, sf::Color color);
    void drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color);
    void drawRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    void drawRectangleWithFrame(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color frameColor);
    void drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
    void drawCircleSym(sf::Vector2f center, float radius, sf::Color color);
    void drawEllipse(sf::Vector2f center, float radiusX, float radiusY, sf::Color color);
    void drawPolygon(const std::vector<sf::Vector2f>& points, sf::Color color);



    
};

#endif



