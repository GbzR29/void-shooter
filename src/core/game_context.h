#pragma once

#include "system/audio/audio_manager.h"
#include "system/resource/resource_manager.h"
#include "system/window/window_manager.h"

/**
 * @struct GameContext
 * @brief A container struct that holds pointers to core engine systems.
 * * This context is passed around to various game states and entities, allowing 
 * easy access to centralized services like rendering, audio, and resource management
 * without using global variables (Singletons).
 */
struct GameContext {
    /** @brief Pointer to the window and rendering manager. */
    WindowManager* window = nullptr;

    /** @brief Pointer to the resource manager for loading/retrieving assets. */
    ResourceManager* resources = nullptr;

    /** @brief Pointer to the audio manager for music and SFX control. */
    AudioManager* audio = nullptr;
};