#include "audio-manager.h"

AudioManager::AudioManager(ResourceManager& rm) : rm(rm){
    playBackgroundMusic(true);
}

void AudioManager::playBackgroundMusic(bool loop){

    rm.getMusic(MusicID::Background).setLooping(loop);    
    rm.getMusic(MusicID::Background).setVolume(10.f);
    rm.getMusic(MusicID::Background).play();
}

void AudioManager::setVolume(float volume){
    rm.getMusic(MusicID::Background).setVolume(volume);
}

void AudioManager::stopMusic(){
    rm.getMusic(MusicID::Background).stop();
}
