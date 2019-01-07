#ifndef ROAD_H
#define ROAD_H

#include "raylib.h"
#include "space2d.h" // triangles

// ROAD ========================================================================

#define ROAD_NUM_TRIANGLES(x) (x*2)-2
#define ROAD_COLOR GRAY

typedef struct Road
{
    /** Beginning and end of the road, along with any turns. */
    Vector2* points;

    /** Number of points in the road. */
    int num_points;

    /** Angle of the road at the beginning. */
    float start_angle;

    /** Angle of the road at the end. */
    float end_angle;

    /** Width of the road / 2. */
    float radius;

    /** The road is split into triangles for easier drawing. */
    Triangle* triangles;

} Road;

void buildRoadTriangles(Road* r); // helper method
Road createRoad(Vector2* points, int num_points, float radius);
void drawRoad(Road* road);
void freeRoad(Road* road); // always free the road after you're done with it

#endif