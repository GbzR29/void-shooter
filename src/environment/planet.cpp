#include "planet.h"
#include "../core/system/resource/resource_manager.h"
#include <iostream>

/**
 * @details Initializes the planet sprite, scale, and color.
 * The color is slightly darkened (100, 100, 100) to ensure the planet 
 * stays in the background and doesn't visually distract from the gameplay.
 */
Planet::Planet(GameContext& ctx) : earth_sprite(ctx.resources->getTexture(TextureID::Planet)){
    
    this->ctx = &ctx;

    // Initial frame setup (100x100 pixels per frame)
    earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame, 0}, {100, 100}));

    // Scale Factor: multiply the original size by X
    float scaleFactor = 15.f;

    // Planet size within the game
    float earthSize = earth_sprite.getGlobalBounds().size.x * scaleFactor;

    // Scaling the 100x100 sprite to a larger size for the background
    earth_sprite.setScale({scaleFactor, scaleFactor});
    
    sf::Vector2f earth_position = static_cast<sf::Vector2f>(ctx.window->getSize());

    earth_sprite.setPosition({(earth_position.x - earthSize) / 2, (earth_position.y + 250) / 2});
    
    // Applying a dark tint to enhance the "background" feel
    earth_sprite.setColor(sf::Color(100, 100, 100, 255));
}

/**
 * @details Frame-by-Frame Animation:
 * The function calculates the current frame by multiplying the accumulated time 
 * by a target FPS. The modulo operator (%) ensures the animation loops back 
 * to the first frame after frame 162.
 */

void Planet::update(float dt){
    // Slowing down the animation progress
    float earth_time_scale = 0.05;
    earth_anim_time += dt * earth_time_scale;

    const float earth_fps = 120.f;
    earth_actual_frame = static_cast<int>(earth_anim_time * earth_fps) % earth_total_frames;

    // Moving the texture rectangle horizontally across the sprite sheet
    earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame * 100, 0}, {100, 100}));
}

void Planet::draw(sf::RenderWindow& window){
    window.draw(earth_sprite);
}