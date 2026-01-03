#include "Player.h"
#include "../assets/textures/player_texture.h"
#include "../assets/sprites/thruster/thruster_spritesheet.h"
#include <iostream>

Player::Player() : player_sprite(player_texture), thruster_sprite(thruster_texture){

    if (!player_texture.loadFromMemory(player_png, player_png_len)) {
        std::cout << "Failed to load player texture!\n";
    }

    player_sprite = sf::Sprite(player_texture);
    player_sprite.setScale({3, 3});
    player_sprite.setPosition({ (800 - 48) / 2, (600 - 48) / 2 });

    if (!thruster_texture.loadFromMemory(thruster_png, thruster_png_len)) {
        std::cout << "Failed to load thruster texture!\n";
    }

    thruster_x_position = player_sprite.getPosition().x + 12;
    thruster_y_position = player_sprite.getPosition().y + 45;

    thruster_sprite = sf::Sprite(thruster_texture);
    thruster_sprite.setScale({3, 3});
    thruster_sprite.setPosition({thruster_x_position, thruster_y_position});
    thruster_sprite.setTextureRect(sf::IntRect({0, 0}, {8, 8}));
}

void Player::update(float dt) {

    thruster_x_position = player_sprite.getPosition().x + 12;
    thruster_y_position = player_sprite.getPosition().y + 45;
    thruster_sprite.setPosition({thruster_x_position, thruster_y_position});

    animation(dt);

    input(dt);
    clampToScreen();    
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(player_sprite);
    window.draw(thruster_sprite);
}

void Player::animation(float dt){
    float thruster_time_scale = 0.05;
    thruster_anim_time += dt * thruster_time_scale;

    const float thruster_fps = 120.f;
    thruster_actual_frame = static_cast<int>(thruster_anim_time * thruster_fps) % thruster_total_frames;

    thruster_sprite.setTextureRect(sf::IntRect({thruster_actual_frame * 8, 0}, {8, 8}));
}

void Player::input(float dt) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        player_sprite.move({ 0, (-300 * dt) });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        player_sprite.move({ 0, (300 * dt) });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        player_sprite.move({ (-300 * dt), 0 });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        player_sprite.move({ (300 * dt), 0 });
    }
}

void Player::clampToScreen() {
    sf::Vector2f pos = player_sprite.getPosition();
    sf::FloatRect bounds = player_sprite.getGlobalBounds();

    if (pos.x < 0)
        pos.x = 0;

    if (pos.y < 0)
        pos.y = 0;

    if (pos.x + bounds.size.x > 800)
        pos.x = 800 - bounds.size.x;

    if (pos.y + bounds.size.y > 600)
        pos.y = 600 - bounds.size.y;

    player_sprite.setPosition(pos);
}
