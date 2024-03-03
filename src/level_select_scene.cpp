#include "level_select_scene.h"
#include "scene_info.h"
#include "game_scenes.h"
#include "game_constants.h"

#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_level_button.h"
#include "bn_regular_bg_items_level_select_bg.h"
#include "bn_sprite_items_menu_pointer.h"
#include "common_variable_16x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"

LevelSelectScene::LevelSelectScene(SaveData saveData) : 
    background(bn::regular_bg_items::level_select_bg.create_bg(0, 0)),
    pointer(bn::sprite_items::menu_pointer.create_sprite(0, 0)),
    titleGenerator(bn::sprite_text_generator(common::variable_16x16_sprite_font))
{
    furthestUnlockedScene = saveData.furthestScene;
    BN_LOG("Current Scene: ", currentScene);
    BN_LOG("Furthest Scene: ", furthestUnlockedScene);
    
    //write level select title
    titleGenerator.set_center_alignment();
    titleGenerator.generate(0, -72, "Level Select", titleSprites);

    int col = 0;
    int row = 0;
    int numScenes = sizeof(sceneIndexes) / sizeof(sceneIndexes[0]);
    for (int i = 0; i <= numScenes; i++)
    {
        if (furthestUnlockedScene < sceneIndexes[i])
            break;
            
        if (saveData.currentScene == sceneIndexes[i])
            currentScene = i;
            
        int x = -96 + (col * 32);
        int y = -24 + (row * 24);
        scenes.push_back({
            bn::sprite_items::level_button.create_sprite(x, y),
            sceneIndexes[i]
        });
        if (i == currentScene)
            pointer.set_position(x - 16, y);

        col++;
        if (col >= maxCols) {
            col = 0;
            row++;
        }
    }
    
    SceneInfo info = getSceneDetails(sceneIndexes[currentScene]);
    //write current Floor Name
    titleGenerator = bn::sprite_text_generator(common::variable_8x8_sprite_font);
    titleGenerator.set_center_alignment();
    titleGenerator.generate(0, -48, info.sceneName, floorNameSprites);
}

void LevelSelectScene::updatePointerPosition()
{
    //rows
    int row = currentScene / maxCols;
    int col = currentScene % maxCols;
    int x = -96 + (col * 32);
    int y = -24 + (row * 24);
    pointer.set_position(x - 16, y);
}

void LevelSelectScene::updateFloorName()
{
    floorNameSprites.clear();
    SceneInfo info = getSceneDetails(sceneIndexes[currentScene]);
    titleGenerator.generate(0, -48, info.sceneName, floorNameSprites);
}

int LevelSelectScene::update()
{
    if (bn::keypad::left_pressed())
    {
        currentScene--;
        if (currentScene < 0)
            currentScene = 0;
        updatePointerPosition();
        updateFloorName();
    }
    else if (bn::keypad::right_pressed())
    {
        currentScene++;
        if (currentScene > furthestUnlockedScene)
            currentScene = furthestUnlockedScene;
        updatePointerPosition();
        updateFloorName();
    }
    else if (bn::keypad::up_pressed())
    {
        currentScene -= maxCols;
        if (currentScene < 0)
            currentScene = 0;
        updatePointerPosition();
        updateFloorName();
    }
    else if (bn::keypad::down_pressed())
    {
        currentScene += maxCols;
        if (currentScene > furthestUnlockedScene)
            currentScene = furthestUnlockedScene;
        updatePointerPosition();
        updateFloorName();
    }

    if (bn::keypad::a_pressed())
    {
        return sceneIndexes[currentScene];
    }

    return -1; //DO NOTHING
}