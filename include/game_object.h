#pragma once

#include "direction.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"

class GameObject
{
    protected:
        GameObjectType type = GameObjectType::GOT_None;
        bn::fixed_point position;
        Direction direction = Direction::Down;
        bn::optional<bn::sprite_ptr> sprite;
        bool active = true;
        bool enabled = true;

    public:
        GameObject(bn::fixed_point pos);
        GameObject(bn::fixed_point pos, bn::sprite_item sprite);
        virtual ~GameObject() = default;
        bn::fixed_point getPosition();
        Direction getDirection();
        GameObjectType getObjectType();
        bool isEnabled();
        bool isActive();
        void setEnabled(bool e);
        void setActive(bool a);
        virtual void setPosition(bn::fixed_point newPos);
        virtual void setDirection(Direction newDir);
        virtual void update();
};

enum GameObjectType
{
    GOT_None,
    GOT_Player,
    GOT_IceRock,
    GOT_RockWall,
    GOT_RockHole,
    GOT_CrackedIce,
    GOT_Snowball,
    GOT_SnowPatch,
    GOT_StairsUp,
    GOT_StairsDown,
    GOT_Shuriken
};