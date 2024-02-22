#include "Projectile.hpp"
#include <cmath>


Projectile::Projectile(float x, float y, float rotation) {
    projectileShape.setSize(sf::Vector2f(10.0f, 10.0f));
    float offset = 1.0f; // Adjust this value as needed
    projectileShape.setPosition(x + offset * std::cos(rotation * 3.14159265 / 180.0f),
                      y + offset * std::sin(rotation * 3.14159265 / 180.0f));

    projectileShape.setFillColor(sf::Color::Red);
    projectileShape.setRotation(rotation);

    // Calculate the initial speed based on the rotation
    float changeX = std::cos(rotation * 3.14159265 / 180.0f);
    float changeY = std::sin(rotation * 3.14159265 / 180.0f);

    speed.x = projectileSpeed * changeX;
    speed.y = projectileSpeed * changeY;
}

void Projectile::render(sf::RenderWindow& window) const {
    window.draw(projectileShape);
}


void Projectile::update() {
    projectileShape.move(speed);
}

bool Projectile::isOffScreen() const {
    sf::Vector2f position = projectileShape.getPosition();
    if (position.x < 0 || position.x > 800 ||   position.y < 0 || position.y > 600) {
        return true;
    }
    return false;
}

sf::FloatRect Projectile::getBounds() const {
    return projectileShape.getGlobalBounds();
}

bool Projectile::operator==(const Projectile& other) const {
    // Adjust the epsilon value based on your precision requirements
    const float epsilon = 0.00001f;
    return std::abs(this->projectileShape.getPosition().x - other.projectileShape.getPosition().x) < epsilon &&
           std::abs(this->projectileShape.getPosition().y - other.projectileShape.getPosition().y) < epsilon;
}