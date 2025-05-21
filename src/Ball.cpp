#include "Ball.h"

Ball::Ball(int x, int y, Color color, float radius) : Sprite(x, y, color), radius(radius) {}

void Ball::Draw() const {
    DrawCircle(x, y, radius, color);
}

