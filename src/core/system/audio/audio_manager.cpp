#include "audio_manager.h"
#include "../resource/resource_manager.h"
#include "../resource/resource_ids.h"
#include <algorithm>

/**
 * Initializes the volume map with default values and reserves initial capacity for the pool.
 */
AudioManager::AudioManager(ResourceManager& rm) : rm(rm){
    volumes[SoundCategory::Music] = 10.f;
    volumes[SoundCategory::SFX]   = 40.f;
    volumes[SoundCategory::UI]    = 50.f;
    
    soundPool.reserve(32);
}

/**
 * Implementation of the Object Pool pattern for sounds. 
 * If a stopped sound instance is found, it is reused to save resources.
 */
void AudioManager::playSound(SoundID id, SoundCategory category) {
    for (auto& s : soundPool) {
        if (s.sound.getStatus() == sf::Sound::Status::Stopped) {
            s.sound.setBuffer(rm.getSound(id));
            s.sound.setVolume(volumes[category]);
            s.sound.play();
            s.category = category;
            return;
        }
    }

    soundPool.emplace_back(rm.getSound(id), category);
    SoundInstance& instance = soundPool.back();
    instance.sound.setVolume(volumes[category]);
    instance.sound.play();
}

void AudioManager::playMusic(MusicID id, bool loop) {
    if (currentMusic) {
        currentMusic->stop();
    }

    currentMusic = &rm.getMusic(id);
    currentMusic->setLooping(loop);
    currentMusic->setVolume(volumes[SoundCategory::Music]);
    currentMusic->play();
}

void AudioManager::stopMusic() {
    if (currentMusic) {
        currentMusic->stop();
        currentMusic = nullptr;
    }
}

/**
 * Removes sounds that have finished playing from the vector to keep the pool size manageable.
 * Uses the erase-remove idiom for efficiency.
 */
void AudioManager::update() {
    soundPool.erase(std::remove_if(soundPool.begin(), soundPool.end(), [](const SoundInstance& s)
    {
        return s.sound.getStatus() == sf::Sound::Status::Stopped;
    }), soundPool.end());
}