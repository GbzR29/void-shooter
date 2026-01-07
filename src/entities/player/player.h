#pragma once

#include "../entity.h"
#include "../projectiles/projectile.h"

class GameContext;

#include <cmath>
#include <vector>

class Player : public Entity {
    private:
        GameContext* ctx;

        //thruster
        sf::Sprite thruster_sprite;
        sf::Vector2f thruster_position;

        const int thruster_total_frames = 4;
        float thruster_anim_time = 0;
        int thruster_actual_frame = 0;

        //player
        sf::Sprite player_sprite;
        const float player_speed = 300.f;

        int player_hp = 10;

        //shooting
        std::vector<Projectile> ammunition;
        int max_ammo = 20;     

    public:

        Player(GameContext& ctx);               
        virtual ~Player() = default;

        void update(float dt) override;
        void draw(sf::RenderWindow& window) const override;
        void input(float dt);
        void clampToScreen();
        void animation(float dt);
        void shoot(float dt);

        void handleEvent(const sf::Event& event, float dt);
};
