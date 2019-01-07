/**
 * Source code for space2d.
 * @author Michael Bianconi
 * @since 04 January 2019
 */
#include <stdlib.h> // malloc
#include <math.h> // sqrt, atan
#include "raylib.h" // Vector2
#include "space2d.h"
#include "stdio.h"

Vector2 getCentroid(Vector2* vectors, int num_points)
{
    float x = 0;
    float y = 0;

    for (int i = 0; i < num_points; i++)
    {
        x += vectors[i].x;
        y += vectors[i].y;
    }

    return (Vector2){x/num_points, y/num_points};
}


Vector2 getMidpointOfVectors(Vector2 v1, Vector2 v2)
{
    return (Vector2){(v1.x+v2.x)/2,(v1.y+v2.y)/2};
}


void getPerpendicularPoints(
    Vector2 p1, Vector2 p2, float radius, Vector2 result[2])
{
    // Translate the given vectors such that p1 is at the origin
    Vector2 delta = {p1.x-p2.x, p1.y-p2.y};

    // Distance from p1 to p2
    float distance = sqrt((delta.x*delta.x)+(delta.y*delta.y));

    // Transform delta into a unit vector
    delta.x /= distance;
    delta.y /= distance;

    // Find the x and y distances from p2 to the perpendicular points
    Vector2 u = {radius * delta.x, radius * delta.y};

    // The perpendicular point that is clockwise from p1
    result[0] = (Vector2){p2.x + u.y, p2.y - u.x};

    // The perpendicular point that is counter-clockwise from p1
    result[1] = (Vector2){p2.x - u.y, p2.y + u.x};
}


void getRegularPolygonVectors(Vector2 pos, int n, float r, Vector2* result)
{
    float theta = (2*PI/n); // radians
    for (int i = 0; i < n; i++)
    {
        result[i].x = pos.x + (r * cos(i*theta));
        result[i].y = pos.y + (r * sin(i*theta)); 
        printVector2(&result[i]);
    }
}


void printRectangle(Rectangle* r)
{
    printf("Rectangle: (%1.1f, %1.1f, %1.1f, %1.1f)\n", 
        r->x, r->y, r->width, r->height);
}


void printTriangle(Triangle* t)
{
    printf("Triangle:\n");
    printf("\t"); printVector2(&t->values[0]);
    printf("\t"); printVector2(&t->values[1]);
    printf("\t"); printVector2(&t->values[2]);
}


void printVector2(Vector2* v)
{
    printf("Vector2: (%1.1f, %1.1f)\n",
        v->x, v->y);
}


void sortPolygonVerticesCounterClockwise(Vector2* vectors, int num_points)
{
    Vector2 centroid = getCentroid(vectors, num_points);

    float angles[num_points];

    for (int i = 0; i < num_points; i++)
    {
        angles[i] = atan2(centroid.y - vectors[i].y, centroid.x - vectors[i].x);  
    }

    // selection sort, greatest to smallest, both the angles and vertices
    for (int i = 0; i < 2; i++) 
    { 
        int min = i; 

        for (int j = i+1; j < 3; j++)
        {

            if (angles[j] > angles[min]) 
            {
                min = j;
            }          
        }
  
        // Put the largest element first
        float temp_angle = angles[min];
        Vector2 temp_vector = vectors[min];
        angles[min] = angles[i];
        angles[i] = temp_angle;
        vectors[min] = vectors[i];
        vectors[i] = temp_vector;
    }
}