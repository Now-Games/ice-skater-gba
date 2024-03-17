#pragma once

#include "game_object.h"
#include "destructible.h"

class CrackedIce : public GameObject, public IDestructible
{
    public:
        CrackedIce(bn::fixed_point pos);
        ~CrackedIce() = default;
        void update() override;
};