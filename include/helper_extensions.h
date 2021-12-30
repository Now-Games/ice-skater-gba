#ifndef IS_EXTENSIONS_H
#define IS_EXTENSIONS_H

#include "is_direction.h"
#include "is_obstacle_type.h"
#include "is_game_scene.h"
#include "is_scene_details.h"

#include "bn_sprite_ptr.h"
#include "bn_sprite_items_rock_wall.h"
#include "bn_sprite_items_rock_wall_hole.h"
#include "bn_sprite_items_snow_tile.h"
#include "bn_sprite_items_ice_rock.h"
#include "bn_sprite_items_snowball_sheet.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

namespace is {

class helper
{
public:
    static game_scene cast_to_scene(int);
    static scene_details get_scene_details(game_scene);
    static bn::sprite_item get_sprite_item(obstacle_type);
    static bool is_destructible(obstacle_type);
};

}

#endif // IS_EXTENSIONS_H
