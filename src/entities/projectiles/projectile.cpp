#include "projectile.h"

/**
 * @details Initializes the sprite scale. Projectiles are usually smaller 
 * and stretched to give a sense of speed.
 */
Projectile::Projectile(ResourceManager& rm) : projectile_sprite(rm.getTexture(TextureID::Laser)) {
    projectile_sprite.setScale({2, 3});
}

/**
 * @details "Revives" the projectile. This avoids the cost of 'new' and 'delete'
 * during intense combat scenes.
 */
void Projectile::activate(sf::Vector2f startPos, sf::Vector2f vel) {
    position = startPos;
    velocity = vel;
    projectile_sprite.setPosition(position);
    active = true;
}

/**
 * @details The projectile automatically deactivates (returning to the pool)
 * when it moves off-screen (y < -20.f).
 */

void Projectile::update(float dt) {
    if (!active) return;

    // Movement calculation: P = P0 + V * dt
    position += velocity * dt;
    projectile_sprite.setPosition(position);

    // Despawn logic: Check if projectile left the top of the screen
    if (position.y < -20.f) {
        active = false;
    }
}

void Projectile::draw(sf::RenderWindow& window) const {
    if (!active) return;
    window.draw(projectile_sprite);
}