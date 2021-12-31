#ifndef IS_OBSTACLE_H
#define IS_OBSTACLE_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

namespace is {
enum obstacle_type {
    SNOW,
    ROCK_WALL,
    SNOWBALL,
    CRACKED_WALL,
    CRACKED_ICE,
    ICE_ROCK,
    ROCK_WALL_HOLE
};

}
#endif // IS_OBSTACLE_H
