#include "Game.hpp"
#include <iostream>
using namespace std;

static const int WIDTH = 800;
static const int HEIGHT = 600;

Game::Game() : ship(WIDTH/2, HEIGHT/2), projectilesToRemove(), asteroidsToRemove(), gameOver(false) {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Asteroids-ish");
    window.setFramerateLimit(60);
    // Initialize the asteroids vector with a certain number of asteroids
    for (int i = 0; i < 9; ++i) {
        float x = static_cast<float>(rand() % (window.getSize().x / 3));
        float y = static_cast<float>(rand() % (window.getSize().y / 3));

        Asteroid asteroid(x, y, 30.0f, 6);
        asteroids.push_back(asteroid);
    }
}

void Game::run() {
    while (window.isOpen()) {
        if (gameOver) {
            cout<<"Game over!"<<endl;
            break;
        }
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle keyboard events for one-time actions
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::L) {
                    // Create a projectile when the L key is pressed
                    cout<<"Creating projectile"<<endl;
                    Projectile projectile(ship.getPosition().x, ship.getPosition().y, ship.getRotation());
                    projectiles.push_back(projectile);
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            ship.accelerate();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ship.rotateLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ship.rotateRight();
        }
}

void Game::update() {
    ship.update();
    ship.move();

    projectiles.erase(
        std::remove_if(
            projectiles.begin(),
            projectiles.end(),
            [](const Projectile& projectile) { return projectile.isOffScreen(); }),
        projectiles.end()
    );

    for (auto& asteroid : asteroids) {
        for (const auto& projectile : projectiles) {
            if (asteroidProjectileCollision(asteroid, projectile)) {
                projectilesToRemove.push_back(projectile);
                asteroidsToRemove.push_back(asteroid);
                if (!(asteroid.getRadius() < 20.f)) {
                    float offsetX = static_cast<float>(std::rand() % 30 - 15);  // Random offset between -15 and 15
                    float offsetY = static_cast<float>(std::rand() % 30 - 15);

                    Asteroid newAsteroid1(asteroid.getPosition().x + offsetX, asteroid.getPosition().y + offsetY, asteroid.getRadius() / 2, 6);
                    // New random offset for the other half asteroid.
                    offsetX = static_cast<float>(std::rand() % 30 - 15);
                    offsetY = static_cast<float>(std::rand() % 30 - 15);
                    Asteroid newAsteroid2(asteroid.getPosition().x + offsetX, asteroid.getPosition().y + offsetY, asteroid.getRadius() / 2, 6);

                    newAsteroids.push_back(newAsteroid1);
                    newAsteroids.push_back(newAsteroid2);
                }
            }
        }
    }

    projectiles.erase(
        std::remove_if(
            projectiles.begin(),
            projectiles.end(),
            [this](const Projectile& projectile) { return std::find(projectilesToRemove.begin(), projectilesToRemove.end(), projectile) != projectilesToRemove.end(); }),
        projectiles.end()
    );

    asteroids.erase(
        std::remove_if(
            asteroids.begin(),
            asteroids.end(),
            [this](const Asteroid& asteroid) { return std::find(asteroidsToRemove.begin(), asteroidsToRemove.end(), asteroid) != asteroidsToRemove.end(); }),
        asteroids.end()
    );

    for(auto& projectile : projectiles) {
        projectile.update();
    }

    for (auto& asteroid : asteroids) {
        asteroid.update();
        // Check collision with ship
        if (ship.getBounds().intersects(asteroid.getBounds())) {
            std::cout << "Ship collided with asteroid!" << std::endl;
            gameOver = true;
        }
    }

    for(auto& asteroid : newAsteroids) {
        asteroids.push_back(asteroid);
    }
    // Optimization purposes, clear vectors for next iteration, as they were already removed from the asteroids and projectiles vectors.
    newAsteroids.clear();
    asteroidsToRemove.clear();
    projectilesToRemove.clear();
}

void Game::render() {
    window.clear();
    for(int i = 0; i <projectiles.size(); i++) {
        projectiles[i].render(window);
    }

    for(int i = 0; i < asteroids.size(); i++) {
        asteroids[i].render(window);
    }

    ship.render(window);
    window.display();   
}

bool Game::asteroidProjectileCollision(const Asteroid& asteroid, const Projectile& projectile) {
    return asteroid.getBounds().intersects(projectile.getBounds());
}