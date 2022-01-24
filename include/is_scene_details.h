#ifndef HELPER_SCENE_DETAILS_H
#define HELPER_SCENE_DETAILS_H

#include "bn_array.h"
#include "bn_string.h"
#include "bn_fixed_point.h"
#include "is_direction.h"
#include "is_obstacle_type.h"
#include "is_game_scene.h"

namespace is
{

struct scene_obstacle {
    bool exists = false;
    bn::fixed_point _pos;
    obstacle_type _type;
    direction _direction = DOWN;
};

struct scene_details {
    bn::fixed_point _player_pos;
    direction _player_dir = UP;
    scene_type _type;
    bn::string<64> event_message;
    scene_obstacle obstacles[32];
};

}

#endif // HELPER_SCENE_DETAILS_H
