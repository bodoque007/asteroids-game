// Game.hpp

#pragma once

#include <SFML/Graphics.hpp>
#include "Ship.hpp"
#include "Projectile.hpp"
#include "Asteroid.hpp"
#include "Projectile.hpp"

class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update();
    void render();
    bool asteroidProjectileCollision(const Asteroid& asteroid, const Projectile& projectile);

private:
    sf::RenderWindow window;
    Ship ship;
    std::vector<Projectile> projectiles;
    std::vector<Asteroid> asteroids;  // Vector to store multiple asteroids
    std::vector<Projectile> projectilesToRemove;
    std::vector<Asteroid> asteroidsToRemove;
    bool gameOver;
};
