#include "event_game_scene.h"

#include "bn_display.h"
#include "bn_log.h"
#include "bn_string.h"
#include "common_variable_8x16_sprite_font.h"

namespace is
{
    EventGameScene::EventGameScene(EventSceneDetails* details) : GameScene(details),
        eventTextGenerator(common::variable_8x16_sprite_font)
    {
        sceneBounds = bn::rect(0, -16, bn::display::width(), 128);

        eventTextGenerator.set_center_alignment();
        eventTextGenerator.set_one_sprite_per_character(false);

        bn::vector<bn::string<10>, 20> words;
        int wordStart = 0;
        int wordLength = 0;
        for (int i = 0; i < details->eventText.size(); i++)
        {
            wordLength++;
            if (details->eventText[i] == ' ' || i == details->eventText.size() - 1)
            {
                words.push_back(details->eventText.substr(wordStart, wordLength));
                wordStart = i + 1;
                wordLength = 0;
            }
        }

        bn::string<64> line = "";
        int lines = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int width = eventTextGenerator.width(line + " " + words[i]);
            if (width < bn::display::width() - 20)
            {
                line.append(" ").append(words[i]);
                BN_LOG("Line: ", line);
            }
            else
            {
                eventTextGenerator.generate(0, 56 + (lines * 12), line, eventTextSprites);
                line = words[i];
                lines++;
            }
            
            //end of the loop
            if (i >= words.size() - 1)
            {
                eventTextGenerator.generate(0, 56 + (lines * 12), line, eventTextSprites);
            }
        }
    }
}