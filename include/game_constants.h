#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "bn_string.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define MIN_X -120
#define MAX_X 120

#define MIN_Y -80
#define MAX_Y 80

#define PLAYER_INDEX 0

const int BLOCK_SIZE = 8;
const bn::string<6> version = "2.0";
const int sceneIndexes[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 19, 20, 22
};

#endif // GAME_CONSTANTS_H