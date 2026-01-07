#include "player.h"

#include <iostream>

Player::Player(ResourceManager& rm) : player_sprite(rm.getTexture(TextureID::Player)), thruster_sprite(rm.getTexture(TextureID::Thruster)){
    player_sprite = sf::Sprite(rm.getTexture(TextureID::Player));
    thruster_sprite = sf::Sprite(rm.getTexture(TextureID::Thruster));

    player_sprite.setScale({3, 3});
    player_sprite.setPosition({ (800 - 48) / 2, (600 - 48) / 2 });
        
    thruster_sprite.setScale({3, 3});
    thruster_sprite.setPosition(thruster_position);
    thruster_sprite.setTextureRect(sf::IntRect({0, 0}, {8, 8}));

    /*ammunition.reserve(max_ammo);
    for(int i = 0; i < max_ammo; i++){
        ammunition.emplace_back();
    }*/

    //O(1)
}

void Player::update(float dt) {
    thruster_position = player_sprite.getPosition();
    thruster_position.x += 12;
    thruster_position.y += 45;

    thruster_sprite.setPosition(thruster_position);

    animation(dt);
    input(dt);
    clampToScreen();
    //O(1)
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(player_sprite);
    window.draw(thruster_sprite);

    //O(1)
}

void Player::animation(float dt){
    float thruster_time_scale = 0.05;
    thruster_anim_time += dt * thruster_time_scale;

    const float thruster_fps = 120.f;
    thruster_actual_frame = static_cast<int>(thruster_anim_time * thruster_fps) % thruster_total_frames;

    thruster_sprite.setTextureRect(sf::IntRect({thruster_actual_frame * 8, 0}, {8, 8}));
    //O(1)
}

void Player::shoot(float dt){
    std::cout << "Shooted!!" << std::endl;
}

void Player::handleEvent(const sf::Event& event, float dt)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Space)
        {
            shoot(dt);
            //O(1)
        }
        //O(1)
    }

    //O(1)
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
        //O(1)
    }
    player_sprite.move(direction * player_speed * dt);

    //O(1)
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

    //O(1)
}
