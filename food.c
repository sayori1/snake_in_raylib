#include "consts.c"

typedef struct
{
    Vector2 position;
} Food;

void updatePosition(Food *food)
{
    food->position = (Vector2){GetRandomValue(0, AREA_WIDTH - 1), GetRandomValue(0, AREA_HEIGHT - 1)};
}

void drawFood(Food *food)
{
    DrawRectangle(food->position.x * BLOCK_WIDTH, food->position.y * BLOCK_HEIGHT, BLOCK_WIDTH, BLOCK_HEIGHT, RED);
}

bool isFoodEaten(Food *food, Snake *snake)
{
    return (food->position.x == snake->body[0].x && food->position.y == snake->body[0].y);
}