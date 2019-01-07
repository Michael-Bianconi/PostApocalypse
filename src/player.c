#include "raylib.h"
#include "player.h"
#include "zombie.h"

bool checkCollisionPlayerZombie(Player* player, Zombie* zombie)
{
    return CheckCollisionCircles(player->position, player->size/2, zombie->position, zombie->size);
}

Player createPlayer(Vector2 pos)
{
    Player player;
    player.position = pos;
    player.rotation = 0;
    player.speed = 0;
    player.health = PLAYER_MAX_HEALTH;
    player.size = 16;
    return player;
}


void movePlayerForward(Player* p, float speed)
{

    p->position.x += speed * sin(DEG2RAD*p->rotation);
    p->position.y -= speed * cos(DEG2RAD*p->rotation);
}


void drawPlayer(Player* p)
{
    DrawPoly(p->position, 3, PLAYER_SIZE, p->rotation+180, RED);
    DrawCircleLines(p->position.x, p->position.y, PLAYER_SIZE/2, YELLOW);
}


void printPlayer(Player* p)
{
    printf("[Post: Apocalypse]\n");
    printf("\tPlayer at (%1.1f,%1.1f)\n",p->position.x, p->position.y);
    printf("\tRotation: %1.1f\n", p->rotation);
    printf("\tSpeed: %1.1f\n", p->speed);
    printf("\tHealth: %1.1f\n", p->health);
}


void rotatePlayer(Player* p, float amount)
{
    p->rotation += amount;
    if (p->rotation > 360) { p->rotation -= 360; }
    if (p->rotation < 0) { p->rotation += 360; }
}


void setPlayerPosition(Player* p, Vector2 pos)
{
    p->position = pos;
}


void setPlayerRotation(Player* p, float angle)
{
    p->rotation = angle;
    if (p->rotation > 360) { p->rotation -= 360; }
    if (p->rotation < 0) { p->rotation += 360; }
}


void setPlayerSpeed(Player* p, float speed)
{
    if (speed < PLAYER_MIN_SPEED) { speed = PLAYER_MIN_SPEED; }
    if (speed > PLAYER_MAX_SPEED) { speed = PLAYER_MAX_SPEED; }
    p->speed = speed;
}

void speedPlayerUp(Player* p, float speed)
{
    if (speed > 0) { p->speed = fmaxf(PLAYER_MAX_SPEED, p->speed + speed); }
    else if (speed < 0) { p->speed = fmaxf(PLAYER_MIN_SPEED, p->speed - speed);}
}

void speedPlayerDown(Player* p, float speed)
{
    if (p->speed > 0) { p->speed = fmaxf(0, p->speed - speed); }

    else if (p->speed < 0) { p->speed = fminf(0, p->speed + speed); }
}