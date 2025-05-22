#include "Ball.h"

Ball::Ball(float x, float y, Color color, float radius) : Sprite(x, y, color), radius(radius) {}

void Ball::Draw() const {
    DrawCircle(x, y, radius, color);
}

void Ball::Update() {
    apply_vel_x();
    apply_vel_y();

    if (y - radius < 0 || y + radius > GetScreenHeight()) {
        vel_y *= -1;
    }

    if (x - radius < 0 || x + radius > GetScreenWidth()) {
        vel_x *= -1;
    }
}

