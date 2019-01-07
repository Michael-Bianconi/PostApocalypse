#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"

typedef struct Sprite
{
    Texture2D texture;
    Rectangle source_rect;
    Rectangle dest_rect;

} Sprite;


/**
 * Construct a new Sprite.
 * @param path Path to image.
 * @return The constructed Sprite.
 */
Sprite createSprite(char* path);

/**
 * Draw the Sprite.
 * @param s Sprite to draw.
 */
void drawSprite(Sprite* s, float rotation);

/**
 * Get the origin of the vehicle (it's middle).
 * @param v Vehicle to get the origin of.
 * @return The middle of the vehicle.
 */
Vector2 getSpriteOrigin(Vehicle* v);

/**
 * Get the position of the vehicle (upper left corner).
 * @param v Vehicle to get the position of.
 * @return The position of the vehicle.
 */
Vector2 getVehiclePosition(Vehicle* v);

/**
 * Move the vehicle by the given amounts.
 * @param v Vehicle to move.
 * @param amount Amount to move the vehicle by (x and y).
 * @see setVehiclePosition()
 */
void moveVehicle(Vehicle* v, Vector2 amount);

/**
 * Print out the parameters of the Vehicle.
 * @param v Vehicle to print.
 */
void printVehicle(Vehicle* v);

/**
 * Rotate the vehicle and it's coords to the given value.
 * @param v Vehicle to rotate.
 * @param rotation Rotate to this value (radians).
 */
void rotateVehicle(Vehicle* v, float rotation);

/**
 * Set the vehicle's position within the game world.
 * @param v Vehicle to move.
 * @param pos Position to move the vehicle to.
 * @see moveVehicle()
 */
void setVehiclePosition(Vehicle* v, Vector2 pos);

/**
 * Set the vehicle's rotation.
 * @param v Vehicle to rotate.
 * @param angle Angle to set.
 */
void setVehicleRotation(Vehicle* v, float angle);

/**
 * Unload the vehicle texture.
 * @param v Vehicle to unload.
 */
void unloadVehicle(Vehicle* v);

#endif