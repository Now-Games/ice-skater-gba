#ifndef IS_SAVE_DATA_H
#define IS_SAVE_DATA_H

#include "bn_array.h"

namespace is
{

struct save_data
{
    bn::array<char, 32> format;
    int current_scene = 1;
};

}

#endif // IS_SAVE_DATA_H
