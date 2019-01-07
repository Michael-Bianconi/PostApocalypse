/**
 * @author Michael Bianconi
 * @since 04 January 2019
 */
#ifndef HOUSE_H
#define HOUSE_H

#define HOUSE_FACING_NORTH 0
#define HOUSE_FACING_WEST 90
#define HOUSE_FACING_SOUTH 180
#define HOUSE_FACING_EAST 270
#define HOUSE0_NUM_SHAPES 4


typedef struct House
{
    Rectangle bounds;
    Rectangle collision_box;
    Rectangle* rects;
    Color* colors;
    Vector2* origins;
    int num_rects;
    float rotation;

} House;


House createHouse0(Rectangle bounds, float orientation);
House createHouse1(Rectangle bounds, int orientation);

void drawHouse(House* house);
void freeHouse(House* house);

#endif