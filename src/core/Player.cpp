#include "Player.h"
#include <iostream>

Player::Player() : sprite(tex){

    if (!tex.loadFromFile("assets/textures/player.png")) {
        std::cout << "Failed to load texture!\n";
    }

    sprite = sf::Sprite(tex);

    sprite.setScale({3, 3});
    sprite.setPosition({ (800 - 48) / 2, (600 - 48) / 2 });
}

void Player::update(float dt) {
    input(dt);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
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
