#pragma once
#include <SFML/Graphics.hpp>
#include "../core/system/resource/resource_manager.h"
#include "../core/game_context.h"

class UI {

    private:

        GameContext* ctx;
       
        sf::Sprite healthbar_sprite;

        sf::Font default_font;
        sf::Text score_text;

    public:

        UI(GameContext& ctx);

        void draw(sf::RenderWindow& window);
        void update(float dt);
};