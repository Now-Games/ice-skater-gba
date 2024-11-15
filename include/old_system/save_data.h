#pragma once
// #ifndef SAVE_DATA_H
// #define SAVE_DATA_H

#include "bn_array.h"

struct SaveData
{
    bn::array<char, 32> format;
    int furthestScene = 0;
    int currentScene = 0;
};

// #endif