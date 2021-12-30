#include "is_scene_manager.h"

namespace is {
scene_manager::scene_manager() : _current_scene(game_scene::MAIN_MENU)
{
    read_save();
    bn::music_items::mystical_p.play(0.5);
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
        bn::unique_ptr<main_menu> menu_ptr = bn::unique_ptr(new main_menu(save.current_scene));
        _next_scene = menu_ptr->update();
        BN_LOG("Next Scene: ", _next_scene);
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


//    case TUTORIAL_SCENE:
//    {
//        bn::unique_ptr<tutorial_scene> tutorial_scene_ptr = bn::unique_ptr(new tutorial_scene());
//        _next_scene = tutorial_scene_ptr->update();
//        break;
//    }
//    case TUTORIAL_SCENE_2:
//    {
//        bn::unique_ptr<tutorial_scene2> tut_scene2_ptr = bn::unique_ptr(new tutorial_scene2());
//        _next_scene = tut_scene2_ptr->update();
//        break;
//    }
//    case STAGE_ONE:
//    {
//        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_next_scene));
//        title_ptr->update();
//        title_ptr.reset();
//        bn::unique_ptr<stage_one> stage_one_ptr = bn::unique_ptr(new stage_one());
//        _next_scene = stage_one_ptr->update();
//        break;
//    }
//    case STAGE_TWO:
//    {
//        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_next_scene));
//        title_ptr->update();
//        title_ptr.reset();
//        bn::unique_ptr<stage_two> stage_two_ptr = bn::unique_ptr(new stage_two());
//        _next_scene = stage_two_ptr->update();
//        break;
//    }
//    case STAGE_THREE:
//    {
//        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_next_scene));
//        title_ptr->update();
//        title_ptr.reset();
//        bn::unique_ptr<stage_three> stage_three_ptr = bn::unique_ptr(new stage_three());
//        _next_scene = stage_three_ptr->update();
//        break;
//    }
//    case STAGE_FOUR:
//    {
//        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_next_scene));
//        title_ptr->update();
//        title_ptr.reset();
//        bn::unique_ptr<stage_four> stage_four_ptr = bn::unique_ptr(new stage_four());
//        _next_scene = stage_four_ptr->update();
//        break;
//    }
//    case STAGE_FIVE:
//    {
//        bn::unique_ptr<floor_title> title_ptr = bn::unique_ptr(new floor_title(_next_scene));
//        title_ptr->update();
//        title_ptr.reset();
//        bn::unique_ptr<stage_five> stage_five_ptr = bn::unique_ptr(new stage_five());
//        _next_scene = stage_five_ptr->update();
//        break;
//    }
