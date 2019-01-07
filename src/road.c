#include "raylib.h"
#include "road.h"
#include "space2d.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"

void buildRoadTriangles(Road* r)
{

    r->triangles = (Triangle*) malloc(sizeof(Triangle) * ROAD_NUM_TRIANGLES(r->num_points));
    Vector2 coords[r->num_points * 2];

    // Get the zigzagging coordinates
    int coord_counter = 0;
    for (int i = 0; i < r->num_points; i++)
    {
        Vector2 p1 = (i==0) ? r->points[i+1] : r->points[i-1];
        Vector2 p2 = r->points[i];
        Vector2 points[2];
        getPerpendicularPoints(p1,p2,r->radius,points);
        coords[coord_counter++] = (i==0) ? points[1] : points[0];
        coords[coord_counter++] = (i==0) ? points[0] : points[1];
    }

    // Turn those coordinates into triangles
    int triangle_counter = 0;
    for (int i = 0; i < ROAD_NUM_TRIANGLES(r->num_points); i++)
    {
        Triangle tri;
        tri.values[0] = coords[i];
        tri.values[1] = coords[i+1];
        tri.values[2] = coords[i+2];
        sortPolygonVerticesCounterClockwise(tri.values,3);
        r->triangles[triangle_counter++] = tri;

    }
}


Road createRoad(Vector2* points, int num_points, float radius)
{
    Road road;
    road.points = points;
    road.num_points = num_points;
    road.radius = radius;
    road.start_angle = 0;
    road.end_angle = 0;
    buildRoadTriangles(&road);
    return road;
}

void drawRoad(Road* road)
{
    for (int i = 0; i < ROAD_NUM_TRIANGLES(road->num_points); i++)
    {
        DrawTriangle(
            road->triangles[i].values[0],
            road->triangles[i].values[1],
            road->triangles[i].values[2],
            ROAD_COLOR
        );
    }

    DrawPolyExLines(road->points, road->num_points, YELLOW);
}

void freeRoad(Road* road)
{
    free(road->triangles);
}