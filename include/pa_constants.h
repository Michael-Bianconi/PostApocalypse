/**
 * pa_constants holds a bunch of game constants such as screen dimensions
 * and background color.
 * @author Michael Bianconi
 * @since 05 January 2019
 */

#ifndef PA_CONSTANTS_H
#define PA_CONSTANTS_H

#include "raylib.h"

// Window
#define BACKGROUND GRASS_COLOR
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 320
#define TARGET_FPS 30
#define TITLE "Post: Apocalypse"

#define GRASS_COLOR GetColor(0x10680AFF)

// Zombies
#define NUM_ZOMBIES 50

#define PLAYER_START_POSITION (Vector2){0,0}

#endif