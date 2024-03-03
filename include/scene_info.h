#ifndef SCENE_INFO_H
#define SCENE_INFO_H

#include "bn_unique_ptr.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_regular_bg_item.h"
#include "bn_string.h"
#include "bn_vector.h"
#include "bn_string.h"
#include "direction.h"
#include "obstacle_type.h"
#include "scene_type.h"

#include "bn_sprite_items_ice_rock.h"
#include "bn_sprite_items_rock_wall.h"
#include "bn_sprite_items_rock_wall_hole.h"
#include "bn_sprite_items_snowball_sheet.h"
#include "bn_sprite_items_snow_tile.h"
#include "bn_sprite_items_cracked_ice_sheet.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

struct ObstacleInfo
{
    ObstacleType type;
    bn::fixed_point position;
    Direction direction;
};

struct SceneInfo
{
    bn::string<4> sceneName;
    bn::fixed_point startPos;
    Direction startDirection;
    ObstacleInfo obstalces[32];
    SceneType sceneType;
    int previousScene;
    int nextScene;
};

struct EventSceneInfo
{
    bn::string<64> eventMessage;
};

struct MultiSceneInfo
{
    int mainScene = 0;
    bn::array<int, 3> sceneIndexes;
};

#endif // SCENE_INFO_H
