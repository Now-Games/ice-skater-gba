#ifndef IS_MULTILEVEL_SCENE_H
#define IS_MULTILEVEL_SCENE_H

#include "is_sub_level.h"

namespace is
{

class multilevel_scene
{
private:
    game_scene _current_scene;
    int _main_level;
    int _current_level;
    bn::vector<sub_scene, 10> sub_levels;
    bn::fixed_point _player_position;

    bn::unique_ptr<sub_level> start_sub_level(sub_scene);

public:
    multilevel_scene(game_scene, sub_scene, scene_details);
    ~multilevel_scene();
    int update();
};

}

#endif // IS_MULTILEVEL_SCENE_H
