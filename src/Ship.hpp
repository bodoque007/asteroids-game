#pragma once
#include <SFML/Graphics.hpp>

class Ship {
public:
    Ship(float x, float y);
    void update(); // This method updates the ship's logic
    void render(sf::RenderWindow& window) const;
    void move();
    void accelerate();
    void rotateLeft();
    void rotateRight();
    sf::Vector2f getPosition();
    float getRotation();
    sf::FloatRect getBounds() const;
private:
    sf::ConvexShape shipShape;
    sf::Vector2f speed;
    static constexpr float MAX_SPEED = 6.0f;
    static constexpr float FRICTION = 0.98f;
    static constexpr float ACCELERATION = 0.2f;
    static constexpr float ROTATION_SPEED = 3.0f;
};
