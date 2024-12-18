#include "shuriken_game_object.h"

#include "save_data.h"
#include "player.h"
#include "game_scene.h"
#include "game_constants.h"

#include "bn_sprite_items_shuriken.h"

namespace is
{
    ShurikenGameObject::ShurikenGameObject(GameScene& gs, bn::point pos, Direction dir) : 
        SpriteGameObject(gs, bn::sprite_items::shuriken, pos)
    {
        direction = dir;
        triggered = false;
        nextPosition = pos;
    }

    SceneUpdateResult ShurikenGameObject::update()
    {
        if (triggered)
            return SceneUpdateResult(true);

        bn::fixed angle = sprite.rotation_angle() + bn::fixed(ROTATE_SPEED);
        if (angle > 360)
            angle -= 360;
        sprite.set_rotation_angle(angle);

        Player *playerHit = scene.checkPlayerCollision(getCollider());
        if (playerHit != nullptr) {
            interact(*playerHit);
            return SceneUpdateResult();
        }

        bool canMove = true;
        if (position == nextPosition)
            canMove = checkMoveAhead();
            
        if (canMove)
            move();
        else
            changeDirection();

        return SceneUpdateResult();
    }

    bool ShurikenGameObject::checkMoveAhead()
    {
        bool canMove = false;
        bn::rect colliderAhead = getColliderAhead();
        
        //Check if collider is out of bounds
        if (colliderAhead.left() < scene.getSceneBounds().left() ||
            colliderAhead.right() > scene.getSceneBounds().right() ||
            colliderAhead.top() < scene.getSceneBounds().top() ||
            colliderAhead.bottom() > scene.getSceneBounds().bottom())
        {
            BN_LOG("Shuriken is moving out of bounds");
            return canMove;
        }

        GameObject *hit = scene.checkCollisions(colliderAhead);
        if (hit == nullptr)
        {
            canMove = true;
            nextPosition = colliderAhead.position();

            BN_LOG("Shuriken Hit is null");
        }
        else
        {
            if (hit->getTransparency() == Transparency::Opaque)
            {
                BN_LOG("Shuriken Hit is Opaque");
                canMove = false;
            }
            else 
            {
                canMove = true;
                nextPosition = colliderAhead.position();
                BN_LOG("Shuriken Hit is Transparent or Translucent");
            }
        }

        return canMove;
    }

    void ShurikenGameObject::interact(Player& player)
    {
        player.dead();
        triggered = true;
    }
    
    bn::rect ShurikenGameObject::getColliderAhead()
    {
        bn::rect colliderAhead = getCollider();
        switch (direction)
        {
            case Direction::Up:
                colliderAhead.set_y(colliderAhead.y() - TILE_SIZE);
                break;
            case Direction::Down:
                colliderAhead.set_y(colliderAhead.y() + TILE_SIZE);
                break;
            case Direction::Left:
                colliderAhead.set_x(colliderAhead.x() - TILE_SIZE);
                break;
            case Direction::Right:
                colliderAhead.set_x(colliderAhead.x() + TILE_SIZE);
                break;
            default:
                break;
        }

        return colliderAhead;
    }
    
    void ShurikenGameObject::changeDirection()
    {
        switch (direction)
        {
            case Direction::Up:
                direction = Direction::Down;
                break;
            case Direction::Down:
                direction = Direction::Up;
                break;
            case Direction::Left:
                direction = Direction::Right;
                break;
            case Direction::Right:
                direction = Direction::Left;
                break;
            default:
                break;
        }
    }
    
    void ShurikenGameObject::move()
    {
        bn::point newPosition = bn::point(position.x(), position.y());

        switch (direction)
        {
            case Direction::Down:
                newPosition.set_y(newPosition.y() + MOVE_SPEED);
                break;
            case Direction::Left:
                newPosition.set_x(newPosition.x() - MOVE_SPEED);
                break;
            case Direction::Right:
                newPosition.set_x(newPosition.x() + MOVE_SPEED);
                break;
            case Direction::Up:
                newPosition.set_y(newPosition.y() - MOVE_SPEED);
                break;
            default:
                break;
        }

        setPosition(newPosition);
    }
}