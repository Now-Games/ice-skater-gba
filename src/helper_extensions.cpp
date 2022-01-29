#include "helper_extensions.h"

namespace is {

game_scene helper::cast_to_scene(int num)
{
    game_scene scene = static_cast<game_scene>(num);
    if (scene <= CREDITS)
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
            EVENT,
            "Use D-Pad to move character",
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
            EVENT,
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
            NORMAL,
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
            NORMAL,
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
            NORMAL,
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
            NORMAL,
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
            EVENT,
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
            NORMAL,
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
            EVENT,
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
    case STAGE_EIGHT:
    {
        return {
            bn::fixed_point(-16, 72),
            direction::UP,
            NORMAL,
            "",
            {
                { true, bn::fixed_point(-32, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL_HOLE },
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
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(48, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, -56), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-16, -8), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-32, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(-16, 72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_NINE:
    {
        return {
            bn::fixed_point(0, 40),
            direction::UP,
            EVENT,
            "I have to hurry...",
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
                { true, bn::fixed_point(0, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(0, 40), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_TEN:
    {
        return {
            bn::fixed_point(16, 72),
            direction::UP,
            NORMAL,
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
                { true, bn::fixed_point(64, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(48, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(-32, -56), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(0, -56), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(80, -40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-64, -24), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-16, -24), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(32, -8), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-16, 8), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-80, 24), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-16, 24), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-32, 40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(80, 40), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-80, 72), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(-32, 72), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(112, 72), obstacle_type::SNOWBALL },
                { true, bn::fixed_point(16, 40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, 72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_ELEVEN:
    {
        return {
            bn::fixed_point(112, -8),
            direction::LEFT,
            EVENT,
            "That ice looks quite fragile...",
            {
                { true, bn::fixed_point(-112, -8), obstacle_type::ROCK_WALL_HOLE, direction::RIGHT },
                { true, bn::fixed_point(-112, 40), obstacle_type::ROCK_WALL_HOLE, direction::RIGHT },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -56), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -40), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -24), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 8), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 24), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-96, -8), obstacle_type::CRACKED_ICE },
                { true, bn::fixed_point(112, -8), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_TWELVE:
    {
        return {
            bn::fixed_point(112, -72),
            direction::DOWN,
            NORMAL,
            "",
            {
                { true, bn::fixed_point(-112, -8), obstacle_type::ROCK_WALL_HOLE, direction::RIGHT },
                { true, bn::fixed_point(-112, -72), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -56), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -40), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -24), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 8), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 24), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 40), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 56), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 72), obstacle_type::ROCK_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, 8), obstacle_type::CRACKED_WALL, direction::RIGHT },
                { true, bn::fixed_point(-112, -8), obstacle_type::CRACKED_WALL, direction::RIGHT },
                { true, bn::fixed_point(48, -72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, -72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 8), obstacle_type::CRACKED_ICE },
                { true, bn::fixed_point(112, -72), obstacle_type::SNOW }
            }
        };
    }
    case STAGE_THIRTEEN:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            NORMAL,
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
                { true, bn::fixed_point(-112, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(48, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, 24), obstacle_type::CRACKED_ICE },
                { true, bn::fixed_point(0, 72), obstacle_type::SNOW },
            }
        };
    }
    case STAGE_FOURTEEN:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            NORMAL,
            "",
            {
                { true, bn::fixed_point(-64, -72), obstacle_type::ROCK_WALL_HOLE },
                { true, bn::fixed_point(80, -72), obstacle_type::ROCK_WALL_HOLE },
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
                { true, bn::fixed_point(96, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(112, -72), obstacle_type::ROCK_WALL },
                { true, bn::fixed_point(-64, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(16, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, -8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-96, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(112, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, 40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-112, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, 40), obstacle_type::CRACKED_ICE },
                { true, bn::fixed_point(64, 24), obstacle_type::CRACKED_ICE },
                { true, bn::fixed_point(0, 72), obstacle_type::SNOW },
            }
        };
    }
    case STAGE_FIFTEEN:
    {
        return {
            bn::fixed_point(-64, 72),
            direction::UP,
            MULTILEVEL,
            "", {
                //Scene details are taken from the sublevels
            }
        };
    }
    case STAGE_SIXTEEN:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            MULTILEVEL,
            "", {
                //Scene details are taken from the sublevels
            }
        };
    }
    default:
        return scene_details();
    }
}

sub_scene helper::get_sub_scene_main(game_scene scene)
{
    switch (scene)
    {
    case STAGE_FIFTEEN:
        return STAGE_FIFTEEN_M;
    case STAGE_SIXTEEN:
        return STAGE_SIXTEEN_M;
    default:
        break;
    }
}

scene_details helper::get_sub_scene_details(sub_scene current_scene)
{
    switch (current_scene) {
    case STAGE_FIFTEEN_M:
    {
        return {
            bn::fixed_point(-64, 72),
            direction::UP,
            MULTILEVEL,
            "", {
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
                { true, bn::fixed_point(-64, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(112, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(48, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 8), obstacle_type::STAIRS, DOWN },
                { true, bn::fixed_point(96, -40), obstacle_type::STAIRS, DOWN },
                { true, bn::fixed_point(-64, 72), obstacle_type::SNOW },
            }
        };
    }
    case STAGE_FIFTEEN_B1:
    {
        return {
            bn::fixed_point(-64, 72),
            direction::UP,
            MULTILEVEL,
            "", {
                { true, bn::fixed_point(0, -72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 8), obstacle_type::STAIRS, UP },
                { true, bn::fixed_point(96, -40), obstacle_type::STAIRS, UP },
            }
        };
    }
    case STAGE_SIXTEEN_1:
    {
        return {
            bn::fixed_point(0, 72),
            direction::UP,
            MULTILEVEL,
            "", {
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
                { true, bn::fixed_point(0, -72), obstacle_type::CRACKED_WALL },
                { true, bn::fixed_point(80, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(16, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-16, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(96, -24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(80, -8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(0, 40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-48, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, 56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-112, 72), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -40), obstacle_type::STAIRS, DOWN },
                { true, bn::fixed_point(80, -40), obstacle_type::STAIRS, DOWN },
            }
        };
    }
    case STAGE_SIXTEEN_M:
    {
        return {
            bn::fixed_point(0,72),
            direction::UP,
            MULTILEVEL,
            "", {
                { true, bn::fixed_point(0, -56), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(32, -40), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-64, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(64, 8), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-112, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(112, 24), obstacle_type::ICE_ROCK },
                { true, bn::fixed_point(-80, -40), obstacle_type::STAIRS, UP },
                { true, bn::fixed_point(80, -40), obstacle_type::STAIRS, UP },
                { true, bn::fixed_point(0, 72), obstacle_type::SNOW },
            }
        };
    }
    default:
        break;
    }

    return scene_details();
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
    case CRACKED_ICE:
        return bn::sprite_items::cracked_ice_sheet;
    case ROCK_WALL_HOLE:
        return bn::sprite_items::rock_wall_hole;
    case ICE_ROCK:
        return bn::sprite_items::ice_rock;
    case STAIRS:
        return bn::sprite_items::stairs_sheet;
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
