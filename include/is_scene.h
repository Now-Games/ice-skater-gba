#ifndef SCENE_H
#define SCENE_H

#include "bn_core.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_log.h"
#include "bn_unique_ptr.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "is_game_scene.h"
#include "is_obstacle.h"
#include "helper_extensions.h"
#include "is_player.h"
#include "is_pause.h"

#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"
#include "common_variable_8x16_sprite_font.h"

namespace is {
class scene
{
private:

protected:
    bool scene_paused;
    game_scene _scene;
    bn::sprite_text_generator text_generator;
    bn::vector<bn::sprite_ptr, 32> text_sprites;
    bn::optional<bn::regular_bg_ptr> _bg;
    bn::vector<obstacle, 32> map_objects;
    bn::optional<player> _player;
    int closest_obstacle_index = -1;
    bn::fixed bounds_min_x;
    bn::fixed bounds_max_x;
    bn::fixed bounds_min_y;
    bn::fixed bounds_max_y;

    void get_closest_object();
    void destroy_obstacle(bn::fixed, bn::fixed);
    virtual void set_player_move_limit();
    game_scene get_next_scene();

public:
    scene(game_scene, scene_details);
    virtual ~scene();
    virtual void get_input();
    virtual game_scene update();
};
}

#endif // SCENE_H
