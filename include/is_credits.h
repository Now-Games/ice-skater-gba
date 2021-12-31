#ifndef IS_CREDITS_H
#define IS_CREDITS_H

#include "bn_core.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "is_game_scene.h"

#include "common_fixed_8x16_sprite_font.h"

namespace is
{

class credits
{
private:
    const int credits_size = 25;
    int current_index = 0;
    bn::sprite_text_generator text_generator;
    bn::vector<bn::sprite_ptr, 32> title_text_sprites;
    bn::vector<bn::sprite_ptr, 32> msg_text_sprites;
    bn::string<32> credit_screens[25] = {
        bn::string<32>("This game was made using the"),
        bn::string<32>("Butano Library"),
        bn::string<32>("located at:"),
        bn::string<32>("https://github.com/"),
        bn::string<32>("GValiente/butano"),
        bn::string<32>("I hope you enjoyed playing!"),
        bn::string<32>("This game is still"),
        bn::string<32>("currently under development"),
        bn::string<32>("so more updates are on"),
        bn::string<32>("the way!"),
        bn::string<32>("More challenging"),
        bn::string<32>("puzzles await!"),
        bn::string<32>(""),
        bn::string<32>(""),
        bn::string<32>(""),
        bn::string<32>(""),
        bn::string<32>("Programming: Jonathan Loppnow"),
        bn::string<32>("Art: Jonathan Loppnow"),
        bn::string<32>("Lvl Design: Jonathan Loppnow"),
        bn::string<32>("Music: ModArchive.org"),
        bn::string<32>(""),
        bn::string<32>(""),
        bn::string<32>("Thank you for playing! :)"),
        bn::string<32>(""),
        bn::string<32>("")
    };

public:
    credits();
    ~credits();
    game_scene update();
};

}

#endif // IS_CREDITS_H
