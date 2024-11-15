#include "floor_title_scene.h"
#include "bn_keypad.h"
#include "bn_regular_bg_items_floor_title_bg.h"
#include "fixed_32x64_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"

FloorTitleScene::FloorTitleScene(bn::string<32> sceneTitle) : background(bn::regular_bg_items::floor_title_bg.create_bg(0, 0)), 
    titleGenerator(bn::sprite_text_generator(fixed_32x64_sprite_font)),
    descGenerator(bn::sprite_text_generator(common::fixed_8x16_sprite_font))
{
    titleGenerator.set_center_alignment();
    titleGenerator.generate(0, -32, sceneTitle, titleSprites);
    
    descGenerator.set_center_alignment();
    descGenerator.generate(0, 40, "Press A to continue", descSprites);
}

SceneUpdateResult FloorTitleScene::update()
{
    if (bn::keypad::a_pressed())
    {
        return SceneUpdateResult::S_Next;
    }

    return SceneUpdateResult::S_None;
}