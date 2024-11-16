#include "player.h"

#include "game_scene.h"
#include "game_constants.h"

#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_sprite_items_player_fall_sheet.h"

namespace is
{
    Player::Player(GameScene& gs) : 
        SpriteGameObject(gs, bn::sprite_items::player_sheet, bn::point(0, 0)),
        currentDirection(Direction::Down),
        fallAnim(bn::create_sprite_animate_action_once(sprite, 4, 
                       bn::sprite_items::player_fall_sheet.tiles_item(), 
                       1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17))
    {
        sprite.set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(currentDirection));
        sprite.set_z_order(PLAYER_LAYER);

        collider = bn::rect(position.x(), position.y(), 16, 16);
    }

    void Player::update()
    {
        //only allow input if the player is not moving
        if (!isMoving)
        {
            getInput();
            if (!isMoving)
                return;
        }

        
        GameObject *hit = scene.checkCollisions(getCollider());
        if (hit != nullptr)
        {
            BN_LOG("Collision with a game object");
            //if the object is transparent, continue moving right through it
            if (hit->getTransparency() == Transparency::Transparent)
            {
                move();
                return;
            }
            else if (hit->getTransparency() == Transparency::Translucent)
            {
                if (position == hit->getPosition())
                    isMoving = false;
                else
                    move();
            }
            else
            {
                isMoving = false;
            }
        }
        else {
            move();
        }
    }

    void Player::getInput()
    {
        if (bn::keypad::up_held())
        {
            isMoving = true;
            currentDirection = Direction::Up;
        }
        else if (bn::keypad::left_held())
        {
            isMoving = true;
            currentDirection = Direction::Left;
        }
        else if (bn::keypad::right_held())
        {
            isMoving = true;
            currentDirection = Direction::Right;
        }
        else if (bn::keypad::down_held())
        {
            isMoving = true;
            currentDirection = Direction::Down;
        }

        if (bn::keypad::a_pressed())
        {
            //interact with the object infront of the player
            bn::rect colliderAhead = bn::rect(collider.position(), collider.dimensions());
            switch (currentDirection)
            {
                case Down:
                    colliderAhead.set_y(colliderAhead.position().y() + 16);
                    break;
                case Right:
                    colliderAhead.set_x(colliderAhead.position().x() + 16);
                    break;
                case Left:
                    colliderAhead.set_x(colliderAhead.position().x() - 16);
                    break;
                case Up:
                    colliderAhead.set_y(colliderAhead.position().y() - 16);
                    break;
                default:
                    break;
            }
            
            GameObject *object = scene.checkCollisions(colliderAhead);
            if (object != nullptr)
            {
                //interact with the object
                object->interact();
            }
        }
    }
    
    void Player::move()
    {
        bn::point direction;
        switch (currentDirection)
        {
            case Down:
                direction = bn::point(0, 1);
                break;
            case Left:
                direction = bn::point(-1, 0);
                break;
            case Right:
                direction = bn::point(1, 0);
                break;
            case Up:
                direction = bn::point(0, -1);
                break;
            default:
                break;
        }

        setPosition(position + (direction * moveSpeed));
    }
}