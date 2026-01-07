#include "player.h"

#include "../../core/game_context.h"

#include <iostream>

// initialization list for class member 'this->ctx'
Player::Player(GameContext& ctx) : player_sprite(ctx.resources->getTexture(TextureID::Player)), thruster_sprite(ctx.resources->getTexture(TextureID::Thruster)) 
{
    this->ctx = &ctx; // stores the address of the received context.

    player_sprite.setScale({3, 3});
    player_sprite.setPosition({ (1200 - 48) / 2, (900 - 48) / 2 });

    thruster_sprite.setScale({3, 3});
    thruster_sprite.setPosition(thruster_position);
    thruster_sprite.setTextureRect(sf::IntRect({0, 0}, {8, 8})); 

    ammunition.reserve(max_ammo);
    for(int i = 0; i < max_ammo; i++){
        // using ctx.resources (via pointer or reference)
        ammunition.emplace_back(*ctx.resources); 
    }
}

void Player::shoot(float dt) {
    for (auto& proj : ammunition) {
        if (!proj.isActive()) {
            
            ctx->audio->playSound(SoundID::LaserShot, SoundCategory::SFX);
            proj.activate({player_sprite.getPosition().x + 16, player_sprite.getPosition().y - 24}, {0.f, -1500.f});
            break;
        }
    }
}

void Player::update(float dt) {
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

void Player::draw(sf::RenderWindow& window) const {
    window.draw(player_sprite);
    window.draw(thruster_sprite);

    for (const auto& proj : ammunition) {
        proj.draw(window);
    }    
}

void Player::animation(float dt){
    float thruster_time_scale = 0.05;
    thruster_anim_time += dt * thruster_time_scale;

    const float thruster_fps = 120.f;
    thruster_actual_frame = static_cast<int>(thruster_anim_time * thruster_fps) % thruster_total_frames;

    thruster_sprite.setTextureRect(sf::IntRect({thruster_actual_frame * 8, 0}, {8, 8}));
}

void Player::handleEvent(const sf::Event& event, float dt)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Space)
        {
            shoot(dt);           
        }       
    }   
}

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

    // normalization
    if (direction.x != 0.f || direction.y != 0.f)
    {
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction /= length;
    }
    player_sprite.move(direction * player_speed * dt);
}

void Player::clampToScreen() {
    sf::Vector2f pos = player_sprite.getPosition();
    sf::FloatRect bounds = player_sprite.getGlobalBounds();

    if (pos.x < 0)
        pos.x = 0;

    if (pos.y < 0)
        pos.y = 0;

    if (pos.x + bounds.size.x > 1200)
        pos.x = 1200 - bounds.size.x;

    if (pos.y + bounds.size.y > 900)
        pos.y = 900 - bounds.size.y;

    player_sprite.setPosition(pos);
}
