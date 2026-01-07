#include "projectile.h"

Projectile::Projectile(ResourceManager& rm) : projectile_sprite(rm.getTexture(TextureID::Laser)){

    projectile_sprite = sf::Sprite(rm.getTexture(TextureID::Laser));
    projectile_sprite.setScale({2, 3});
    projectile_sprite.setPosition(position);
}

void Projectile::update(float dt){
    position += velocity * dt;
    projectile_sprite.setPosition(position);
}

void Projectile::draw(sf::RenderWindow& window) const{
    window.draw(projectile_sprite);    
}

void Projectile::set_Position(sf::Vector2f pos){
    position = pos;
}