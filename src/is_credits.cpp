#include "is_credits.h"

namespace is
{

credits::credits() :
    text_generator(bn::sprite_text_generator(common::fixed_8x16_sprite_font))
{
    text_generator.set_center_alignment();
    text_generator.generate(0, -64, "CREDITS", title_text_sprites);

    for (int i = 0; i < 5; i ++) {
        text_generator.generate(0, -32 + (18 * i), credit_screens[current_index++], msg_text_sprites);
    }
}

credits::~credits()
{

}

game_scene credits::update()
{
    //
    while (true) {
        //
        if (bn::keypad::a_pressed()) {
            msg_text_sprites.clear();

            if (current_index >= credits_size) {
                return game_scene::MAIN_MENU;
            }

            for (int i = 0; i < 5; i ++) {
                text_generator.generate(0, -32 + (18 * i),
                                        credit_screens[current_index++], msg_text_sprites);
            }
        }

        bn::core::update();
    }

    return game_scene::MAIN_MENU;
}

}
