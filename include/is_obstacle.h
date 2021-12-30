#ifndef IS_OBSTACLE2_H
#define IS_OBSTACLE2_H

#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"
#include "bn_fixed_point.h"
#include "bn_log.h"

#include "bn_sprite_items_snowball_sheet.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

#include "is_game_constants.h"
#include "helper_extensions.h"
#include "is_obstacle_type.h"

namespace is
{

class obstacle
{
private:
    obstacle_type _type;
    bn::fixed_point _position;
    bool _can_destroy = false;
    bool is_destroyed = false;
    bn::optional<bn::sprite_ptr> _sprite;
    bn::optional<bn::sprite_animate_action<5>> _death_anim;

public:
    obstacle(bn::fixed_point, obstacle_type, bool, direction = DOWN);
    ~obstacle();
    bool can_destroy();
    bn::fixed get_collision_edge(direction);
    bn::fixed_point get_position();
    bool get_destroyed();
    void set_destroy();
    void update();
};

}

#endif // IS_OBSTACLE2_H
