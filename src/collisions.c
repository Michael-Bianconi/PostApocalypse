/**
 * Source code for collisions.h.
 * @author Michael Bianconi
 * @since 05 January 2019
 */
#include "raylib.h"
#include "collisions.h"
#include <math.h> // sqrt

/*
bool checkCollisionCircleLine(
    Vector2 circle, float radius, Vector2 a, Vector2 b)
{
    // First, check if either end of the line is within the circle.
    if (checkCollisionPointCircle(a, circle, radius)
    ||  checkCollisionPointCircle(b, circle, radius))
    {
        return true;
    }

    // Get the lengths (x and y deltas) of the line
    Vector2 lengths = {a.x - b.x, a.y - b.y};
    float len = sqrt((lengths.x*lengths.x) + (lengths.y*lengths.y));

    // Get the dot product
    float dot = (((circle.x-a.x)*(b.x-a.x)) + ((circle.y-a.y)*(b.y-a.y))) / (len*len);

    // Get the closest point on the line
    Vector2 closest = {a.x + (dot*(b.x-a.x)), a.y + (dot * (b.y-a.y))};

}*/


bool checkCollisionPointPoint(Vector2 a, Vector2 b)
{
    return a.x == b.x && a.y == b.y;
}


bool checkCollisionPointLine(Vector2 point, Vector2 lineStart, Vector2 lineEnd)
{
    return false;
}


bool checkCollisionLineLine(
    Vector2 lineStart1, Vector2 lineEnd1, Vector2 lineStart2, Vector2 lineEnd2)
{
    return false;
}


bool checkCollisionCircleRegularPolygon(
    Vector2 circleOrigin, float circleRadius, int num_points, float polyRadius)
{
    return false;
}


bool checkCollisionCirclePolygon(
    Vector2 circleOrigin, float radius, Vector2* points, int num_points)
{
    return false;
}