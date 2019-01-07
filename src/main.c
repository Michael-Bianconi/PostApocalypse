#include "raylib.h"
#include "obstacle.h"
#include "zombie.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "player.h"
#include "road.h"
#include "house.h"
#include "space2d.h"
#include "pa_constants.h"

int main()
{

    SetTargetFPS(TARGET_FPS);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    srand(time(NULL));

    // CREATE PLAYER ==========================================================
    Player player = createPlayer(PLAYER_START_POSITION);

    // CREATE CAMERA
    Camera2D camera;
    
    camera.target = player.position;
    camera.offset = PLAYER_START_POSITION;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    // CREATE ZOMBIES ==========================================================

    Zombie zombies[NUM_ZOMBIES];

    for (int i = 0; i < NUM_ZOMBIES; i++)
    {
        Vector2 position = {rand() % 640, rand() % 320};
        zombies[i] = createRandomZombie(position);
    }

    // ROADS ===================================================================
    Vector2 points1[] = {{320,420},{320,240},{480,160},{560,0},{560,-100},{300,-150},{200,-150}};
    Road road1 = createRoad(points1, 8, 60);

    Vector2 roundabout_points[10];
    getRegularPolygonVectors((Vector2){0,0},9,300,roundabout_points);
    roundabout_points[9] = roundabout_points[0];
    Road roundabout = createRoad(roundabout_points, 10, 60);


    // Houses ==================================================================
    House house0 = createHouse0((Rectangle){0,0,100,100},0);

    int frames = 0;
    while(!WindowShouldClose())
    {
        // UPDATE ==============================================================

        if (IsKeyDown(KEY_UP))
        {
            //speedPlayerUp(&player, 0.01);
            player.speed += 0.3;
            if (player.speed > PLAYER_MAX_SPEED) { player.speed = PLAYER_MAX_SPEED; }
        }

        else
        {
            //speedPlayerDown(&player, 0.01);
            player.speed -= 1;
            if (player.speed < 0) { player.speed = 0; }
        }

        if (IsKeyDown(KEY_RIGHT)) { rotatePlayer(&player, 4.0); }
        if (IsKeyDown(KEY_LEFT)) { rotatePlayer(&player, -4); }

        movePlayerForward(&player, player.speed);
        camera.offset = (Vector2){-player.position.x+SCREEN_WIDTH/2, -player.position.y+SCREEN_HEIGHT/2};


        for (int i = 0; i < NUM_ZOMBIES; i++)
        {
            Vector2 original_pos = zombies[i].position;
            moveZombieTowards(&zombies[i], player.position);

            for (int g = 0; g < NUM_ZOMBIES; g++)
            {
                if (g != i)
                {
                    if (checkCollisionZombieZombie(&zombies[i],&zombies[g]))
                    {
                        setZombiePosition(&zombies[i], original_pos);
                        break;
                    }
                }
            }
        }

        house0.rotation++;

        // DRAW ================================================================

        BeginDrawing();
        BeginMode2D(camera);

            ClearBackground(BACKGROUND);

            drawRoad(&roundabout);
            drawHouse(&house0);


            drawPlayer(&player);   

            for (int i = 0; i < NUM_ZOMBIES; i++)
            {
                drawZombie(&zombies[i]);
            }

        EndMode2D();
        EndDrawing();
    }

    freeRoad(&road1);
    freeHouse(&house0);
    CloseWindow();
}