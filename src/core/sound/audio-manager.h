#pragma once

#include <SFML/Audio.hpp>
#include "../system/resource_manager.h"
#include <iostream>

class AudioManager {
public:
    
    AudioManager(ResourceManager& rm);

    void playBackgroundMusic(bool loop);
    void setVolume(float volume);
    void stopMusic();

private:
    ResourceManager& rm;
};
