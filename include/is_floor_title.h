#ifndef IS_FLOOR_TITLE_H
#define IS_FLOOR_TITLE_H

#include <string>

#include "bn_core.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_ptr.h"

#include "helper_extensions.h"
#include "is_game_scene.h"
#include "fixed_32x64_sprite_font.h"

#include "bn_regular_bg_items_floor_title_bg.h"
#include "bn_sprite_items_frozen_underline_start.h"
#include "bn_sprite_items_frozen_underline_m1.h"
#include "bn_sprite_items_frozen_underline_m2.h"
#include "bn_sprite_items_frozen_underline_end.h"
#include "common_variable_8x16_sprite_font.h"

namespace is
{

class floor_title
{
private:
    bn::sprite_text_generator message_generator;
    bn::sprite_text_generator title_generator;
    bn::vector<bn::sprite_ptr, 32> msg_text_sprites;
    bn::vector<bn::sprite_ptr, 32> title_text_sprites;
    bn::vector<bn::sprite_ptr, 3> underline_sprites;
    bn::regular_bg_ptr _bg;
    game_scene current_scene;


public:
    floor_title(game_scene);
    ~floor_title();
    game_scene update();
};

}

#endif // IS_FLOOR_TITLE_H
