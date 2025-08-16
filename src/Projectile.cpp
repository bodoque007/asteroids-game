#include "Projectile.hpp"
#include <cmath>


Projectile::Projectile(float x, float y, float rotation) {
    projectileShape.setSize(sf::Vector2f(10.0f, 10.0f));
    
    // Adjust angle to match ship's forward direction (subtract 90 degrees)
    float angle = (rotation - 90.0f) * 3.14159265 / 180.0f;
    float offset = 1.0f;
    
    projectileShape.setPosition(x + offset * std::cos(angle),
                      y + offset * std::sin(angle));

    projectileShape.setFillColor(sf::Color::Red);
    projectileShape.setRotation(rotation);

    float changeX = std::cos(angle);
    float changeY = std::sin(angle);

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
    const float epsilon = 0.00001f;
    return std::abs(this->projectileShape.getPosition().x - other.projectileShape.getPosition().x) < epsilon &&
           std::abs(this->projectileShape.getPosition().y - other.projectileShape.getPosition().y) < epsilon;
}