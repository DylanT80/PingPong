#include "Paddle.h"

Paddle::Paddle(int x, int y, Color color, int width, int height) : Sprite(x, y, color), width(width), height(height) {}

void Paddle::Draw() const {
    DrawRectangle(x, y, width, height, color);
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