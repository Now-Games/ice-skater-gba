#ifndef PLAYER_H
#define PLAYER_H

#include "scene.h"
#include "game_object.h"
#include "move_component.h"
#include "collider_component.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_unique_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "direction.h"

class Player : public GameObject
{
    private:
        bn::unique_ptr<Scene> currentScene;
        MoveComponent moveComponent;
        ColliderComponent colliderComponent;
        bn::optional<bn::sprite_animate_action<20>> fallAnim;
        
        void getInput();

    public:
        Player(Scene *scene, bn::fixed_point pos, Direction dir);
        ~Player() = default;
        MoveComponent* getMoveComponent();
        ColliderComponent* getColliderComponent();
        void setDirection(Direction newDir) override;
        void update() override;
        void playFallingAnimation();
};

#endif // PLAYER_H
