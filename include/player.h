/**
 * Player is controlled by the user.
 *
 * @author Michael Bianconi
 * @since 02 January 2019
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "math.h"
#include "zombie.h"

#define PLAYER_SIZE 16
#define PLAYER_MAX_HEALTH 100
#define PLAYER_MAX_SPEED  10
#define PLAYER_MIN_SPEED -5
#define PLAYER_MIN_ROTATION -PI/4
#define PLAYER_MAX_ROTATION  PI/4

typedef struct Player
{
    Vector2 position;
    float speed;
    float health;
    float rotation;
    float size;

} Player;


bool checkCollisionPlayerZombie(Player* player, Zombie* zombie);
Player createPlayer(Vector2 pos);
void drawPlayer(Player* p);
void movePlayerForward(Player* p, float speed);
void printPlayer(Player* p);
void rotatePlayer(Player* p, float amount);
void setPlayerPosition(Player* p, Vector2 pos);
void setPlayerRotation(Player* p, float angle);
void setPlayerSpeed(Player* p, float speed);

/** Player's speed increases until it reaches max or min speed. */
void speedPlayerUp(Player* p, float speed);

/** Player's speed goes to zero. */
void speedPlayerDown(Player* p, float speed);

#endif