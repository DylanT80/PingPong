#include <Game.h>
#include <raylib.h>

Game::Game(int screen_width, int screen_height, int target_fps) : screen_width(screen_width), screen_height(screen_height), target_fps(target_fps) {
    ball = new Ball(screen_width / 2, screen_height / 2, WHITE, 36.0f);
    ball->set_vel_x(5.0f);
    ball->set_vel_y(5.0f);

    paddle_one = new Paddle(0, screen_height / 2 - 150, WHITE, 50, 300);
    paddle_two = new CpuPaddle(screen_width - 50, screen_height / 2 - 150, WHITE, 50, 300);
}

Game::~Game() {
    delete ball;
    delete paddle_one;
}

void Game::run() {
    SetTargetFPS(target_fps);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, title);
    while (!WindowShouldClose()) {
        handleInput();
        update();
        render();
    }
}

void Game::handleInput() {
    paddle_one->HandleInput();
}

void Game::update() {
    ball->Update();
    paddle_one->Update();
    paddle_two->Update(ball->get_y());
}

void Game::render() {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    ball->Draw();

    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    
    paddle_one->Draw();
    paddle_two->Draw();

    EndDrawing();
}
