#include "stars.h"

/**
 * @details Initializes the starfield by storing the context and triggering 
 * the initial generation of stars.
 */
Stars::Stars(GameContext& ctx, std::size_t count){
    this->ctx = &ctx;
    create_stars(count);
}

void Stars::draw(sf::RenderWindow& window) {
    for (const auto& star : stars) {
        window.draw(star);   
    }
}

/**
 * @details Movement Logic:
 * Stars move downward at a constant rate. When a star's Y coordinate 
 * exceeds the window height (900.f), it "wraps around" to Y=0 with a 
 * new randomized X position to avoid repeating patterns.
 */

void Stars::update(float delta_time) {
    for (auto& star : stars) {
        // Linear movement: P = P0 + (Speed * dt)
        star.move({0.f, 100.f * delta_time}); 

        // Boundary check for infinite scrolling
        if (star.getPosition().y > 900.f) {
            float newX = distribX(gen);
            star.setPosition({newX, 0.f});
        }
    }
}

/**
 * @details Optimization: 
 * Uses 'vector::reserve' to prevent multiple reallocations during initialization.
 * Each star is given a random scale to create a sense of depth (smaller/larger stars).
 */
void Stars::create_stars(std::size_t count) {
    stars.reserve(count);

    for (std::size_t i = 0; i < count; ++i) {
        // Base shape is a tiny circle
        sf::CircleShape star{ 0.5f };

        // Randomizing scale for variety
        float randomScale = std::uniform_real_distribution<float>(0.5f, 2.0f)(gen);
        star.setScale({ randomScale, randomScale });
        
        star.setFillColor(sf::Color::White);
        
        // Random initial placement across the whole screen
        star.setPosition({distribX(gen), distribY(gen)});

        stars.push_back(star);
    }
}