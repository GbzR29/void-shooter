#include "Player.h"
#include "../assets/textures/player_texture.h"
#include <iostream>

Player::Player() : sprite(tex){

    if (!tex.loadFromMemory(player_png, player_png_len)) {
        std::cout << "Failed to load texture!\n";
    }
    sprite = sf::Sprite(tex);

    sprite.setScale({3, 3});
    sprite.setPosition({ (800 - 48) / 2, (600 - 48) / 2 });
}

void Player::update(float dt) {

    input(dt);
    clampToScreen();    
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

void Player::animation(){

}

void Player::input(float dt) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        sprite.move({ 0, (-300 * dt) });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        sprite.move({ 0, (300 * dt) });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        sprite.move({ (-300 * dt), 0 });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        sprite.move({ (300 * dt), 0 });
    }
}

void Player::clampToScreen() {
    sf::Vector2f pos = sprite.getPosition();
    sf::FloatRect bounds = sprite.getGlobalBounds();

    if (pos.x < 0)
        pos.x = 0;

    if (pos.y < 0)
        pos.y = 0;

    if (pos.x + bounds.size.x > 800)
        pos.x = 800 - bounds.size.x;

    if (pos.y + bounds.size.y > 600)
        pos.y = 600 - bounds.size.y;

    sprite.setPosition(pos);
}
