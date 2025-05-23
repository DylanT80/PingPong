#include "Ball.h"

Ball::Ball(float x, float y, Color color, float speed, float radius) : Sprite(x, y, color), speed(speed), radius(radius) {
    float choices[2] = {1.0f, -1.0f};
    set_vel_x(speed * choices[GetRandomValue(0, 1)]);
    set_vel_y(speed * choices[GetRandomValue(0, 1)]);
}

void Ball::Draw() const {
    DrawCircle(x, y, radius, color);
}

void Ball::Update() {
    if (frozen) {
        return;
    }

    apply_vel_x();
    apply_vel_y();

    if (y - radius < 0 || y + radius > GetScreenHeight()) {
        vel_y *= -1;
    }

    if (x - radius < 0 || x + radius > GetScreenWidth()) {
        vel_x *= -1;
    }
}

void Ball::Reset() {
    x = initial_x;
    y = initial_y;

    float choices[2] = {1.0f, -1.0f};
    set_vel_x(speed * choices[GetRandomValue(0, 1)]);
    set_vel_y(speed * choices[GetRandomValue(0, 1)]);
}

float Ball::get_radius() {
    return radius;
}