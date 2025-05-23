#include "CpuPaddle.h"

CpuPaddle::CpuPaddle(float x, float y, Color color, float width, float height) : Paddle(x, y, color, width, height) {}

void CpuPaddle::Update(float ball_y) {
    if (frozen) {
        return;
    }

    if (y + height / 2 > ball_y) {
        vel_y = -speed;
    }
    if (y + height / 2 <= ball_y) {
        vel_y = speed;
    }

    apply_vel_x();
    apply_vel_y();
    
    limit_movement();
}