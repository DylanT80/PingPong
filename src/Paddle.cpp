#include "Paddle.h"

void Paddle::limit_movement() {
    if (y <= 0) {
        y = 0;
    }
    if (y + height >= GetScreenHeight()) {
        y = GetScreenHeight() - height;
    }
}

Paddle::Paddle(float x, float y, Color color, int width, int height) : Sprite(x, y, color), width(width), height(height) {}

void Paddle::Draw() const {
    DrawRectangle(x, y, width, height, color);
}

void Paddle::Update() {
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