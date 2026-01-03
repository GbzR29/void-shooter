#pragma once

#include "../headers/Entity.h"

class Player : public Entity {
public:
    Player();               
    virtual ~Player() = default;

    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;
    void input(float dt);
    void clampToScreen();
    void animation();

private:
    sf::Vector2f velocity{ 0.f, 0.f };

    sf::Texture throwers;
    //sf::Sprite throwers;

    sf::Texture tex;
    sf::Sprite sprite;
    float speed = 200.f;
    int hp = 10;
};
