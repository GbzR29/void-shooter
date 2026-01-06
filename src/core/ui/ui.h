#pragma once
#include <SFML/Graphics.hpp>

class UI {
    public:

        UI();

        void draw(sf::RenderWindow &window);
        void update(float dt);

    private:
        sf::Texture healthbar_texture;
        sf::Sprite healthbar_sprite;

        sf::Font default_font;
        sf::Text score_text;
};