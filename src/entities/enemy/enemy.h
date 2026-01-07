#pragma once

# include "../entity.h"

#include <cmath>

class GameContext;

class Enemy : public Entity{

    public:

        Enemy(GameContext& ctx);
        void update(float dt) override;
        void draw(sf::RenderWindow& window) const override;
        void shoot(float dt);

    private:    
        
        GameContext* ctx;

        sf::Sprite enemy_sprite;

        float enemy_x_position;
        float enemy_y_position;

        float amplitude;

        float enemy_anim_time;

};