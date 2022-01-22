#ifndef IS_MULTILEVEL_SCENE_H
#define IS_MULTILEVEL_SCENE_H

#include "is_scene.h"

namespace is
{

class multilevel_scene : public scene
{
private:
    sub_scene _current_level;

    int start_sub_level(sub_scene);

public:
    multilevel_scene(game_scene, sub_scene, scene_details);
    ~multilevel_scene();
    int update_logic() override;
};

}

#endif // IS_MULTILEVEL_SCENE_H
