#pragma once

#include "../entity.h"
#include <cmath>


class Player : public Entity {
public:
    Player();               
    virtual ~Player() = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    void input(float dt);
    void clampToScreen();
    void animation(float dt);
    void shoot(float dt);

    void handleEvent(const sf::Event& event, float dt);

private:
    sf::Vector2f velocity{ 0.f, 0.f };

    sf::Texture thruster_texture;
    sf::Sprite thruster_sprite;

    float thruster_x_position;
    float thruster_y_position;

    const int thruster_total_frames = 4;
    float thruster_anim_time = 0;
    int thruster_actual_frame = 0;

    sf::Texture player_texture;
    sf::Sprite player_sprite;
    float speed = 200.f;
    int hp = 10;
};
