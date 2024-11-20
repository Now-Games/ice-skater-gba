#include "player.h"

#include "game_scene.h"
#include "game_constants.h"

#include "bn_display.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_core.h"
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
        sprite.set_z_order(PLAYER_SPRITE_Z);
        sprite.set_bg_priority(SCENE_BACKGROUND_LAYER);

        nextPosition = bn::point(position.x(), position.y());
        collider = bn::rect(position.x(), position.y(), 16, 16);
    }

    void Player::setDirection(Direction newDir)
    {
        if (currentDirection == newDir)
            return;

        currentDirection = newDir;
        sprite.set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(currentDirection));
    }

    SceneUpdateResult Player::update()
    {
        if (!isMoving) 
        {
            if (bn::keypad::up_held())
            {
                setDirection(Direction::Up);
                checkMoveAhead();
            }
            else if (bn::keypad::down_held())
            {
                setDirection(Direction::Down);
                checkMoveAhead();
            }
            else if (bn::keypad::left_held())
            {
                setDirection(Direction::Left);
                checkMoveAhead();
            }
            else if (bn::keypad::right_held())
            {
                setDirection(Direction::Right);
                checkMoveAhead();
            }
            else if (bn::keypad::a_pressed())
            {
                //interact with the object infront of the player
                GameObject *object = scene.checkCollisions(getColliderAhead());
                if (object != nullptr)
                {
                    //interact with the object
                    object->interact(*this);
                }
            }
        }
        else
        {
            move();
            
            if (position == nextPosition)
            {
                GameObject *hit = scene.checkCollisions(getCollider());
                if (hit->getTransparency() == Transparency::Translucent) 
                {
                    isMoving = false;
                    hit->interact(*this);
                }
                else
                    checkMoveAhead();
            }
        }

        return SceneUpdateResult();
    }

    void Player::checkMoveAhead()
    {
        bn::rect colliderAhead = getColliderAhead();
        //Check if collider is out of bounds
        if (colliderAhead.left() < scene.getSceneBounds().left() ||
            colliderAhead.right() > scene.getSceneBounds().right() ||
            colliderAhead.top() < scene.getSceneBounds().top() ||
            colliderAhead.bottom() > scene.getSceneBounds().bottom())
        {
            BN_LOG("Moving out of bounds");
            isMoving = false;
            return;
        }

        GameObject *hit = scene.checkCollisions(colliderAhead);
        if (hit == nullptr)
        {
            isMoving = true;
            nextPosition = colliderAhead.position();

            BN_LOG("Hit is null");
        }
        else
        {
            if (hit->getTransparency() == Transparency::Translucent || 
                hit->getTransparency() == Transparency::Transparent)
            {
                isMoving = true;
                nextPosition = colliderAhead.position();
                BN_LOG("Hit is Transparent or Translucent");
            }
            else 
            {
                isMoving = false;
                BN_LOG("Hit is Opaque");
            }
        }
    }
    
    bn::rect Player::getColliderAhead()
    {
        bn::rect colliderAhead = bn::rect(collider.position(), collider.dimensions());
        switch (currentDirection)
        {
            case Down:
                colliderAhead.set_y(colliderAhead.position().y() + TILE_SIZE);
                break;
            case Right:
                colliderAhead.set_x(colliderAhead.position().x() + TILE_SIZE);
                break;
            case Left:
                colliderAhead.set_x(colliderAhead.position().x() - TILE_SIZE);
                break;
            case Up:
                colliderAhead.set_y(colliderAhead.position().y() - TILE_SIZE);
                break;
            default:
                break;
        }
        
        return colliderAhead;
    }

    void Player::move()
    {
        bn::point newPosition = bn::point(position.x(), position.y());

        switch (currentDirection)
        {
            case Down:
                newPosition.set_y(newPosition.y() + PLAYER_MOVE_SPEED);
                break;
            case Left:
                newPosition.set_x(newPosition.x() - PLAYER_MOVE_SPEED);
                break;
            case Right:
                newPosition.set_x(newPosition.x() + PLAYER_MOVE_SPEED);
                break;
            case Up:
                newPosition.set_y(newPosition.y() - PLAYER_MOVE_SPEED);
                break;
            default:
                break;
        }

        setPosition(newPosition);
    }
    
    void Player::fall()
    {
        while (!fallAnim.done())
        {
            fallAnim.update();
            bn::core::update();
        }
    }
}