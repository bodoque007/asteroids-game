#pragma once

#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(float x, float y, float rotation);

    void update();
    void render(sf::RenderWindow& window) const;
    bool isOffScreen() const;
    sf::FloatRect getBounds() const;
    bool operator==(const Projectile& other) const;

private:
    sf::RectangleShape projectileShape;
    sf::Vector2f speed;
    float projectileSpeed = 5.0f;
};