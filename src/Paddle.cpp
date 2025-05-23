#include "Paddle.h"

void Paddle::limit_movement() {
    if (y <= 0) {
        y = 0;
    }
    if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}

Paddle::Paddle(float x, float y, Color color, float width, float height) : Sprite(x, y, color), width(width), height(height) {}

void Paddle::Draw() const {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, color);
}

void Paddle::Update() {
    if (frozen) {
        return;
    }
    apply_vel_x();
    apply_vel_y();

    limit_movement();
}

void Paddle::HandleInput() {  
    float curr_speed = speed;
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        curr_speed *= sprint_modifier;
    }
    
    if (!(IsKeyDown(KEY_W) || IsKeyDown(KEY_S))) {
        set_vel_y(0.0f);
        return;
    }
    if (IsKeyDown(KEY_W)) {
        set_vel_y(-curr_speed);
    } else {
        set_vel_y(curr_speed);
    }
}

float Paddle::get_width() {
    return width;
}

float Paddle::get_height() {
    return height;
}