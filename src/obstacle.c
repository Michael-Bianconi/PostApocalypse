#include "raylib.h"
#include "obstacle.h"


const int OBSTACLE_COLORS[] =
{
    0x8D6645FF,
    0x653E1DFF,
    0x5B3413FF,
    0x6F4827FF,
    0x512A09FF,
    0x3D1600FF
};
const int NUM_OBSTACLE_COLORS = sizeof(OBSTACLE_COLORS) / sizeof(int);
const int OBSTACLE_OUTLINE_THICKNESS = 1;


Obstacle createObstacle(Vector2 position, float size, Color color)
{
    Obstacle o;
    o.bounds = (Rectangle){position.x, position.y, size, size};
    o.color = color;
    return o;
}


void drawObstacle(Obstacle* o)
{
    DrawRectangleRec(o->bounds, o->color);
    DrawRectangleLinesEx(o->bounds, OBSTACLE_OUTLINE_THICKNESS, BLACK);
}


Color randomObstacleColor()
{
    return GetColor(OBSTACLE_COLORS[rand() % NUM_OBSTACLE_COLORS]);
}