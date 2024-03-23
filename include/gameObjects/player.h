#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "components/move_component.h"
#include "components/collider_component.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_unique_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "direction.h"

class Player : public GameObject
{
    private:
        bn::unique_ptr<MoveComponent> moveComponent;
        bn::optional<bn::sprite_animate_action<20>> fallAnim;
        
        void getInput();

    public:
        Player(Scene *scene, bn::fixed_point pos, Direction dir);
        ~Player() = default;
        void setDirection(Direction newDir) override;
        void update() override;
        void playFallingAnimation();
};

#endif // PLAYER_H
