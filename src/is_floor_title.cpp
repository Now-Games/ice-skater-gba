#include "is_floor_title.h"

namespace is
{

floor_title::floor_title(game_scene scene) :
    message_generator(bn::sprite_text_generator(common::variable_8x16_sprite_font)),
    title_generator(bn::sprite_text_generator(fixed_32x64_sprite_font)),
    _bg(bn::regular_bg_items::floor_title_bg.create_bg(0, 0))
{
    current_scene = scene;
    int scene_number = static_cast<int>(scene);

    //display the title
    title_generator.set_center_alignment();
    bn::string<32> str = "B";
    str.append(bn::to_string<32>(current_scene - 2));
    title_generator.generate(0, -50, str, title_text_sprites);

    //display the message
    message_generator.set_center_alignment();
    message_generator.generate(0, 40, "Press A button to progress", msg_text_sprites);

    underline_sprites.push_back(bn::sprite_items::frozen_underline_start.create_sprite(-32, -16));
    underline_sprites.push_back(bn::sprite_items::frozen_underline_m2.create_sprite(0, -16));
    underline_sprites.push_back(bn::sprite_items::frozen_underline_end.create_sprite(32, -16));
}

floor_title::~floor_title()
{

}

game_scene floor_title::update()
{
    while (true) {
        if (bn::keypad::a_pressed()) {
            break;
        }
        bn::core::update();
    }

    return current_scene;
}

}
