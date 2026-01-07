#pragma once
#include <SFML/Graphics.hpp>
#include "../system/resource_manager.h"

class Planet{

    private:
        sf::Sprite earth_sprite;

        float earth_anim_time = 0.f;    
        const int earth_total_frames = 163;
        int earth_actual_frame = 0;

    public:
        Planet(ResourceManager& rm);
        void update(float dt);
        void draw(sf::RenderWindow& window);
};