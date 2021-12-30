#include "helper_extensions.h"

namespace is {

game_scene helper::cast_to_scene(int num)
{
    game_scene scene = static_cast<game_scene>(num);
    if (scene < CREDITS)
        return scene;
    else
        return MAIN_MENU;
}

scene_details helper::get_scene_details(game_scene current_scene)
{
    switch (current_scene) {
    case TUTORIAL_SCENE:
    {
        return {
            bn::fixed_point(0, 40),
            direction::UP,
            true,
            "Press D-Pad to move character",
            {
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, 40), obstacle_type::SNOW }
            }
        };
    }
    case TUTORIAL_SCENE_2:
    {
        return {
            bn::fixed_point(0, 40),
            direction::UP,
            true,
            "Press A to destroy certain objects",
            {
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, 0), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(0, 40), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_ONE:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            false,
            "",
            {
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, 0), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_TWO:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            false,
            "",
            {
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-112, 16), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(48, 0), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, -40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(0, 72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_THREE:
    {
        return {
            bn::fixed_point(112, 40),
            direction::LEFT,
            false,
            "",
            {
                { true, bn::fixed_point(-112, -24), obstacle_type::ROCK_WALL_HOLE, RIGHT },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, -56), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, -40), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, -8), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, 8), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, 24), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, 40), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, 56), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-112, 72), obstacle_type::ROCK_WALL, RIGHT },
                { true, bn::fixed_point(-96, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, -72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, 40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(80, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, -24), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-80, -40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-80, -8), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(112, 40), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_FOUR:
    {
        return {
            bn::fixed_point(-64, 72),
            direction::UP,
            false,
            "",
            {
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-112, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(48, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(112, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, -40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-64, 72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_FIVE:
    {
        return {
            bn::fixed_point(0, 40),
            direction::UP,
            true,
            "I wonder how deep this cave goes...",
            {
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, -8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 40), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_SIX:
    {
        return {
            bn::fixed_point(112, 24),
            direction::LEFT,
            false,
            "",
            {
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(80, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, -40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(32, -8), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-32, 72), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(112, 24), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_SEVEN:
    {
        return {
            bn::fixed_point(0, 40),
            direction::UP,
            true,
            "Be on the lookout for cracked walls",
            {
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(0, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(32, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-80, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(0, 40), obstacle_type::SNOW }
            }
        };
    }
    default:
        return scene_details();
    }
}

bn::sprite_item helper::get_sprite_item(obstacle_type type) {
    switch(type) {
    case ROCK_WALL:
        return bn::sprite_items::rock_wall;
    case SNOW:
        return bn::sprite_items::snow_tile;
    case SNOWBALL:
        return bn::sprite_items::snowball_sheet;
    case CRACKED_WALL:
        return bn::sprite_items::cracked_wall_sheet;
    case ROCK_WALL_HOLE:
        return bn::sprite_items::rock_wall_hole;
    case ICE_ROCK:
        return bn::sprite_items::ice_rock;
    default:
        return bn::sprite_items::rock_wall;
    }
}

bool helper::is_destructible(obstacle_type _type)
{
    switch (_type) {
    case SNOWBALL:
    case CRACKED_WALL:
    {
        return true;
    }
    default:
        return false;
    }
}

}
