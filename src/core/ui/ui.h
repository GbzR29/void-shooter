#pragma once
#include <SFML/Graphics.hpp>
#include "../system/resource_manager.h"

class UI {
    public:

        UI(ResourceManager& rm);

        void draw(sf::RenderWindow& window);
        void update(float dt);

    private:
       
        sf::Sprite healthbar_sprite;

        sf::Font default_font;
        sf::Text score_text;
};