/**
 * collisions.h handles all of the collision functions not already
 * defined in raylib.
 * @author Michael Bianconi
 * @since 05 January 2019
 */
#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "raylib.h"

// ALREADY DEFINED BY RAYLIB ===================================================
    // Point-Rectangle
    // Point-Circle
    // Point-Triangle
    // Rectangle-Rectangle
    // Circle-Circle
    // Circle-Rectangle

// Side note:
    // Distance formula: sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

// =============================================================================

bool checkCollisionPointPoint(Vector2 a, Vector2 b);

bool checkCollisionPointLine(Vector2 point, Vector2 lineStart, Vector2 lineEnd);

bool checkCollisionLineLine(
    Vector2 lineStart1, Vector2 lineEnd1, Vector2 lineStart2, Vector2 lineEnd2);

bool checkCollisionRectangleLine(
    Rectangle rect, Vector2 lineStart, Vector2 lineEnd);

bool checkCollisionRectanglePolygon(
    Rectangle rect, Vector2* points, int num_points);

bool checkCollisionCircleLine(
    Vector2 circleOrigin, float radius, Vector2 lineStart, Vector2 lineEnd);

bool checkCollisionCirclePolygon(
    Vector2 circleOrigin, float radius, Vector2* points, int num_points);

bool checkCollisionPolygonPolygon(
    Vector2* polygon1, int num_points1, Vector2* polygon2, int num_points2);

#endif