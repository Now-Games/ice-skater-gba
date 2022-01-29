#ifndef IS_MAIN_MENU_H
#define IS_MAIN_MENU_H

#include "bn_core.h"
#include "bn_vector.h"
#include "bn_string_view.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_optional.h"
#include "bn_keypad.h"
#include "bn_fixed.h"
#include "bn_sprite_text_generator.h"

#include "helper_extensions.h"
#include "is_game_constants.h"
#include "is_game_scene.h"

#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_items_title_scene.h"
#include "common_variable_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"

namespace is
{

class main_menu
{
private:
    bn::vector<bn::sprite_ptr, 32> text_sprites;
    bn::sprite_text_generator text_generator;
    bn::vector<bn::sprite_ptr, 32> version_sprites;
    bn::sprite_text_generator version_generator;
    bn::vector<bn::string_view, 2> menu_options;
    bn::optional<bn::regular_bg_ptr> _bg;
    bn::optional<bn::sprite_ptr> menu_ptr;
    int current_selection;
    int saved_scene;

public:
    main_menu(int);
    ~main_menu();
    game_scene update();
};

}

#endif // IS_MAIN_MENU_H
