#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "bn_fixed.h"
#include "bn_string.h"
#include "bn_display.h"
#include "bn_vector.h"
#include "bn_fixed_point.h"
#include "is_obstacle_type.h"

namespace is {
    const bn::fixed min_y = -(bn::display::height() / 2);
    const bn::fixed max_y = bn::display::height() / 2;
    const bn::fixed min_x = -(bn::display::width() / 2);
    const bn::fixed max_x = (bn::display::width() / 2);
    const bn::fixed tile_height = 16;
    const bn::string<6> game_version = "1.1";
}

#endif // GAME_CONSTANTS_H
