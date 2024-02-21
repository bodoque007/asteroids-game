// Ship.hpp

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
    sf::RectangleShape shipShape;
    sf::Vector2f speed;
};
