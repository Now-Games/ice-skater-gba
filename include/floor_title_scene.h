#ifndef FLOOR_TITLE_SCENE_H
#define FLOOR_TITLE_SCENE_H

#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_string.h"
#include "scene_update_result.h"

class FloorTitleScene
{
    private:
        bn::regular_bg_ptr background;
        bn::vector<bn::sprite_ptr, 32> titleSprites;
        bn::vector<bn::sprite_ptr, 32> descSprites;
        bn::sprite_text_generator titleGenerator;
        bn::sprite_text_generator descGenerator;
        
    public:
        FloorTitleScene(bn::string<32> sceneTitle);
        ~FloorTitleScene() = default;
        SceneUpdateResult update();
        
};

#endif // TITLE_SCENE_H
