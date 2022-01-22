#include "is_scene_manager.h"

namespace is {
scene_manager::scene_manager() : _current_scene(game_scene::MAIN_MENU)
{
    read_save();
}

scene_manager::~scene_manager()
{

}

void scene_manager::read_save()
{
    //read data from sram
    bn::sram::read(save);

    bn::array<char, 32> expected_format_tag;
    bn::istring_base expected_format_tag_istring(expected_format_tag._data);
    bn::ostringstream expected_format_tag_stream(expected_format_tag_istring);

    BN_LOG("Saved Scene: ", save.current_scene);

    if (save.format != expected_format_tag) {
        BN_LOG("RESETTING SAVE DATA");
        save = {
            expected_format_tag,
            1
        };
    }
}

game_scene scene_manager::load_scene() {
    if (_current_scene != TUTORIAL_SCENE && _current_scene != TUTORIAL_SCENE_2) {
        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_current_scene));
        title_ptr->update();
        title_ptr.reset();
    }
    bn::unique_ptr<scene> scene_ptr = bn::unique_ptr(new scene(_current_scene,
                                                        helper::get_scene_details(_current_scene)));

    game_scene next = scene_ptr->update();
    return next;
}

void scene_manager::update()
{
    BN_LOG("Current Scene: ", _current_scene);
    game_scene _next_scene = MAIN_MENU;
    switch(_current_scene)
    {
    case MAIN_MENU:
    {
        bn::music_items::music_box.play(0.5);
        bn::unique_ptr<main_menu> menu_ptr = bn::unique_ptr(new main_menu(save.current_scene));
        _next_scene = menu_ptr->update();
        BN_LOG("Next Scene: ", _next_scene);
        bn::music_items::mystical_p.play(0.4);
        break;
    }
    case CREDITS:
    {
        bn::unique_ptr<credits> credit_ptr = bn::unique_ptr(new credits());
        _next_scene =  credit_ptr->update();
        break;
    }
    default:
        _next_scene = load_scene();
        break;
    }

    if (_next_scene != _current_scene) {
        save.current_scene = static_cast<int>(_next_scene);

        BN_LOG("Saving Scene: ", save.current_scene);
        //save data to sram
        bn::sram::write(save);

        //set _current_scene as next_scene
        _current_scene = _next_scene;
    }
}

}
