#include "projectile.h"

Projectile::Projectile(ResourceManager& rm) : projectile_sprite(rm.getTexture(TextureID::Laser)){

    projectile_sprite = sf::Sprite(rm.getTexture(TextureID::Laser));
    projectile_sprite.setScale({2, 3});
    projectile_sprite.setPosition(position);
}

void Projectile::draw(sf::RenderWindow& window) const{
    window.draw(projectile_sprite);    
}

void Projectile::activate(sf::Vector2f startPos, sf::Vector2f vel) {
    position = startPos;
    velocity = vel;
    projectile_sprite.setPosition(position);
    active = true;
}

void Projectile::update(float dt) {
    if (!active) return;

    position += velocity * dt;
    projectile_sprite.setPosition(position);

    if (position.y < -20) {
        active = false;
    }
}