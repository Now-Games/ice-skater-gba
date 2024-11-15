#pragma once

#include "bn_array.h"
#include "bn_sram.h"

namespace is
{
    struct SaveData
    {
        bn::array<char, 32> format;
        int furthestScene = 0;
        int currentScene = 0;
    };    
    
    static SaveData SAVE_DATA;

    static void saveData()
    {
        bn::sram::write(SAVE_DATA);
    }

    static void loadData()
    {
        bn::array<char, 32> expectedFormatTag;

        bn::sram::read(SAVE_DATA);
        bn::istring_base expectedFormatTagIstring(expectedFormatTag._data);
        bn::ostringstream expectedFormatTagStream(expectedFormatTagIstring);
        
        if (SAVE_DATA.format != expectedFormatTag)
        {
            //clear the data saved in sram
            bn::sram::clear(bn::sram::size());
            SAVE_DATA = SaveData();
        }
        }
}