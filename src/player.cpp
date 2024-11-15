#include "player.h"

#include "bn_keypad.h"
#include "game_scene.h"

namespace is
{
    Player::Player(GameScene& gs) : GameObject(gs, bn::point(0, 0))
    {
        currentDirection = Direction::Down;
        collider = bn::rect(position.x(), position.y(), 16, 16);
    }

    void Player::update()
    {
        getInput();
        if (!isMoving)
            return;

        if (scene.checkCollisions(getCollider()) != nullptr)
        {
            isMoving = false;
        }
        else {
            move();
        }
    }

    void Player::getInput()
    {
        if (bn::keypad::up_pressed())
        {
            isMoving = true;
            currentDirection = Direction::Up;
        }
        else if (bn::keypad::left_pressed())
        {
            isMoving = true;
            currentDirection = Direction::Left;
        }
        else if (bn::keypad::right_pressed())
        {
            isMoving = true;
            currentDirection = Direction::Right;
        }
        else if (bn::keypad::down_pressed())
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

        position += direction * moveSpeed;
    }
}