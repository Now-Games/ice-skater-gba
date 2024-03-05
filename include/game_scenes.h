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
                bn::fixed_point(0, 5),
                Direction::Up,
                { 
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 5), Direction::Down },
                },
                SceneType::Event, -1, 1
            };
        case 1:
            return { //Tutorial 2
                "B2",
                bn::fixed_point(0, 5),
                Direction::Up,
                {
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 5), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(0, 0), Direction::Down },
                },
                SceneType::Event, 0, 2
            };
        case 2:
            return { //Stage 1
                "B3",
                bn::fixed_point(0, 9),
                Direction::Up,
                {
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, 0), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -7), Direction::Down },
                },
                SceneType::Basic, 1, 3
            };
        case 3:
            return { //Stage 2
                "B4",
                bn::fixed_point(0, 9),
                Direction::Up,
                {
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(-8, -9), Direction::Down }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 2), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(6, 0), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, -7), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-8, -5), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                },
                SceneType::Basic, 2, 4
            };
        case 4:
            return { //Stage 3
                "B5",
                bn::fixed_point(14, 5),
                Direction::Left,
                {
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -7), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -5), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 3), Direction::Right },
                    { ObstacleType::RockHole, bn::fixed_point(-14, -3), Direction::Right }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(-14, 5), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 7), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 9), Direction::Right },
                    { ObstacleType::IceRock, bn::fixed_point(-12, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, 5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(10, -7), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-10, -1), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-10, -5), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-12, -3), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(14, 5), Direction::Down },
                },
                SceneType::Basic, 3, 5
            };
        case 5:
            return { //Stage 4
                "B6",
                bn::fixed_point(-8, 9),
                Direction::Up,
                {
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(-4, -9), Direction::Down }, //Exit
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down }, 
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -5), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(-14, 1), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(-6, -7), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(-2, -7), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(-2, -3), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(-6, 7), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(0, 9), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(6, 1), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(12, -7), Direction::Down},
                    { ObstacleType::IceRock, bn::fixed_point(14, -3), Direction::Down},
                    { ObstacleType::Snowball, bn::fixed_point(-4, -5), Direction::Down},
                    { ObstacleType::SnowPatch, bn::fixed_point(-8, 9), Direction::Down}
                },
                SceneType::Basic, 4, 6
            };
        case 6:
            return     { //Stage 5
                "B7",
                bn::fixed_point(0, 5),
                Direction::Up,
                {
                  { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                  { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down }, //Exit
                  { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(4, 3), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-4, 3), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(4, -1), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-4, -1), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(4, -5), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-4, -5), Direction::Down },
                  { ObstacleType::SnowPatch, bn::fixed_point(0, 5),  Direction::Down },
                },
                SceneType::Event, 5, 7
            };
        case 7:
            return { //Stage 6
                "B8",
                bn::fixed_point(14, 3),
                Direction::Up,
                {
                  { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-2, -7), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(2, -7), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(4, -7), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-2, -3), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-10, -5), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-12, 5), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-8, 1), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(0, 3), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(12, 9), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(10, -5), Direction::Down },
                  { ObstacleType::Snowball, bn::fixed_point(0, -5), Direction::Down },
                  { ObstacleType::Snowball, bn::fixed_point(4, -1), Direction::Down },
                  { ObstacleType::Snowball, bn::fixed_point(-4, 9), Direction::Down },
                  { ObstacleType::SnowPatch, bn::fixed_point(14, 3), Direction::Down },
                },
                SceneType::Basic, 6, 8
            };
        case 8:
            return { //Stage 7
                "B9",
                bn::fixed_point(0, 5),
                Direction::Up,
                {
                  { ObstacleType::RockHole, bn::fixed_point(-8, -9), Direction::Down },
                  { ObstacleType::RockHole, bn::fixed_point(8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(14, -9),Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(-10, -7), Direction::Down },
                  { ObstacleType::IceRock, bn::fixed_point(8, -7), Direction::Down },
                  { ObstacleType::CrackedWall, bn::fixed_point(-8, -9), Direction::Down },
                  { ObstacleType::SnowPatch, bn::fixed_point(0, 5), Direction::Down }
                },
                SceneType::Event, 7, 9
            };
        case 9:
            return { //Stage 8
                "B10",
                bn::fixed_point(-2, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockHole, bn::fixed_point(8, -9), Direction::Down},
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-12, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(6, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, 1), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(8, -7), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-2, -1), Direction::Down },
                    { ObstacleType::CrackedWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(-2, 9), Direction::Down }
                },
                SceneType::Basic, 8, 10
            };
        case 10:
            return { //Stage 9
                "B11",
                bn::fixed_point(0, 5),
                Direction::Up,
                {
                  { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                  { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                  { ObstacleType::CrackedWall, bn::fixed_point(0, -9), Direction::Down },
                  { ObstacleType::SnowPatch, bn::fixed_point(0, 5), Direction::Down }
                },
                SceneType::Event, 9, 11
            };
        case 11:
            return { //Stage 10
                "B12",
                bn::fixed_point(2, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::CrackedWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-4, -7), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(0, -7), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(10, -5), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-8, -3), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-2, -3), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(4, -1), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-2, 1), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-10, 3), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-2, 3), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-4, 5), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(10, 5), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-10, 9), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(-4, 9), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(14, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, 5), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(2, 9), Direction::Down }
                },
                SceneType::Basic, 10, 12
            };
        case 12:
            return { //Stage 11
                "B13",
                bn::fixed_point(14, -1),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(-14, 5), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9),Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -7),Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -5),Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -3),Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 3), Direction::Right },
                    { ObstacleType::CrackedIce, bn::fixed_point(-12, -1), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(14, -1), Direction::Down }
                },
                SceneType::Event, 11, 13
            };
        case 13:
            return { //Stage 12
                "B14",
                bn::fixed_point(14, -9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(-14, -1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -7), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -5), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -3), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 1), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 3), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 5), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 7), Direction::Right },
                    { ObstacleType::RockWall, bn::fixed_point(-14, 9), Direction::Right },
                    { ObstacleType::CrackedWall, bn::fixed_point(-14, 1), Direction::Right },
                    { ObstacleType::CrackedWall, bn::fixed_point(-14, -1), Direction::Right },
                    { ObstacleType::IceRock, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, 3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-12, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, 9), Direction::Down },
                    { ObstacleType::CrackedIce, bn::fixed_point(-12, 1), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(14, -9), Direction::Down }
                },
                SceneType::Basic, 12, 14
            };
        case 14:
            return { //Stage 13
                "B15",
                bn::fixed_point(0, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9),Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-12, 3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(6, 1), Direction::Down },
                    { ObstacleType::CrackedIce, bn::fixed_point(-4, 3), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                },
                SceneType::Basic, 13, 15
            };
        case 15:
            return { //Stage 14
                "B16",
                bn::fixed_point(0, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::CrackedWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, -1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-12, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(14, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, 3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, 5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 9), Direction::Down },
                    { ObstacleType::CrackedIce, bn::fixed_point(-8, 5), Direction::Down },
                    { ObstacleType::CrackedIce, bn::fixed_point(8, 3), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                },
                SceneType::Basic, 14, 16
            };
        case 16:
            return { //Stage 15 Main
                "B17",
                bn::fixed_point(-8, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(14, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(6, 9), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(0, 1), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(12, -5), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(-8, 9), Direction::Down },
                },
                SceneType::MultiLevel, 15, 19
            };
        case 17:
            return { //Stage 15 sub
                "",
                bn::fixed_point(),
                Direction::Down,
                {
                    { ObstacleType::IceRock, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, 9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, 9), Direction::Down },
                    { ObstacleType::StairsUp, bn::fixed_point(0, 1), Direction::Up },
                    { ObstacleType::StairsUp, bn::fixed_point(12, -5), Direction::Up },
                },
                SceneType::MultiLevel, 15, -1
            };
        case 18:
            return { //Stage 16 Sub
                "",
                bn::fixed_point(0, 9),
                Direction::Up,
                {
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::CrackedWall, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(10, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(10, -1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, 5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-6, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 9), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(-10, -5), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(10, -5), Direction::Down },
                },
                SceneType::MultiLevel, 16, 20
            };
        case 19:
            return { //Stage 16 Main
                "B18",
                bn::fixed_point(0, 9),
                Direction::Down,
                {
                    { ObstacleType::IceRock, bn::fixed_point(0, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(14, 3), Direction::Down },
                    { ObstacleType::StairsUp, bn::fixed_point(-10, -5), Direction::Up },
                    { ObstacleType::StairsUp, bn::fixed_point(10, -5), Direction::Up },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                },
                SceneType::MultiLevel, 16, 20
            };
        case 20:
            return {
                "B19",
                bn::fixed_point(0, 5),
                Direction::Down,
                {
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, -1), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, -3), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, -5), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, -7), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 1), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 3), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 5), Direction::Down },
                },
                SceneType::Event, 18, 22
            };
        case 21:
            return { //Stage 20 sub
                "",
                bn::fixed_point(0, 9),
                Direction::Down,
                {
                    { ObstacleType::IceRock, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, -1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(14, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(6, 3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(10, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 9), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(0, -3), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(-10, -1), Direction::Down },
                    { ObstacleType::Snowball, bn::fixed_point(0, -3), Direction::Down },
                },
                SceneType::MultiLevel, 20, -1
            };
        case 22:
            return { //Stage 20 Main
                "B20",
                bn::fixed_point(0, 9),
                Direction::Down,
                {
                    { ObstacleType::RockHole, bn::fixed_point(0, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-14, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(-2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(2, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(4, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(6, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(8, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(12, -9), Direction::Down },
                    { ObstacleType::RockWall, bn::fixed_point(14, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-12, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-2, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(0, -1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(8, 1), Direction::Down },
                    { ObstacleType::StairsDown, bn::fixed_point(-10, -5), Direction::Down },
                    { ObstacleType::StairsUp, bn::fixed_point(0, -3), Direction::Up },
                    { ObstacleType::StairsUp, bn::fixed_point(-10, -1), Direction::Up },
                    { ObstacleType::StairsDown, bn::fixed_point(10, -1), Direction::Down },
                    { ObstacleType::SnowPatch, bn::fixed_point(0, 9), Direction::Down },
                },
                SceneType::MultiLevel, 20, -1
            };
        case 23:
            return { //Stage 20 sub
                "",
                bn::fixed_point(),
                Direction::Down,
                {
                    { ObstacleType::IceRock, bn::fixed_point(10, -9), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-8, -7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(2, -5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-10, -3), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-4, 1), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(4, 5), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(-14, 7), Direction::Down },
                    { ObstacleType::IceRock, bn::fixed_point(12, 9), Direction::Down },
                    { ObstacleType::StairsUp, bn::fixed_point(-10, -5), Direction::Up },
                    { ObstacleType::StairsUp, bn::fixed_point(10, -1), Direction::Up },
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
