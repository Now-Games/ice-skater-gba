#include "destructible.h"
#include "bn_core.h"

void IDestructible::destroy()
{
    while (!destroyAnimation.done())
    {
        destroyAnimation.update();
        bn::core::update();
    }
}