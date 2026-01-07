#pragma once
#include "../entity.h"

#include <iostream>

class Projectile : Entity{

    public:

        Projectile(ResourceManager& rm);

        void update(float dt) override;
        void draw(sf::RenderWindow& window) const override;
        void set_Position(sf::Vector2f position);

    private:

        sf::Vector2f position;
        sf::Vector2f velocity;

        sf::Sprite projectile_sprite;

};