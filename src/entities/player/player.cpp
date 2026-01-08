#include "player.h"
#include "../../core/game_context.h"
#include <iostream>

/**
 * @details Initializes sprites and pre-fills the 'ammunition' vector.
 * Using Object Pooling here is a best practice to prevent frame drops caused by 
 * dynamic memory allocation during gameplay.
 */
Player::Player(GameContext& ctx) 
    : player_sprite(ctx.resources->getTexture(TextureID::Player)), 
      thruster_sprite(ctx.resources->getTexture(TextureID::Thruster)) 
{
    this->ctx = &ctx;

    player_sprite.setScale({3, 3});
    // Center the player on a 1200x900 screen
    player_sprite.setPosition({ (1200 - 48) / 2, (900 - 48) / 2 });

    thruster_sprite.setScale({3, 3});
    thruster_sprite.setTextureRect(sf::IntRect({0, 0}, {8, 8})); 

    ammunition.reserve(max_ammo);
    for(int i = 0; i < max_ammo; i++){
        ammunition.emplace_back(*ctx.resources); 
    }
}

/**
 * @details Iterates through the pool to find the first 'dead' projectile and 'revives' it.
 */
void Player::shoot(float dt) {
    for (auto& proj : ammunition) {
        if (!proj.isActive()) {
            ctx->audio->playSound(SoundID::LaserShot, SoundCategory::SFX);
            // Offset projectile to appear from the front of the ship
            proj.activate({player_sprite.getPosition().x + 16, player_sprite.getPosition().y - 24}, {0.f, -1500.f});
            break;
        }
    }
}

void Player::update(float dt) {
    // Sync thruster position with ship body
    thruster_position = player_sprite.getPosition();
    thruster_position.x += 12;
    thruster_position.y += 45;
    thruster_sprite.setPosition(thruster_position);

    for (auto& proj : ammunition) {
        proj.update(dt);
    }

    animation(dt);
    input(dt);
    clampToScreen();
}

/**
 * @brief Renders the player, thrusters, and all active projectiles.
 */
void Player::draw(sf::RenderWindow& window) const {
    window.draw(player_sprite);
    window.draw(thruster_sprite);

    for (const auto& proj : ammunition) {
        proj.draw(window);
    }    
}

/**
 * @brief Handles discrete engine events (like one-tap key presses).
 */
void Player::handleEvent(const sf::Event& event, float dt) {
    // Verificando se a tecla Espaço foi pressionada (SFML 3.0 style)
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::Space) {
            shoot(dt);           
        }       
    }   
}

/**
 * @details Sprite Sheet logic:
 * Moves the IntRect across the texture based on time to create a flicker effect.
 */

void Player::animation(float dt){
    float thruster_time_scale = 0.05;
    thruster_anim_time += dt * thruster_time_scale;

    const float thruster_fps = 120.f;
    thruster_actual_frame = static_cast<int>(thruster_anim_time * thruster_fps) % thruster_total_frames;

    // Shift the source rectangle by 8 pixels (frame width) per frame
    thruster_sprite.setTextureRect(sf::IntRect({thruster_actual_frame * 8, 0}, {8, 8}));
}

/**
 * @details Normalization:
 * Ensures diagonal movement is not faster than orthogonal movement.
 * Formula: v_normalized = v / |v|
 */

void Player::input(float dt) {       
    sf::Vector2f direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        direction.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        direction.x += 1.f;

    if (direction.x != 0.f || direction.y != 0.f)
    {
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;
    }
    player_sprite.move(direction * player_speed * dt);
}

/**
 * @details Window Clamping:
 * Hardcoded boundaries (1200x900). 
 * @todo Replace magic numbers with variables from WindowManager.
 */
void Player::clampToScreen() {
    sf::Vector2f pos = player_sprite.getPosition();
    sf::FloatRect bounds = player_sprite.getGlobalBounds();

    if (pos.x < 0) pos.x = 0;
    if (pos.y < 0) pos.y = 0;
    if (pos.x + bounds.size.x > 1200) pos.x = 1200 - bounds.size.x;
    if (pos.y + bounds.size.y > 900) pos.y = 900 - bounds.size.y;

    player_sprite.setPosition(pos);
}