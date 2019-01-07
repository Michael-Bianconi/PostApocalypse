/**
 * Obstacles are represented as brown and gray boxes. Colliding with one
 * will cause the Vehicle to slow down or stop.
 *
 * @author Michael Bianconi
 * @since 31 December 2018
 */
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

extern const int OBSTACLE_COLORS[];
extern const int NUM_OBSTACLE_COLORS;
extern const int OBSTACLE_OUTLINE_THICKNESS;

/**
 * Obstacles are represented as brown and gray boxes. Colliding with one
 * will cause the Vehicle to slow down or stop.
 */
typedef struct Obstacle
{
    Rectangle bounds;
    Color color;

} Obstacle;

/**
 * Construct a new Obstacle.
 * @param bounds Position and size of the Obstacle.
 * @param color Color of the obstacle.
 * @return Returns a new Obstacle.
 */
Obstacle createObstacle(Vector2 position, float size, Color color);

/**
 * Draws an Obstacle.
 * @param o Obstacle to draw.
 */
void drawObstacle(Obstacle* o);

/**
 * Return a random obstacle color.
 * srand() must be called prior to this!
 * @return Returns a random obstacle color.
 */
Color randomObstacleColor();

#endif