#pragma once
#include <SFML/Graphics.hpp>

#include "../core/game_context.h"

class Planet{

    private:

        GameContext* ctx;

        sf::Sprite earth_sprite;

        float earth_anim_time = 0.f;    
        const int earth_total_frames = 163;
        int earth_actual_frame = 0;

    public:
        Planet(GameContext& ctx);
        void update(float dt);
        void draw(sf::RenderWindow& window);
};