#pragma once

# include "../entity.h"


class Enemy : Entity{

    public:
        void update(float dt) override;
        void draw(sf::RenderWindow& window) const override;
        void shoot(float dt);

    private:

};