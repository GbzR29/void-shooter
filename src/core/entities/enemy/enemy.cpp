#include "enemy.h"
#include <iostream>

#include "../../../assets/textures/purp_enemy_texture.h"

Enemy::Enemy() : enemy_sprite(enemy_texture){

    if (!enemy_texture.loadFromMemory(purple_enemy_png, purple_enemy_png_len))
    {
        std::cout << "Failed to load purple_enemy texture" << std::endl;
    }

    enemy_x_position = 400.f - 25.f;
    enemy_y_position = 100;

    amplitude = 50.0f;

    enemy_anim_time = 0;

    enemy_sprite = sf::Sprite(enemy_texture);
    enemy_sprite.setScale({3, 3});
    enemy_sprite.setPosition({10, 100});
}

void Enemy::update(float dt){
    //enemy animation
    enemy_anim_time += dt;      

    //enemy_y_position <= 600 ? enemy_y_position += 100 * dt : enemy_y_position = -50;

    // offsets circulares
    float offsetX = std::cos(enemy_anim_time * 2.f) * amplitude;
    float offsetY = std::sin(enemy_anim_time * 2.f) * amplitude;

    // posição final
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