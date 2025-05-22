#ifndef BALL_H
#define BALL_H

#include "Sprite.h"

/**
 * @class Ball
 * @brief Represents a ball sprite with a position, velocity, color, and radius.
 * 
 * Inherits from Sprite and adds radius to define the size of the ball.
 */
class Ball : public Sprite {
private:
    int radius; ///< Radius of the ball in pixels.

public:
    /**
     * @brief Construct a new Ball object.
     * 
     * @param x Initial x-position of the ball.
     * @param y Initial y-position of the ball.
     * @param color Color of the ball.
     * @param radius Radius of the ball in pixels.
     */
    Ball(float x, float y, Color color, float radius);

    /**
     * @brief Draws the ball on the screen.
     * 
     * Overrides the pure virtual Draw method in Sprite.
     */
    void Draw() const override;

    /**
     * @brief Update behavior of ball
     */
    void Update() override;
};

#endif
