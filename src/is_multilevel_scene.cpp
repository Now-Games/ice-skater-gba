#include "is_multilevel_scene.h"

namespace is
{

multilevel_scene::multilevel_scene(game_scene _current_scene, sub_scene _current_level, scene_details details)
    : _current_scene(_current_scene)
{
    int level_size = sizeof(details.sub_levels) / sizeof(details.sub_levels[0]);
    for (int i = 0; i < level_size; i ++) {
        if (details.sub_levels[i] == _current_level) {
            this->_main_level = i;
        }
        sub_levels.push_back(details.sub_levels[i]);
    }
    _player_position = details._player_pos;
}

multilevel_scene::~multilevel_scene()
{

}

bn::unique_ptr<sub_level> multilevel_scene::start_sub_level(sub_scene next_scene)
{
    bn::unique_ptr<sub_level> scene_ptr = bn::unique_ptr(new sub_level(_current_scene, next_scene, _player_position,
                                                            helper::get_sub_scene_details(next_scene)));
    return scene_ptr;
}

int multilevel_scene::update()
{
    bn::unique_ptr<sub_level> scene_ptr = start_sub_level(sub_levels[_main_level]);
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
                _current_level = next;
                _player_position = scene_ptr->get_player_position();
                scene_ptr = start_sub_level(sub_levels[next]);
            }
        }

        bn::core::update();
    }
}

}
