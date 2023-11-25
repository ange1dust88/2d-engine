
#include "PrimitiveRenderer.h"
#define pi 3.141592653589793238462643383279502884L

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow* _window) {
    window = _window;
}

PrimitiveRenderer::~PrimitiveRenderer() {}

void PrimitiveRenderer::drawCircle(sf::Vector2f center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setFillColor(color);
    circle.setPosition(center - sf::Vector2f(radius, radius));
    window->draw(circle);
}

void PrimitiveRenderer::drawPolyline(sf::Vector2i p1, sf::Vector2i p2, sf::Vector2i p3, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(static_cast<sf::Vector2f>(p1), color),
        sf::Vertex(static_cast<sf::Vector2f>(p2), color),
        sf::Vertex(static_cast<sf::Vector2f>(p3), color),
        sf::Vertex(static_cast<sf::Vector2f>(p1), color)
    };
    window->draw(line, 4, sf::LineStrip);
}

void PrimitiveRenderer::drawTriangle(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Color color) {
    sf::VertexArray triangle(sf::Triangles, 3);
    triangle[0].position = p1;
    triangle[1].position = p2;
    triangle[2].position = p3;
    triangle[0].color = color;
    triangle[1].color = color;
    triangle[2].color = color;
    window->draw(triangle);
}

void PrimitiveRenderer::drawRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    sf::RectangleShape rectangle(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    window->draw(rectangle);
}

void PrimitiveRenderer::drawRectangleWithFrame(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color frameColor) {
    sf::RectangleShape rectangle(size);
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(frameColor);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(position);
    window->draw(rectangle);
}

void PrimitiveRenderer::drawLine(sf::Vector2f p1, sf::Vector2f p2, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(p1, color),
        sf::Vertex(p2, color)
    };
    window->draw(line, 2, sf::Lines);
}




void PrimitiveRenderer::drawEllipse(sf::Vector2f center, float radiusX, float radiusY, sf::Color color) {
    const int numSegments = 100; 
    const float twoPi = 2.0 * pi;

    float angleIncrement = twoPi / numSegments;

    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = center.x + radiusX * cos(angle);
        float y = center.y + radiusY * sin(angle);

   
        sf::Vertex vertex(sf::Vector2f(x, y), color);
        window->draw(&vertex, 1, sf::Points);
    }
}


void PrimitiveRenderer::drawPolygon(const std::vector<sf::Vector2f>& points, sf::Color color) {
    if (points.size() < 2) {
        return;
    }

    for (size_t i = 0; i < points.size() - 1; ++i) {
        sf::Vertex line[] = {
            sf::Vertex(points[i], color),
            sf::Vertex(points[i + 1], color)
        };
        window->draw(line, 2, sf::Lines);
    }
    sf::Vertex closingLine[] = {
        sf::Vertex(points.back(), color),
        sf::Vertex(points.front(), color)
    };
    window->draw(closingLine, 2, sf::Lines);
}


void PrimitiveRenderer::animatedCircle(sf::Vector2f center, float initialRadius, float maxRadius, float animationSpeed, sf::Color color) {
    const int numSegments = 100;
    const float twoPi = 2.0 * pi;
    float angleIncrement = twoPi / numSegments;

    static float currentRadius = initialRadius;
    static bool increasing = true;
    if (increasing) {
        currentRadius += animationSpeed;
        if (currentRadius >= maxRadius) {
            currentRadius = maxRadius;
            increasing = false;
        }
    } else {
        currentRadius -= animationSpeed;
        if (currentRadius <= initialRadius) {
            currentRadius = initialRadius;
            increasing = true;
        }
    }
    sf::CircleShape circle(currentRadius);
    circle.setFillColor(color);
    circle.setPosition(center - sf::Vector2f(currentRadius, currentRadius));
    window->draw(circle);
}