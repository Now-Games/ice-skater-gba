#include "is_multilevel_scene.h"

namespace is
{

multilevel_scene::multilevel_scene(game_scene _current_scene, sub_scene _current_level, scene_details details)
    : _current_scene(_current_scene)
{
    _main_level = static_cast<int>(_current_level);
    this->_current_level = _main_level;
    _player_position = details._player_pos;
}

multilevel_scene::~multilevel_scene()
{

}

bn::unique_ptr<sub_level> multilevel_scene::start_sub_level(sub_scene next_scene)
{
    BN_LOG("Loading Level: ", next_scene);
    bn::unique_ptr<sub_level> scene_ptr = bn::unique_ptr(new sub_level(_current_scene, next_scene, _player_position,
                                                            helper::get_sub_scene_details(next_scene)));
    return scene_ptr;
}

int multilevel_scene::update()
{
    bn::unique_ptr<sub_level> scene_ptr = start_sub_level(static_cast<sub_scene>(_main_level));
    while (true) {
        int next = scene_ptr->update();
        BN_LOG("Scene completed with code: ", next);

        if (next == -2) {
            _current_level = _main_level;
            BN_LOG("Restarting current Game level");
            scene_ptr = start_sub_level(sub_levels[_main_level]);
        }
        else if (next == -1) {
            int next_game_scene = static_cast<int>(_current_scene);
            BN_LOG("Next Game Scene: ", (next_game_scene+1));
            return ++next_game_scene;
        }
        else {
            if (next != _current_level) {
                BN_LOG("(next_level, current_level): ", next, _current_level);
                _current_level = next;
                _player_position = scene_ptr->get_player_position();
                scene_ptr = start_sub_level(static_cast<sub_scene>(next));
            }
        }

        bn::core::update();
    }
}

}
