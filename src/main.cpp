#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_color.h"

#include "game.h"

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    is::Game game = is::Game();

    while(true)
    {
        game.update();
        bn::core::update();
    }
}