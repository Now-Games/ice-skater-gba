#ifndef PLAYER_H
#define PLAYER_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_item.h"
#include "bn_optional.h"
#include "bn_log.h"

#include "is_direction.h"
#include "is_game_constants.h"

#include "bn_sprite_items_player_sheet.h"

namespace is {
class player
{
private:
    direction player_facing;
    bool isMoving;
    bool initialDraw = true;
    bn::fixed_point _position;
    bn::fixed_point _move_limit;
    bn::optional<bn::sprite_ptr> _sprite;

    void set_sprite_direction();

public:
    player(bn::fixed, bn::fixed, direction = UP);
    ~player();
    direction get_direction();
    bn::fixed_point get_position();
    bn::fixed_point get_move_limit();
    void set_player_direction(direction);
    void set_position(bn::fixed_point);
    void set_move_limit(bn::fixed, bn::fixed);
    void move(bn::fixed, bn::fixed);
    void update();
};
}
#endif // PLAYER_H
