#ifndef UTILS_H
#define UTILS_H

#include "bn_fixed_point.h"
#include "bn_math.h"

class utils
{
    public:
        static int getDistance(bn::fixed_point a, bn::fixed_point b)
        {
            bn::fixed dx = a.x() - b.x();            
        }
};

#endif // UTILS_H
