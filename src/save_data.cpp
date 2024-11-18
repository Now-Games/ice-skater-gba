#include "save_data.h"

namespace is 
{
    SaveData saveData;

    void save()
    {
        bn::sram::write(saveData);
    }

    void load()
    {
        bn::array<char, 32> expectedFormatTag;

        bn::sram::read(saveData);
        bn::istring_base expectedFormatTagIstring(expectedFormatTag._data);
        bn::ostringstream expectedFormatTagStream(expectedFormatTagIstring);
        
        if (saveData.format != expectedFormatTag)
        {
            //clear the data saved in sram
            bn::sram::clear(bn::sram::size());
            saveData = SaveData();
        }
    }
}