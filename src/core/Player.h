#pragma once

#include "Entity.h"

class Player : public Entity {
public:
    Player();               
    virtual ~Player() = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    void input(float dt);
    void clampToScreen();

private:
    sf::Vector2f velocity{ 0.f, 0.f };
    sf::Texture tex;
    sf::Sprite sprite;
    float speed = 200.f;
    int hp = 10;
};
