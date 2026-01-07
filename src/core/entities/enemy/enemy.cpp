#include "enemy.h"
#include <iostream>


Enemy::Enemy(ResourceManager& rm) : enemy_sprite(rm.getTexture(TextureID::Enemy)){

    enemy_x_position = 400.f - 25.f;
    enemy_y_position = 100;

    amplitude = 50.0f;
    enemy_anim_time = 0;

    enemy_sprite = sf::Sprite(rm.getTexture(TextureID::Enemy));
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