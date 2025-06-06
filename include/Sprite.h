#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

/**
 * @class Sprite
 * @brief Base class for drawable game objects with position, velocity, and color.
 * 
 * Provides common properties and methods for 2D sprites,
 * including position, velocity, color, and basic movement handling.
 */
class Sprite {
protected:
    float x, y, initial_x, initial_y;           ///< Current and initial position of the sprite on the screen (pixels).
    float vel_x, vel_y; ///< Current velocity in x and y directions (pixels per update).
    Color color;        ///< Color used to draw the sprite.
    bool frozen;

public:
    /**
     * @brief Construct a new Sprite.
     * 
     * @param x Initial x-position.
     * @param y Initial y-position.
     * @param color Color used for rendering the sprite.
     */
    Sprite(float x, float y, Color color) : x(x), y(y), initial_x(x), initial_y(y), color(color), vel_x(0), vel_y(0), frozen(false) {}

    /**
     * @brief Get vel-x of sprite
     */
    float get_vel_x() { return this->vel_x; }

    /**
     * @brief Get vel-y of sprite
     */
    float get_vel_y() { return this->vel_y; }

    /**
     * @brief Set horizontal velocity.
     * @param vel_x New velocity along the x-axis.
     */
    void set_vel_x(float vel_x) { this->vel_x = vel_x; }

    /**
     * @brief Set vertical velocity.
     * @param vel_y New velocity along the y-axis.
     */
    void set_vel_y(float vel_y) { this->vel_y = vel_y; }

    /**
     * @brief Update x-position by adding horizontal velocity.
     * 
     * Can be overridden for custom behavior.
     */
    virtual void apply_vel_x() { x += vel_x; }

    /**
     * @brief Update y-position by adding vertical velocity.
     * 
     * Can be overridden for custom behavior.
     */
    virtual void apply_vel_y() { y += vel_y; }

    /**
     * @brief Get x-coord of sprite
     */
    float get_x() { return x; }

    /**
     * @brief Get y-coord of sprite
     */
    float get_y() { return y; }

    /**
     * @brief set x-coord of sprite
     */
    void set_x(float x) { this->x = x; }

    /**
     * @brief set y-coord of sprite
     */
    void set_y(float y) { this->y = y; }

    /**
     * @brief Draw the sprite to the screen.
     * 
     * Must be implemented by derived classes.
     */
    virtual void Draw() const = 0;

    /**
     * @brief Update the sprite's state.
     * 
     * By default, moves the sprite according to its velocity.
     * Can be overridden for more complex update logic.
     */
    virtual void Update() {
        if (frozen) {
            return;
        }
        apply_vel_x();
        apply_vel_y();
    }

    /**
     * @brief Handle input for the sprite.
     * 
     * Empty default implementation; override if input handling is needed.
     */
    virtual void HandleInput() {};

    /**
     * @brief Reset sprite
     */
    virtual void Reset() {
        x = initial_x;
        y = initial_y;
    };

    /**
     * @brief Freeze sprites making the unrenderable
     */
    virtual void Freeze(bool isFrozen) {
        frozen = isFrozen;
    }
};

#endif
