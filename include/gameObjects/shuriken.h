#pragma once

#include "game_object.h"
#include "components/move_component.h"
#include "bn_unique_ptr.h"
#include "scene.h"

class Shuriken : public GameObject
{
    private:
        bn::unique_ptr<MoveComponent> moveComponent;

        void changeDirection();

    public:
        Shuriken(Scene* scene, bn::fixed_point, bn::sprite_item);
        ~Shuriken() = default;
        void update() override;
};