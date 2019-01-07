#include "raylib.h"
#include "zombie.h"

const int ZOMBIE_COLORS[] =
{
    0xB0BF1AFF,
    0x91C82FFF,
    0x81BA49FF,
    0x839D50FF,
    0x8FFE09FF,
    0x387C44FF,
    0x54C571FF
};
const int NUM_ZOMBIE_COLORS = sizeof(ZOMBIE_COLORS) / sizeof(int);
const int ZOMBIE_MIN_SIZE = 7;
const int ZOMBIE_MAX_SIZE = 14;

bool checkCollisionZombieZombie(Zombie* z1, Zombie* z2)
{
    return CheckCollisionCircles(z1->position, z1->size, z2->position, z2->size);
}


Zombie createZombie(Vector2 position, float size, Color color)
{
    return (Zombie){position, size, color};
}


Zombie createRandomZombie(Vector2 position)
{
    float size = (rand() % (ZOMBIE_MAX_SIZE - ZOMBIE_MIN_SIZE + 1)) + ZOMBIE_MIN_SIZE;
    Color color = randomZombieColor();
    return (Zombie){position, size, color};
}


void drawZombie(Zombie* z)
{
    DrawCircleV(z->position, z->size, z->color);
    DrawCircleLines(z->position.x, z->position.y, z->size, BLACK);
}


void moveZombie(Zombie* z, Vector2 amount)
{
    z->position.x += amount.x;
    z->position.y += amount.y;
}


void moveZombieTowards(Zombie* z, Vector2 point)
{
    if(z->position.x == point.x && z->position.y == point.y)
    {
        return;
    }
    
    int fX = point.x - z->position.x;
    int fY = point.y - z->position.y;
    double dist = sqrt( fX*fX + fY*fY );

    if (dist < ZOMBIE_STOP_CHASING_DISTANCE)
    {
        return;
    }

    double step = (ZOMBIE_SPEED(z->size) / dist);
    moveZombie(z, (Vector2){fX * step,fY * step});
}


Color randomZombieColor()
{
    return GetColor(ZOMBIE_COLORS[rand() % NUM_ZOMBIE_COLORS]);
}


void setZombiePosition(Zombie* z, Vector2 position)
{
    z->position = position;
}