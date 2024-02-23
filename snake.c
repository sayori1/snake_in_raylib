#include "raymath.h"

#include "consts.c"
#ifndef RAYLIB_H
#include "raylib.h"
#endif

#ifndef STDIO_H
#include <stdio.h>
#endif

#include <stdlib.h>

typedef struct
{
    Vector2 *body;
    int length;
    Vector2 direction;

    float elapsed;
    int steps;
    float speed;
} Snake;

void growSnake(Snake *snake)
{
    snake->length++;
    snake->body = realloc(snake->body, snake->length * sizeof(Vector2));
    snake->body[snake->length - 1] = (Vector2){snake->body[snake->length - 2].x - snake->direction.x, snake->body[snake->length - 2].y - snake->direction.y};
}

void initSnake(Snake *snake, int initialLength)
{
    growSnake(snake);
    snake->body[0] = (Vector2){5, 5};
    snake->speed = 0.2;

    snake->direction = (Vector2){1, 0};
    for (int i = 0; i < initialLength; i++)
    {
        growSnake(snake);
    }
    snake->direction = (Vector2){0, 0};
}

void drawSnake(Snake *snake)
{
    for (int i = 0; i < snake->length; i++)
    {
        DrawRectangle(snake->body[i].x * BLOCK_WIDTH, snake->body[i].y * BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT, BLACK);
    }
}

void moveSnake(Snake *snake, Vector2 direction)
{
    if (Vector2Length(direction) == 0)
        return;
    for (int i = snake->length - 1; i > 0; i--)
    {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = (Vector2){snake->body[0].x + direction.x, snake->body[0].y + direction.y};
}

void handleInput(Snake *snake)
{
    if (IsKeyPressed(KEY_UP))
    {
        snake->direction = (Vector2){0, -1};
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        snake->direction = (Vector2){0, 1};
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        snake->direction = (Vector2){-1, 0};
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        snake->direction = (Vector2){1, 0};
    }
}

void updateSnake(Snake *snake)
{
    snake->elapsed += GetFrameTime();

    if (snake->elapsed > snake->steps * snake->speed)
    {
        snake->steps++;
        moveSnake(snake, snake->direction);
    }
}