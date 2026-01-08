#include "ui.h"
#include <iostream>

/**
 * @details Initializes UI elements with fixed positions and default styling.
 * Uses the Resource Manager to fetch the Pixel font and HealthBar texture.
 */
UI::UI(GameContext &ctx) 
    : healthbar_sprite(ctx.resources->getTexture(TextureID::HealthBar)), 
      score_text(ctx.resources->getFont(FontID::Pixel)) 
{
    // Configure Score Text
    score_text.setString("Score: 0000"); // Initial placeholder
    score_text.setCharacterSize(32);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition({950, 5});

    // Configure Health Bar
    // Note: Re-initializing or setting texture rect for initial state
    healthbar_sprite.setScale({2, 2});
    healthbar_sprite.setPosition({10, 10});
    
    /**
     * @note TextureRect({0, 0}, {100, 16}) represents 100% health.
     * To decrease health, the width (100) should be multiplied by the health percentage.
     */
    healthbar_sprite.setTextureRect(sf::IntRect({0, 0}, {100, 16}));
}

void UI::draw(sf::RenderWindow &window){
    window.draw(healthbar_sprite);
    window.draw(score_text);
}

/**
 * @todo Implement dynamic updates for score and health bar scaling.
 */
void UI::update(float dt) {
    // Logic to sync with player stats will go here
}