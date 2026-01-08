#include "enemy.h"
#include <iostream>
#include "../../core/game_context.h"

/**
 * @details The constructor sets the initial spawn point and pre-configures 
 * the sprite scale and position. It fetches the enemy texture from the resource manager.
 */
Enemy::Enemy(GameContext& ctx) : enemy_sprite(ctx.resources->getTexture(TextureID::Enemy)){
    this->ctx = &ctx; 

    enemy_x_position = 400.f - 25.f; // Centering logic
    enemy_y_position = 100;
    amplitude = 50.0f;
    enemy_anim_time = 0;

    enemy_sprite.setScale({3, 3});
    enemy_sprite.setPosition({enemy_x_position, enemy_y_position});
}

/**
 * @details Movement Logic:
 * We use a parametric equation for a circle:
 * X = cx + r * cos(t)
 * Y = cy + r * sin(t)
 * where 't' is driven by enemy_anim_time. The multiplier (2.f) controls rotation speed.
 */

void Enemy::update(float dt){
    // Accumulate time to drive the math functions
    enemy_anim_time += dt;      

    // Calculate circular offsets
    float offsetX = std::cos(enemy_anim_time * 2.f) * amplitude;
    float offsetY = std::sin(enemy_anim_time * 2.f) * amplitude;

    // Apply the offset to the base position
    enemy_sprite.setPosition({
        enemy_x_position + offsetX,
        enemy_y_position + offsetY
    });
}

void Enemy::draw(sf::RenderWindow &window) const{
    window.draw(enemy_sprite);
}

/**
 * @todo Implement projectile spawning logic using the GameContext to add bullets to the world.
 */
void shoot(float dt){
    // Placeholder for shooting logic
}