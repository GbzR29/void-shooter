#include "enemy.h"
#include <iostream>
#include "../../core/game_context.h"

/**
 * @details The constructor sets the initial spawn point and pre-configures 
 * the sprite scale and position. It fetches the enemy texture from the resource manager.
 */
Enemy::Enemy(GameContext& ctx) : enemy_sprite(ctx.resources->getTexture(TextureID::Enemy)){
    this->ctx = &ctx; 

    position = {(400.f - 25.f), 100.f};

    amplitude = 85.0f;
    enemy_anim_time = 0;

    enemy_sprite.setScale({4, 4});

    enemy_sprite.setPosition(position);

    collision_box = enemy_sprite.getGlobalBounds();
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
    enemy_sprite.setPosition({position.x + offsetX, position.y + offsetY});
    
}

void Enemy::draw(sf::RenderWindow &window) const{
    window.draw(enemy_sprite);
}


void Enemy::set_enemyPosition(sf::Vector2f pos){
    position = pos;
}

/**
 * @todo Implement projectile spawning logic using the GameContext to add bullets to the world.
 */
void shoot(float dt){
    // Placeholder for shooting logic
}

void Enemy::takeDamage(int amount){
    health -= amount;
    if (health <= 0) {
        kill(); // Define alive = false
    }
}