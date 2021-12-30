#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "bn_sram.h"

//#include "bn_music_items.h"
#include "bn_music_items.h"
#include "is_save_data.h"
#include "is_floor_title.h"
#include "is_scene.h"
#include "is_main_menu.h"

namespace is {
class scene_manager
{
private:
    save_data save;
    game_scene _current_scene;

    void read_save();
    game_scene load_scene();

public:
    scene_manager();
    ~scene_manager();
    void update();
};
}

#endif // SCENE_MANAGER_H
