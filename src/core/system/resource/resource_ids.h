#pragma once

/**
 * @enum TextureID
 * @brief Unique identifiers for all graphical textures in the game.
 */
enum class TextureID {
    Player,    ///< Main player starship texture
    Thruster,  ///< Engine exhaust particles/animation
    Enemy,     ///< Standard enemy unit texture
    Laser,     ///< Projectile/Laser bolt texture
    Explosion, ///< Explosion sprite sheet
    HealthBar, ///< UI Health bar background/fill
    EnergyBar, ///< UI Energy/Mana bar background/fill
    Planet,    ///< Background celestial bodies
    Icon       ///< General UI icons
};

/**
 * @enum FontID
 * @brief Identifiers for font assets used in UI and menus.
 */
enum class FontID {
    Main,      ///< Primary sans-serif font for readability
    Pixel      ///< Stylized pixel font for retro aesthetics
};

/**
 * @enum SoundID
 * @brief Identifiers for short audio clips (Sound Effects).
 */
enum class SoundID {
    LaserShot, ///< Sound played when firing weapons
    Explosion, ///< Sound played upon entity destruction
    Hit        ///< Sound played when an entity takes damage
};

/**
 * @enum MusicID
 * @brief Identifiers for long-playing background music tracks.
 */
enum class MusicID {
    Background, ///< Standard gameplay background loop
    Boss        ///< High-tension music for boss encounters
};

/**
 * @enum SoundCategory
 * @brief Used for grouping sounds to control volume and mixing.
 */
enum class SoundCategory {
    Music, ///< Background music tracks
    SFX,   ///< Gameplay sound effects
    UI     ///< User interface feedback sounds
};