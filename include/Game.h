#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"

/**
 * @class Game
 * @brief Manages the game loop, window, and main gameplay components.
 */
class Game {
private:
    int target_fps;
    int screen_width;
    int screen_height;
    const char* title = "Ping Pong";

    Ball* ball;
    Paddle* paddle_one;
    CpuPaddle* paddle_two;

    /// @brief Handles player input amongst all game objects within the game window
    void handleInput();
    /// @brief Updates the game window (e.g. movement, collisions, etc.)
    void update();
    /// @brief Draws all game objects in the game window
    void render();

public:
    /**
     * @brief Constructs a new Game instance
     * @param screen_width Width of the game window
     * @param screen_height Height of the game window
     * @param target_fps Fps of the game window
     */
    Game(int screen_width, int screen_height, int target_fps);

    /// @brief Frees up game objects in memory
    ~Game();

    /// @brief Runs the main game loop
    void run();
};

#endif
