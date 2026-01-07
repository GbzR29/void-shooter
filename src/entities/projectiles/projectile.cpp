#include "projectile.h"

Projectile::Projectile(ResourceManager& rm) : projectile_sprite(rm.getTexture(TextureID::Laser)) {
    projectile_sprite.setScale({2, 3});
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

    // returns the projectile to the pool if the y-position is less than 20.
    if (position.y < -20.f) {
        active = false;
    }
}

void Projectile::draw(sf::RenderWindow& window) const {
    if (!active) return;
    window.draw(projectile_sprite);
}
