#ifndef PADDLE_H
#define PADDLE_H

#include "Sprite.h"

/**
 * @class Paddle
 * @brief Represents a paddle controlled by the player with position, size, speed, and sprint capability.
 * 
 * Inherits from Sprite and adds width, height, movement speed,
 * and a sprint modifier to control paddle velocity.
 */
class Paddle : public Sprite {
private:
    int width;               ///< Width of the paddle in pixels.
    int height;              ///< Height of the paddle in pixels.
    float speed = 5.0f;      ///< Base movement speed of the paddle.
    float sprint_modifier = 1.5f; ///< Multiplier applied to speed when sprinting.

public:
    /**
     * @brief Constructs a new Paddle object.
     * 
     * @param x Initial x-position of the paddle.
     * @param y Initial y-position of the paddle.
     * @param color Color of the paddle.
     * @param width Width of the paddle in pixels.
     * @param height Height of the paddle in pixels.
     */
    Paddle(int x, int y, Color color, int width, int height);

    /**
     * @brief Draws the paddle on the screen.
     * 
     * Overrides the pure virtual Draw method in Sprite.
     */
    void Draw() const override;

    /**
     * @brief Handles player input to control paddle movement and sprinting.
     * 
     * Overrides the default HandleInput from Sprite.
     */
    void HandleInput() override;
};

#endif
