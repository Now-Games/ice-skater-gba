#include "components/destructible_component.h"
#include "bn_core.h"
#include "gameObjects/game_object.h"

DestructibleComponent::DestructibleComponent(GameObject *p, bn::sprite_item spritesheet) : 
    BaseComponent(p),
    destroyAnimation(bn::create_sprite_animate_action_once(p->getSprite(), 7, spritesheet.tiles_item(), 1, 2, 3, 4, 5))
{
    
}

void DestructibleComponent::destroy()
{
    while (!destroyAnimation->done())
    {
        destroyAnimation->update();
        bn::core::update();
    }
}