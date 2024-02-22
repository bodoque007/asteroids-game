#include "Asteroid.hpp"


Asteroid::Asteroid(float x, float y, float radius, int numSides) {
    shape.setRadius(radius);
    shape.setPosition(x, y);
    shape.setPointCount(numSides);
    shape.setFillColor(sf::Color::Yellow);

    float speed = 0.8f;
    velocity.x = speed;
    velocity.y = speed;
    rotationalMovement = 0.5f - static_cast<float>(rand()) / (RAND_MAX / 1.0f);
}


void Asteroid::update() {
    // Update asteroid position based on velocity
    shape.move(velocity);

    // Wrap around the screen (teleport to the opposite side)
    sf::Vector2f position = shape.getPosition();
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
    shape.setPosition(position);
    shape.rotate(rotationalMovement);
}

void Asteroid::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Asteroid::getBounds() const {
    return shape.getGlobalBounds();
}
bool Asteroid::operator==(const Asteroid& other) const {
    const float epsilon = 0.00001f;
    return std::abs(this->shape.getPosition().x - other.shape.getPosition().x) < epsilon &&
           std::abs(this->shape.getPosition().y - other.shape.getPosition().y) < epsilon;
}

float Asteroid::getRadius() {
    return this->shape.getRadius();
}

sf::Vector2f Asteroid::getPosition() {
    return this->shape.getPosition();
}