#pragma once

#include "bn_point.h"
#include "direction.h"

namespace is
{
    enum GameObjectType
    {
        Empty,
        RockWall,
        RockWallHole,
        RockWallCracked,
        Snow,
        Snowball,
        IceRock,
        CrackedIce,
        Stairs,
        Shuriken
    };
    
    struct GameObjectDetails
    {
        GameObjectType objectType;
        bn::point position;
        Direction direction;
    };
}