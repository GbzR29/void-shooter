#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <optional>

class AudioManager{

    public:
        bool playBackgroundMusic(bool loop);
        void setVolume(float volume);
        void stopMusic();

    private:
        sf::Music music;
};