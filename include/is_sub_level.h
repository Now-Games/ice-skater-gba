#ifndef IS_SUB_LEVEL_H
#define IS_SUB_LEVEL_H

#include "is_scene.h"

namespace is
{

class sub_level : public scene
{
private:
    sub_scene current_sub_level;

public:
    sub_level(game_scene, sub_scene, bn::fixed_point, scene_details);
    ~sub_level();
    bn::fixed_point get_player_position();
    int update_obstacle_interaction() override;
};

}

#endif // IS_SUB_LEVEL_H
