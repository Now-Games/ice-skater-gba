#pragma once

#include "bn_array.h"
#include "bn_sram.h"
#include "bn_log.h"

namespace is
{
    struct SaveData
    {
        bn::array<char, 32> format;
        int furthestScene = 0;
        int currentScene = 0;
    };    
    
    extern SaveData saveData;

    void save();
    void load();
}