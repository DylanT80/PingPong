#include <Game.h>
#include <raylib.h>

Game::Game(int screen_width, int screen_height, int target_fps) : screen_width(screen_width), screen_height(screen_height), target_fps(target_fps), frozen(false) {
    ball = new Ball(screen_width / 2, screen_height / 2, WHITE, 15.0f, 36.0f);

    paddle_one = new Paddle(0, screen_height / 2 - 150, WHITE, 50.0f, 300.0f);
    paddle_two = new CpuPaddle(screen_width - 50, screen_height / 2 - 150, WHITE, 50.0f, 300.0f);
}

Game::~Game() {
    delete ball;
    delete paddle_one;
    delete paddle_two;

    ball = nullptr;
    paddle_one = nullptr;
    paddle_two = nullptr;
}

void Game::restart_round(bool is_frozen) {
    ball->Reset();
    paddle_one->Reset();
    paddle_two->Reset();

    ball->Freeze(is_frozen);
    paddle_one->Freeze(is_frozen);
    paddle_two->Freeze(is_frozen);

    countdownStartTime = GetTime();
    frozen = is_frozen;
}

void Game::handle_frozen() {
    double elapsed = GetTime() - countdownStartTime;
    if (elapsed >= 3.0) {
        restart_round(false);
    } else {
        countdown = 3 - static_cast<int>(elapsed);
    }
}

void Game::handle_collisions() {
    if (CheckCollisionCircleRec(Vector2{ball->get_x(), ball->get_y()}, ball->get_radius(), 
        Rectangle{paddle_one->get_x(), paddle_one->get_y(), paddle_one->get_width(), paddle_one->get_height()})) {
        
        ball->set_vel_x(-ball->get_vel_x());
    }
    if (CheckCollisionCircleRec(Vector2{ball->get_x(), ball->get_y()}, ball->get_radius(), 
        Rectangle{paddle_two->get_x(), paddle_two->get_y(), paddle_two->get_width(), paddle_two->get_height()})) {

        ball->set_vel_x(-ball->get_vel_x());
    }


    if (ball->get_x() - ball->get_radius() <= 0) {
        playerTwoScore++;
        restart_round(true);
    }
    if (ball->get_x() + ball->get_radius() >= GetScreenWidth()) {
        playerOneScore++;
        restart_round(true);
    }
}


void Game::run() {
    SetTargetFPS(target_fps);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, title);

    restart_round(true);
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
    if (frozen) {
        handle_frozen();
        return;
    }

    ball->Update();
    paddle_one->Update();
    paddle_two->Update(ball->get_y());

    handle_collisions();
}

void Game::render() {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    ball->Draw();
    paddle_one->Draw();
    paddle_two->Draw();

    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
    DrawText(TextFormat("%i", playerOneScore), screen_width / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", playerTwoScore), 3*(screen_width / 4) - 20, 20, 80, WHITE);

    if (frozen) {
        DrawText(TextFormat("%i", countdown), screen_width / 2 - 40, screen_height / 2 - 80, 200, RED);
    }

    EndDrawing();
}
