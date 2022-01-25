#include "is_sub_level.h"

namespace is
{

sub_level::sub_level(game_scene _scene, sub_scene _sub_scene, bn::fixed_point player_pos, scene_details details) :
    scene(_scene, details)
{
    current_sub_level = _sub_scene;
    _player->set_position(player_pos);
}

sub_level::~sub_level()
{

}

bn::fixed_point sub_level::get_player_position()
{
    return _player->get_position();
}

/**
 * @brief -2 to restart to main sub level, -1 to goto next game scene, 0+ to goto certain level
 * @return
 */
int sub_level::update_obstacle_interaction()
{
    if (closest_obstacle_index != -1 &&
            _player->get_position() == map_objects[closest_obstacle_index].get_position()) {
        switch (map_objects[closest_obstacle_index].get_type()) {
        case CRACKED_ICE:
        {
            map_objects[closest_obstacle_index].set_destroy();
            _player->play_fall_anim();
            return -2;
        }
        case ROCK_WALL_HOLE:
        {
            BN_LOG("Moving to next Scene");
            return -1;
        }
        case STAIRS:
        {
            int _scene = static_cast<int>(current_sub_level);
            if (map_objects[closest_obstacle_index].get_direction() == direction::UP)
                return --_scene;
            else
                return ++_scene;
        }
        default:
            break;
        }
    }

    return static_cast<int>(current_sub_level);
}

}
