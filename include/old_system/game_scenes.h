#ifndef GAME_SCENES_H
#define GAME_SCENES_H

#include "scene_info.h"

#include "bn_vector.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

static SceneInfo getSceneDetails(int sceneIndex)
{
    switch(sceneIndex)
    {
        case 0:
            return { //Tutorial 1
                "B1",
                0, 5,
                Direction::Up,
                { 
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down }, //Exit
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 5, Direction::Down },
                },
                SceneType::Event, -1, 1
            };
        case 1:
            return { //Tutorial 2
                "B2",
                0, 5,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down }, //Exit
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 5, Direction::Down },
                    { GameObjectType::GOT_Snowball, 0, 0, Direction::Down },
                },
                SceneType::Event, 0, 2
            };
        case 2:
            return { //Stage 1
                "B3",
                0, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down }, //Exit
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, 0, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -7, Direction::Down },
                },
                SceneType::Basic, 1, 3
            };
        case 3:
            return { //Stage 2
                "B4",
                0, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, -8, -9, Direction::Down }, //Exit
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 2, Direction::Down },
                    { GameObjectType::GOT_IceRock, 6, 0, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, -7, Direction::Down },
                    { GameObjectType::GOT_Snowball, -8, -5, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                },
                SceneType::Basic, 2, 4
            };
        case 4:
            return { //Stage 3
                "B5",
                14, 5,
                Direction::Left,
                {
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -7, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -5, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 3, Direction::Right },
                    { GameObjectType::GOT_RockHole, -14, -3, Direction::Right }, //Exit
                    { GameObjectType::GOT_RockWall, -14, 5, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 7, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 9, Direction::Right },
                    { GameObjectType::GOT_IceRock, -12, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, 5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 10, -7, Direction::Down },
                    { GameObjectType::GOT_Snowball, -10, -1, Direction::Down },
                    { GameObjectType::GOT_Snowball, -10, -5, Direction::Down },
                    { GameObjectType::GOT_Snowball, -12, -3, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 14, 5, Direction::Down },
                },
                SceneType::Basic, 3, 5
            };
        case 5:
            return { //Stage 4
                "B6",
                -8, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, -4, -9, Direction::Down }, //Exit
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 0, -9, Direction::Down }, 
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -5, Direction::Down},
                    { GameObjectType::GOT_IceRock, -14, 1, Direction::Down},
                    { GameObjectType::GOT_IceRock, -6, -7, Direction::Down},
                    { GameObjectType::GOT_IceRock, -2, -7, Direction::Down},
                    { GameObjectType::GOT_IceRock, -2, -3, Direction::Down},
                    { GameObjectType::GOT_IceRock, -6, 7, Direction::Down},
                    { GameObjectType::GOT_IceRock, 0, 9, Direction::Down},
                    { GameObjectType::GOT_IceRock, 6, 1, Direction::Down},
                    { GameObjectType::GOT_IceRock, 12, -7, Direction::Down},
                    { GameObjectType::GOT_IceRock, 14, -3, Direction::Down},
                    { GameObjectType::GOT_Snowball, -4, -5, Direction::Down},
                    { GameObjectType::GOT_SnowPatch, -8, 9, Direction::Down}
                },
                SceneType::Basic, 4, 6
            };
        case 6:
            return     { //Stage 5
                "B7",
                0, 5,
                Direction::Up,
                {
                  { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                  { GameObjectType::GOT_RockHole, 0, -9, Direction::Down }, //Exit
                  { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                  { GameObjectType::GOT_IceRock, 4, 3, Direction::Down },
                  { GameObjectType::GOT_IceRock, -4, 3, Direction::Down },
                  { GameObjectType::GOT_IceRock, 4, -1, Direction::Down },
                  { GameObjectType::GOT_IceRock, -4, -1, Direction::Down },
                  { GameObjectType::GOT_IceRock, 4, -5, Direction::Down },
                  { GameObjectType::GOT_IceRock, -4, -5, Direction::Down },
                  { GameObjectType::GOT_SnowPatch, 0, 5,  Direction::Down },
                },
                SceneType::Event, 5, 7
            };
        case 7:
            return { //Stage 6
                "B8",
                14, 3,
                Direction::Up,
                {
                  { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                  { GameObjectType::GOT_IceRock, -2, -7, Direction::Down },
                  { GameObjectType::GOT_IceRock, 2, -7, Direction::Down },
                  { GameObjectType::GOT_IceRock, 4, -7, Direction::Down },
                  { GameObjectType::GOT_IceRock, -2, -3, Direction::Down },
                  { GameObjectType::GOT_IceRock, -10, -5, Direction::Down },
                  { GameObjectType::GOT_IceRock, -12, 5, Direction::Down },
                  { GameObjectType::GOT_IceRock, -8, 1, Direction::Down },
                  { GameObjectType::GOT_IceRock, 0, 3, Direction::Down },
                  { GameObjectType::GOT_IceRock, 12, 9, Direction::Down },
                  { GameObjectType::GOT_IceRock, 10, -5, Direction::Down },
                  { GameObjectType::GOT_Snowball, 0, -5, Direction::Down },
                  { GameObjectType::GOT_Snowball, 4, -1, Direction::Down },
                  { GameObjectType::GOT_Snowball, -4, 9, Direction::Down },
                  { GameObjectType::GOT_SnowPatch, 14, 3, Direction::Down },
                },
                SceneType::Basic, 6, 8
            };
        case 8:
            return { //Stage 7
                "B9",
                0, 5,
                Direction::Up,
                {
                  { GameObjectType::GOT_RockHole, -8, -9, Direction::Down },
                  { GameObjectType::GOT_RockHole, 8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 0, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 14, -9,Direction::Down },
                  { GameObjectType::GOT_IceRock, -10, -7, Direction::Down },
                  { GameObjectType::GOT_IceRock, 8, -7, Direction::Down },
                  { GameObjectType::GOT_CrackedWall, -8, -9, Direction::Down },
                  { GameObjectType::GOT_SnowPatch, 0, 5, Direction::Down }
                },
                SceneType::Event, 7, 9
            };
        case 9:
            return { //Stage 8
                "B10",
                -2, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockHole, 8, -9, Direction::Down},
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -12, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 6, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, 1, Direction::Down },
                    { GameObjectType::GOT_Snowball, 8, -7, Direction::Down },
                    { GameObjectType::GOT_Snowball, -2, -1, Direction::Down },
                    { GameObjectType::GOT_CrackedWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, -2, 9, Direction::Down }
                },
                SceneType::Basic, 8, 10
            };
        case 10:
            return { //Stage 9
                "B11",
                0, 5,
                Direction::Up,
                {
                  { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                  { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                  { GameObjectType::GOT_CrackedWall, 0, -9, Direction::Down },
                  { GameObjectType::GOT_SnowPatch, 0, 5, Direction::Down }
                },
                SceneType::Event, 9, 11
            };
        case 11:
            return { //Stage 10
                "B12",
                2, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_CrackedWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_Snowball, -4, -7, Direction::Down },
                    { GameObjectType::GOT_Snowball, 0, -7, Direction::Down },
                    { GameObjectType::GOT_Snowball, 10, -5, Direction::Down },
                    { GameObjectType::GOT_Snowball, -8, -3, Direction::Down },
                    { GameObjectType::GOT_Snowball, -2, -3, Direction::Down },
                    { GameObjectType::GOT_Snowball, 4, -1, Direction::Down },
                    { GameObjectType::GOT_Snowball, -2, 1, Direction::Down },
                    { GameObjectType::GOT_Snowball, -10, 3, Direction::Down },
                    { GameObjectType::GOT_Snowball, -2, 3, Direction::Down },
                    { GameObjectType::GOT_Snowball, -4, 5, Direction::Down },
                    { GameObjectType::GOT_Snowball, 10, 5, Direction::Down },
                    { GameObjectType::GOT_Snowball, -10, 9, Direction::Down },
                    { GameObjectType::GOT_Snowball, -4, 9, Direction::Down },
                    { GameObjectType::GOT_Snowball, 14, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, 5, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 2, 9, Direction::Down }
                },
                SceneType::Basic, 10, 12
            };
        case 12:
            return { //Stage 11
                "B13",
                14, 1,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, -14, 5, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -9,Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -7,Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -5,Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -3,Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 3, Direction::Right },
                    { GameObjectType::GOT_CrackedIce, -12, -1, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 14, -1, Direction::Down }
                },
                SceneType::Event, 11, 13
            };
        case 13:
            return { //Stage 12
                "B14",
                14, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, -14, -1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -7, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -5, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, -3, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 1, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 3, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 5, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 7, Direction::Right },
                    { GameObjectType::GOT_RockWall, -14, 9, Direction::Right },
                    { GameObjectType::GOT_CrackedWall, -14, 1, Direction::Right },
                    { GameObjectType::GOT_CrackedWall, -14, -1, Direction::Right },
                    { GameObjectType::GOT_IceRock, 6, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, 3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -12, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, 9, Direction::Down },
                    { GameObjectType::GOT_CrackedIce, -12, 1, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 14, -9, Direction::Down }
                },
                SceneType::Basic, 12, 14
            };
        case 14:
            return { //Stage 13
                "B15",
                0, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9,Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -12, 3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 6, 1, Direction::Down },
                    { GameObjectType::GOT_CrackedIce, -4, 3, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                },
                SceneType::Basic, 13, 15
            };
        case 15:
            return { //Stage 14
                "B16",
                0, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_CrackedWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, -1, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -1, Direction::Down },
                    { GameObjectType::GOT_IceRock, -12, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 14, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, 3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, 5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 9, Direction::Down },
                    { GameObjectType::GOT_CrackedIce, -8, 5, Direction::Down },
                    { GameObjectType::GOT_CrackedIce, 8, 3, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                },
                SceneType::Basic, 14, 16
            };
        case 16:
            return { //Stage 15 Main
                "B17",
                -8, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 14, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 6, 9, Direction::Down },
                    { GameObjectType::GOT_StairsDown, 0, 1, Direction::Down },
                    { GameObjectType::GOT_StairsDown, 12, -5, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, -8, 9, Direction::Down },
                },
                SceneType::MultiLevel, 15, 19
            };
        case 17:
            return { //Stage 15 sub
                "",
                0, 0,
                Direction::Down,
                {
                    { GameObjectType::GOT_IceRock, 0, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, 9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, 9, Direction::Down },
                    { GameObjectType::GOT_StairsUp, 0, 1, Direction::Up },
                    { GameObjectType::GOT_StairsUp, 12, -5, Direction::Up },
                },
                SceneType::MultiLevel, 15, -1
            };
        case 18:
            return { //Stage 16 Sub
                "",
                0, 9,
                Direction::Up,
                {
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_CrackedWall, 0, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 10, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 10, -1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, 5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -6, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 9, Direction::Down },
                    { GameObjectType::GOT_StairsDown, -10, -5, Direction::Down },
                    { GameObjectType::GOT_StairsDown, 10, -5, Direction::Down },
                },
                SceneType::MultiLevel, 16, 20
            };
        case 19:
            return { //Stage 16 Main
                "B18",
                0, 9,
                Direction::Down,
                {
                    { GameObjectType::GOT_IceRock, 0, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 14, 3, Direction::Down },
                    { GameObjectType::GOT_StairsUp, -10, -5, Direction::Up },
                    { GameObjectType::GOT_StairsUp, 10, -5, Direction::Up },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                },
                SceneType::MultiLevel, 16, 20
            };
        case 20:
            return {
                "B19",
                0, 5,
                Direction::Down,
                {
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, -1, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, -3, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, -5, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, -7, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 1, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 3, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 5, Direction::Down },
                },
                SceneType::Event, 18, 22
            };
        case 21:
            return { //Stage 20 sub
                "",
                0, 9,
                Direction::Down,
                {
                    { GameObjectType::GOT_IceRock, -14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, -1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 14, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 6, 3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 10, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 9, Direction::Down },
                    { GameObjectType::GOT_StairsDown, 0, -3, Direction::Down },
                    { GameObjectType::GOT_StairsDown, -10, -1, Direction::Down },
                    { GameObjectType::GOT_Snowball, 0, -3, Direction::Down },
                },
                SceneType::MultiLevel, 20, -1
            };
        case 22:
            return { //Stage 20 Main
                "B20",
                0, 9,
                Direction::Down,
                {
                    { GameObjectType::GOT_RockHole, 0, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -14, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, -2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 2, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 4, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 6, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 8, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 10, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 12, -9, Direction::Down },
                    { GameObjectType::GOT_RockWall, 14, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -12, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, -2, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, 0, -1, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 8, 1, Direction::Down },
                    { GameObjectType::GOT_StairsDown, -10, -5, Direction::Down },
                    { GameObjectType::GOT_StairsUp, 0, -3, Direction::Up },
                    { GameObjectType::GOT_StairsUp, -10, -1, Direction::Up },
                    { GameObjectType::GOT_StairsDown, 10, -1, Direction::Down },
                    { GameObjectType::GOT_SnowPatch, 0, 9, Direction::Down },
                },
                SceneType::MultiLevel, 20, -1
            };
        case 23:
            return { //Stage 20 sub
                "",
                0, 0,
                Direction::Down,
                {
                    { GameObjectType::GOT_IceRock, 10, -9, Direction::Down },
                    { GameObjectType::GOT_IceRock, -8, -7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 2, -5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -10, -3, Direction::Down },
                    { GameObjectType::GOT_IceRock, -4, 1, Direction::Down },
                    { GameObjectType::GOT_IceRock, 4, 5, Direction::Down },
                    { GameObjectType::GOT_IceRock, -14, 7, Direction::Down },
                    { GameObjectType::GOT_IceRock, 12, 9, Direction::Down },
                    { GameObjectType::GOT_StairsUp, -10, -5, Direction::Up },
                    { GameObjectType::GOT_StairsUp, 10, -1, Direction::Up },
                },
                SceneType::MultiLevel, 20, -1
            };
        default:
            return SceneInfo();
    }
}

static EventSceneInfo getEventDetails(int sceneIndex)
{
    switch (sceneIndex)
    {
        case 0:
            return {
                "Use D-Pad to move character"
            };
        case 1:
            return {
                "Press A to destroy certain objects"
            };
        case 6:
            return {
                "I wonder how deep this cave goes..."
            };
        case 8:
            return {
                "Be on the lookout for cracked walls"
            };
        case 10:
            return {
                "I have to hurry..."
            };
        case 12:
            return {
                "That ice looks quite fragile..."
            };
        case 20:
            return {
                "I hope I can find it in time..."
            };
        default:
            return EventSceneInfo();
    }
}

static MultiSceneInfo getMultiLevelDetails(int sceneIndex)
{
    switch (sceneIndex)
    {
        case 16:
            return {
                0, { 16, 17 }
            };
        case 19:
            return {
                1, { 18, 19 }
            };
        case 22:
            return {
                1, { 21, 22, 23 }
            };
        default:
            return {};
    }
}

#endif // GAME_SCENES_H
