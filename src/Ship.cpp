#include "Ship.hpp"
#include <cmath>

Ship::Ship(float x, float y) {
    speed = sf::Vector2f(0.f, 0.f);
    
    // Create a triangle shape
    shipShape.setPointCount(3);
    shipShape.setPoint(0, sf::Vector2f(0, -20));   // Top point (nose of the ship)
    shipShape.setPoint(1, sf::Vector2f(-10, 20));  // Bottom left
    shipShape.setPoint(2, sf::Vector2f(10, 20));   // Bottom right
    
    shipShape.setFillColor(sf::Color::White);
    shipShape.setPosition(400.0f, 300.0f);  // Set the initial position
    
    // Set the origin to the center of the triangle for proper rotation
    shipShape.setOrigin(0, 0);
}

void Ship::update() {
    speed.x *= FRICTION;
    speed.y *= FRICTION;
}

void Ship::move() {
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
    // Subtract 90 degrees to align with triangle's upward-pointing nose
    float angle = (shipShape.getRotation() - 90.0f) * 3.14159265 / 180.0f;
    float changeX = std::cos(angle);
    float changeY = std::sin(angle);

    changeX *= ACCELERATION;
    changeY *= ACCELERATION;
    
    this->speed.x += changeX;
    this->speed.y += changeY;
    
    // Limit maximum speed
    float currentSpeed = std::sqrt(speed.x * speed.x + speed.y * speed.y);
    if (currentSpeed > MAX_SPEED) {
        speed.x = (speed.x / currentSpeed) * MAX_SPEED;
        speed.y = (speed.y / currentSpeed) * MAX_SPEED;
    }
}


void Ship::render(sf::RenderWindow& window) const {
    window.draw(shipShape);
}

void Ship::rotateLeft() {
    shipShape.rotate(-ROTATION_SPEED);
}

void Ship::rotateRight() {
    shipShape.rotate(ROTATION_SPEED);
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