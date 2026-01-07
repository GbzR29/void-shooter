#include "enemy.h"
#include <iostream>

#include "../../core/game_context.h"

Enemy::Enemy(GameContext& ctx) : enemy_sprite(ctx.resources->getTexture(TextureID::Enemy)){
    this->ctx = &ctx; // stores the address of the received context.

    enemy_x_position = 400.f - 25.f;
    enemy_y_position = 100;
    amplitude = 50.0f;
    enemy_anim_time = 0;

    enemy_sprite.setScale({3, 3});
    enemy_sprite.setPosition({enemy_x_position, enemy_y_position});
}

void Enemy::update(float dt){
    //enemy animation
    enemy_anim_time += dt;      

    // circular offsets
    float offsetX = std::cos(enemy_anim_time * 2.f) * amplitude;
    float offsetY = std::sin(enemy_anim_time * 2.f) * amplitude;

    // final position
    enemy_sprite.setPosition({
        enemy_x_position + offsetX,
        enemy_y_position + offsetY
    });
}

void Enemy::draw(sf::RenderWindow &window) const{
    window.draw(enemy_sprite);
}

void shoot(float dt){

}