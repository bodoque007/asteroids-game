// Ship.cpp

#include "Ship.hpp"
#include <cmath>

Ship::Ship(float x, float y) {
    // Ship-specific initialization logic

    speed = sf::Vector2f(0.f, 0.f);
    shipShape.setSize(sf::Vector2f(20, 40));  // Set the size of the rectangle
    shipShape.setFillColor(sf::Color::White);
    shipShape.setPosition(400.0f, 300.0f);  // Set the initial position
}

void Ship::move() {
    // Ship-specific update logic
    shipShape.move(speed);
    sf::Vector2f position = shipShape.getPosition();
    if (position.x > 800.0f) {
        position.x = 0.0f;
    } else if (position.x < 0.0f) {
        position.x = 800.0f;
    }

    if (position.y > 600.0f) {
        position.y = 0.0f;
    } else if (position.y < 0.0f) {
        position.y = 600.0f;
    }
    shipShape.setPosition(position);
}

void Ship::accelerate() {
    float changeX = std::cos(shipShape.getRotation() * 3.14159265 / 180.0f);
    float changeY = std::sin(shipShape.getRotation() * 3.14159265 / 180.0f);

    changeX *= 0.25f;
    changeY *= 0.25f;
    this->speed.x += changeX;
    this->speed.y += changeY;
}


void Ship::render(sf::RenderWindow& window) const {
    // Ship-specific rendering logic
    window.draw(shipShape);
}

void Ship::rotateLeft() {
    shipShape.rotate(-5.f);  // Adjust the rotation speed as needed
}

void Ship::rotateRight() {
    shipShape.rotate(5.f);  // Adjust the rotation speed as needed
}

sf::Vector2f Ship::getPosition() {
    return shipShape.getPosition();
}

float Ship::getRotation() {
    return shipShape.getRotation();
}

sf::FloatRect Ship::getBounds() const {
    return shipShape.getGlobalBounds();
}