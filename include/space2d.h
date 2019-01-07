/**
 * space2D contains several utility functions that revolve around 2D space.
 *
 * @author Michael Bianconi
 * @since 04 January 2019
 */
#ifndef SPACE2D_H
#define SPACE2D_H

#include "raylib.h" // Vector2

typedef struct Triangle
{
    Vector2 values[3];

} Triangle;


/**
 * Gets the distance from a point p to a line (that is, the smallest
 * line length than can touch both the point and line).
 * @param p Point by itself.
 * @param a Point A on the line.
 * @param b Point B on the line.
 * @return Returns the distance from point p to line AB.
 */
float getDistancePointLine(Vector2 p, Vector2 a, Vector2 b)


/**
 * Get the centroid of the convex polygon (the intersection of the lines at
 * the midpoint, and orthogonal, to each side).
 * @param vectors The array of vertices.
 * @param num_points The number of vertices in the n-gon.
 * @return Returns the centroid of the regular polygon.
 */
Vector2 getCentroid(Vector2* vectors, int num_points);


/**
 * Get the midpoint between two vectors.
 * @param v1 Vector 1.
 * @param v2 Vector 2.
 * @return Returns the midpoint between v1 and v2.
 */
Vector2 getMidpointOfVectors(Vector2 v1, Vector2 v2);


/**
 * Given two points that form a line, find the two points perpendicular to
 * to the second vector with distance between those points and p2.
 * The first result is the point that is clockwise from p1.
 * The second result is always counter-clockwise from p1.
 * @param p1 First point.
 * @param p2 Second point.
 * @param radius The distance between p2 and the perpendicular points.
 * @param result The results are stored here.
 */
void getPerpendicularPoints(
    Vector2 p1, Vector2 p2, float radius, Vector2 result[2]);


/**
 * Given a number of sides and a radius, get the vectors constructing
 * a polygon.
 * @param pos Position of the center of the polygon.
 * @param n Number of sides in the n-gon.
 * @param r Radius of the n-gon.
 * @param result Write to this array (should be of size n).
 */
void getRegularPolygonVectors(Vector2 pos, int n, float r, Vector2* result);


void printRectangle(Rectangle* r);
void printTriangle(Triangle* t);
void printVector2(Vector2* v);


/**
 * Sort a convex polygon such that its verticies are in counter-clockwise
 * order. Used for drawing polygons with raylib.
 * @param vectors The array of vertices.
 * @param num_points The number of points in the n-gon.
 */
void sortPolygonVerticesCounterClockwise(Vector2* vectors, int num_points);


#endif