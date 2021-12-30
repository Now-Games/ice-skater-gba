#include "is_main_menu.h"

namespace is
{

main_menu::main_menu(int _saved_scene) :
    text_generator(bn::sprite_text_generator(common::variable_8x16_sprite_font))
{
    saved_scene = _saved_scene;
    current_selection = 0;
    _bg = bn::regular_bg_items::title_scene.create_bg(0, 0);
    menu_ptr = bn::sprite_items::menu_pointer.create_sprite(min_x + 20, max_y - 40);

    menu_options.push_back("CONTINUE");
    menu_options.push_back("NEW GAME");

    text_generator.set_center_alignment();

    bn::fixed start_x = min_x / 2;
    for (int i = 0; i < menu_options.size(); i ++) {
        text_generator.generate(start_x + (i * 120), max_y - 40, menu_options[i], text_sprites);
    }
}

main_menu::~main_menu()
{

}

game_scene main_menu::update()
{
    while (true)
    {
        if (bn::keypad::left_pressed()) {
            current_selection -= 1;
            if (current_selection < 0)
                    current_selection = menu_options.size() - 1;
            menu_ptr->set_x(min_x + 20 + (current_selection * 120));
        }
        else if (bn::keypad::right_pressed()) {
            current_selection += 1;
            if (current_selection > menu_options.size() - 1)
                current_selection = 0;
            menu_ptr->set_x(min_x + 20 + (current_selection * 120));
        }
        else if (bn::keypad::a_pressed()) {
            switch(current_selection) {
            case 0:
                return helper::cast_to_scene(saved_scene);
            default:
                return game_scene::TUTORIAL_SCENE;
            }
        }
        bn::core::update();
    }

    return game_scene::TUTORIAL_SCENE;
}

}
