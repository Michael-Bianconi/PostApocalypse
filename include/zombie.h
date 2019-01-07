#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "raylib.h"

// Hues of green and blue
extern const int ZOMBIE_COLORS[];
extern const int NUM_ZOMBIE_COLORS;
extern const int ZOMBIE_MIN_SIZE;
extern const int ZOMBIE_MAX_SIZE;
#define ZOMBIE_SPEED(size) (ZOMBIE_MAX_SIZE + 1 - size)
#define ZOMBIE_STOP_CHASING_DISTANCE 15

/**
 * Zombies are the main enemy in Postman Apocalypse. They are represented by
 * circles, and chase after the Van. If the van hits them while it's moving
 * at a significant enough speed, they'll die. If the van isn't going fast
 * enough, the zombies will damage it. Each zombie moves at a certain speed,
 * designated by their size (larger zombies are slower).
 *
 * It's position designates the center of the zombie's circle.
 */
typedef struct Zombie
{
    Vector2 position;
    float size;
    Color color;

} Zombie;

bool checkCollisionZombieZombie(Zombie* z1, Zombie* z2);

/**
 * Construct a zombie.
 * @param position Position of the zombie within the game world (at the center).
 * @param size Radius of the zombie circle.
 * @param color Color of the zombie.
 * @return Returns the constructed zombie struct.
 */
Zombie createZombie(Vector2 position, float size, Color color);

/**
 * Construct a random zombie. srand() should already be called.
 * @param position Position of the zombie within the game world at the center).
 * @return Returns the constructed zombie struct with random parameters.
 */
Zombie createRandomZombie(Vector2 position);

/**
 * Draw the zombie.
 * @param z Zombie to draw.
 */
void drawZombie(Zombie* z);

/**
 * Move the zombie by the given amounts.
 * @param z Zombie to move.
 * @param amount Amount to move the zombie by (x and y).
 * @see setZombiePosition()
 */
void moveZombie(Zombie* z, Vector2 amount);

/**
 * Move the zombie towards another point using Bresenham's algorithm.
 * @param z Zombie to move.
 * @param point Point to move to.
 */
void moveZombieTowards(Zombie* z, Vector2 point);

Color randomZombieColor();

/**
 * Set the zombie's position within the game world.
 * @param z Zombie to move.
 * @param pos Position to move the zombie to.
 * @see moveZombie()
 */
void setZombiePosition(Zombie* z, Vector2 pos);

#endif