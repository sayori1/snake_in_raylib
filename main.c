

#include "raylib.h"
#include "snake.c";
#include "consts.c";
#include "food.c";

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake game");

    Snake snake = {};
    Food food = {};

    initSnake(&snake, SNAKE_INIT_LENGTH);
    updatePosition(&food);

    SetTargetFPS(FPS);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        drawSnake(&snake);
        handleInput(&snake);
        updateSnake(&snake);

        drawFood(&food);
        if (isFoodEaten(&food, &snake))
        {
            growSnake(&snake);
            updatePosition(&food);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}