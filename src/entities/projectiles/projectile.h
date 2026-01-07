#pragma once
#include "../entity.h"

#include <iostream>

class Projectile : public Entity {

    private:
        sf::Vector2f position{0.f, 0.f};
        sf::Vector2f velocity{0.f, 0.f};

        bool active = false;

        sf::Sprite projectile_sprite;

    public:
        Projectile(ResourceManager& rm);

        void activate(sf::Vector2f startPos, sf::Vector2f vel);
        bool isActive() const { return active; }

        void update(float dt) override;
        void draw(sf::RenderWindow& window) const override;
};
