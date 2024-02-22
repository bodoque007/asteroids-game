#pragma once
#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(float x, float y, float radius, int numSides);

    void update();
    void render(sf::RenderWindow& window) const;

    sf::FloatRect getBounds() const;
    bool operator==(const Asteroid& other) const;
    float getRadius();
    sf::Vector2f getPosition();

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float rotationalMovement;
};