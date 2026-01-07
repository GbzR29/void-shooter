#pragma once

#include <unordered_map>
#include <vector>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

#include "../resource/resource_ids.h"

class ResourceManager;

class AudioManager {
public:
    AudioManager(ResourceManager& rm);

    void playMusic(MusicID id, bool loop = true);

    void stopMusic();

    void playSound(SoundID id, SoundCategory category);

    void setVolume(SoundCategory category, float volume);

    void update();

private:
    ResourceManager& rm;

    sf::Music* currentMusic = nullptr;

    struct SoundInstance {
        sf::Sound sound;
        SoundCategory category;

        SoundInstance(const sf::SoundBuffer& buffer, SoundCategory cat) : sound(buffer), category(cat) {}
    };

    std::vector<SoundInstance> soundPool;
    std::unordered_map<SoundCategory, float> volumes;
};
