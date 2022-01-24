#include "is_multilevel_scene.h"

namespace is
{

multilevel_scene::multilevel_scene(game_scene _current_scene, sub_scene _current_level, scene_details details)
    : scene(_current_scene, details), _current_level(_current_level)
{

}

multilevel_scene::~multilevel_scene()
{

}

int multilevel_scene::start_sub_level(sub_scene next_scene)
{
    scene_details details = helper::get_sub_scene_details(next_scene);
    load_scene_objects(details);
//    _player->set_position(details._player_pos);
//    _player->set_player_direction(details._player_dir);
}

int multilevel_scene::update_logic()
{
    get_input();

    _player->update();
    if (bn::keypad::pressed(bn::keypad::key_type::UP) ||
             bn::keypad::pressed(bn::keypad::key_type::DOWN) ||
             bn::keypad::pressed(bn::keypad::key_type::LEFT) ||
             bn::keypad::pressed(bn::keypad::key_type::RIGHT)) {
        set_player_move_limit();
    }

    if (closest_obstacle_index != -1 &&
            _player->get_position() == map_objects[closest_obstacle_index].get_position()) {
        switch (map_objects[closest_obstacle_index].get_type()) {
        case CRACKED_ICE:
        {
            map_objects[closest_obstacle_index].set_destroy();
            _player->play_fall_anim();
            return -1;
        }
        case ROCK_WALL_HOLE:
        {
            return get_next_scene();
        }
        case STAIRS:
        {
            //run new multilevel scene update
            if (map_objects[closest_obstacle_index].get_direction() == UP) {
                int next_level = static_cast<int>(_current_level);
                start_sub_level(static_cast<sub_scene>(--next_level));
            }
            else if (map_objects[closest_obstacle_index].get_direction() == DOWN) {
                int next_level = static_cast<int>(_current_level);
                start_sub_level(static_cast<sub_scene>(++next_level));
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}

}
