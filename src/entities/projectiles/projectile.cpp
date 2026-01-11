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

// No Projectile.cpp
void Projectile::update(float dt) {
    if (!active) return;

    position += velocity * dt;
    projectile_sprite.setPosition(position);
    
    // BOX UPDATE: Gets the global sprite boundaries
    collision_box = projectile_sprite.getGlobalBounds();

    if (position.y < -20.f) {
        active = false;
    }
}

void Projectile::draw(sf::RenderWindow& window) const {
    if (!active) return;
    window.draw(projectile_sprite);
}

void Projectile::onCollision(Entity& entity) {
    // apply the damage to the entity that was passed on.
    entity.takeDamage(10); 
    
    // deactivate the projectile (it disappears upon impact).
    this->active = false; 
    
    std::cout << "entity suffered damage." << std::endl;
}