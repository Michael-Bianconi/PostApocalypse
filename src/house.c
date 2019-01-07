/**
 * Source code for houses.
 * @author Michael Bianconi
 * @since 04 January 2019
 */
#include "raylib.h"
#include "house.h"
#include "space2d.h" // scaleRectangle(), translateRectangle()
#include "pa_constants.h"
#include <stdlib.h> // malloc()

House createHouse(Rectangle bounds, Rectangle collision, Rectangle* rects, int num_rects);

House createHouse0(Rectangle bounds, float orientation)
{
    House house;

    // House0 is made out of four rectangles
    house.bounds = bounds;
    house.num_rects = 4;
    house.rects = (Rectangle*) malloc(sizeof(Rectangle) * house.num_rects);
    house.colors = (Color*) malloc(sizeof(Color) * house.num_rects);

    Rectangle ground = {0,0,1,1};
    Color ground_c = GRASS_COLOR;

    Rectangle path = {0.4, 0, 0.2, 0.25};
    Color path_c = GetColor(0xF3A76FFF);

    Rectangle roof1 = {0.1,0.2,0.8,0.35};
    Color roof1_c = GetColor(0xB53806FF);

    Rectangle roof2 = {0.1,0.55,0.8,0.35};
    Color roof2_c = GetColor(0x702608FF);

    // create the collision box, scaled and translated
    house.collision_box = (Rectangle){roof1.x, roof1.y, roof1.width, roof1.height+roof2.height};
    house.collision_box.x *= bounds.width;
    house.collision_box.y *= bounds.height;
    house.collision_box.width *= bounds.width;
    house.collision_box.height *= bounds.height;
    house.collision_box.x += bounds.x;
    house.collision_box.y += bounds.y;

    Rectangle rects[] = {ground, path, roof1, roof2};

    Color colors[] = {ground_c, path_c, roof1_c, roof2_c};

    for (int i = 0; i < house.num_rects; i++)
    {
        // scale the rectangle (including position)
        rects[i].x *= bounds.width;
        rects[i].y *= bounds.height;
        rects[i].width *= bounds.width;
        rects[i].height *= bounds.height;

        // Translate the rectangle
        rects[i].x += bounds.x;
        rects[i].y += bounds.y;

        // apply to the house
        house.rects[i] = rects[i];
        house.colors[i] = colors[i];
    }

    return house;
}


void drawHouse(House* h)
{
    for (int i = 0; i < h->num_rects; i++)
    {
        DrawRectangleRec(h->rects[i],h->colors[i]);
    }

    //DrawRectangleLinesEx(h->collision_box, 6, YELLOW); 
}


void freeHouse(House* h)
{
    free(h->rects);
    free(h->colors);
}