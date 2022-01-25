#include "is_scene.h"

namespace is {
scene::scene(game_scene _current_scene, scene_details details) :
    text_generator(bn::sprite_text_generator(common::variable_8x16_sprite_font))
{
    _scene = _current_scene;
    scene_paused = false;
    bounds_min_x = -(bn::display::width() / 2) + 8;
    bounds_max_x = (bn::display::width() / 2) - 8;
    bounds_min_y = -(bn::display::height() / 2 + 8);

    BN_LOG("Bounds Set");

    load_scene_bg(details._type, details.event_message);
    load_scene_objects(details);

    _player = player(details._player_pos.x(), details._player_pos.y(), details._player_dir);
}

void scene::load_scene_bg(scene_type _type, bn::string<64> message)
{
    if (_type == EVENT) {
        bounds_max_y = (bn::display::height() / 2) - 40;

        text_generator.set_center_alignment();
        text_generator.generate(0, bounds_max_y + 26, message, text_sprites);

        _bg = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
    }
    else {
        bounds_max_y = (bn::display::height() / 2) - 8;
        _bg = bn::regular_bg_items::stage_scene.create_bg(0, 0);
    }
    _bg->set_z_order(6);

    BN_LOG("Background and text set");
}

void scene::load_scene_objects(scene_details details)
{
    bn::vector<obstacle, 32> temp;
    if (map_objects.size() > 0)
        temp = std::move(map_objects);

    int size = sizeof(details.obstacles) / sizeof(details.obstacles[0]);
    for (int i = 0; i < size; i ++) {
        if (details.obstacles[i].exists) {
            bool destructible = helper::is_destructible(details.obstacles[i]._type);

            map_objects.push_back(obstacle(details.obstacles[i]._pos,
                                           details.obstacles[i]._type, destructible,
                                           details.obstacles[i]._direction));
        }
    }
    BN_LOG("Generated Objects");
}

scene::~scene() {

}

void scene::destroy_obstacle(bn::fixed dx, bn::fixed dy)
{
    for (int i = 0; i < map_objects.size(); i ++) {
        if (map_objects[i].can_destroy()) {
            //is object close to player
            if (map_objects[i].get_position().x() == _player->get_position().x() + dx &&
                    map_objects[i].get_position().y() == _player->get_position().y() + dy) {
                map_objects[i].set_destroy();
                break;
            }
        }
    }
}

int scene::get_next_scene()
{
    int current = static_cast<int>(_scene);
    current ++;
    BN_LOG("Current Scene is: ", current);
    return current;
}

void scene::get_input() {
    if (bn::keypad::start_pressed()) {
        //display pause display
        pause pause_display = pause();
        pause_display.update();
    }
    else if (bn::keypad::a_pressed()) {
        //destroy snowball
        switch(_player->get_direction()) {
        case LEFT:
            destroy_obstacle(-16, 0);
            break;
        case RIGHT:
            destroy_obstacle(16, 0);
            break;
        case UP:
            destroy_obstacle(0, -16);
            break;
        case DOWN:
            destroy_obstacle(0, 16);
            break;
        default:
            break;
        }
    }
}

void scene::get_closest_object() {
    bn::fixed_point player_point = _player->get_position();
    bn::fixed min_distance = 280;
    bn::fixed dist = 0;
    int index = -1;

    for (int i = 0; i < map_objects.size(); i ++) {
        if (!map_objects[i].get_destroyed()) {
            bn::fixed_point obj_point = map_objects[i].get_position();

            switch(_player->get_direction()) {
            case LEFT:
                dist = player_point.x() - obj_point.x();
                if (obj_point.y() == player_point.y() && obj_point.x() < player_point.x() &&
                        dist <= min_distance) {
                    index = i;
                    min_distance = dist;
                }
                break;
            case RIGHT:
                dist = obj_point.x() - player_point.x();
                if (obj_point.y() == player_point.y() && obj_point.x() > player_point.x() &&
                        dist <= min_distance) {
                    index = i;
                    min_distance = dist;
                }
                break;
            case UP:
                dist = player_point.y() - obj_point.y();
                if (obj_point.x() == player_point.x() && obj_point.y() < player_point.y() &&
                        dist <= min_distance) {
                    index = i;
                    min_distance = dist;
                }
                break;
            case DOWN:
                dist = obj_point.y() - player_point.y();
                if (obj_point.x() == player_point.x() && obj_point.y() > player_point.y() &&
                        dist <= min_distance) {
                    index = i;
                    min_distance = dist;
                }
                break;
            default:
                break;
            }
        }
    }

    closest_obstacle_index = index;
}

void scene::set_player_move_limit() {
    get_closest_object();
    switch(_player->get_direction()) {
    case LEFT:
        if (closest_obstacle_index != -1)
            _player->set_move_limit(
                        map_objects[closest_obstacle_index].get_collision_edge(_player->get_direction()),
                        _player->get_position().y());
        else
            _player->set_move_limit(bounds_min_x, _player->get_position().y());
        break;
    case RIGHT:
        if (closest_obstacle_index != -1)
            _player->set_move_limit(
                        map_objects[closest_obstacle_index].get_collision_edge(_player->get_direction()),
                        _player->get_position().y());
        else
            _player->set_move_limit(bounds_max_x, _player->get_position().y());
        break;
    case UP:
        if (closest_obstacle_index != -1)
            _player->set_move_limit(
                        _player->get_position().x(),
                        map_objects[closest_obstacle_index].get_collision_edge(_player->get_direction()));
        else
            _player->set_move_limit(_player->get_position().x(), bounds_min_y);
        break;
    case DOWN:
        if (closest_obstacle_index != -1)
            _player->set_move_limit(
                        _player->get_position().x(),
                        map_objects[closest_obstacle_index].get_collision_edge(_player->get_direction()));
        else
            _player->set_move_limit(_player->get_position().x(), bounds_max_y);
        break;
    default:
        break;
    }

//    BN_LOG("Move Limit x: ", _player->get_move_limit().x());
//    BN_LOG("Move Limit y: ", _player->get_move_limit().y());
}

void scene::update_player()
{
    _player->update();
    if (bn::keypad::pressed(bn::keypad::key_type::UP) ||
             bn::keypad::pressed(bn::keypad::key_type::DOWN) ||
             bn::keypad::pressed(bn::keypad::key_type::LEFT) ||
             bn::keypad::pressed(bn::keypad::key_type::RIGHT)) {
        set_player_move_limit();
    }
}

int scene::update_obstacle_interaction()
{
    if (closest_obstacle_index != -1 &&
            _player->get_position() == map_objects[closest_obstacle_index].get_position()) {
        switch (map_objects[closest_obstacle_index].get_type()) {
        case CRACKED_ICE:
        {
            map_objects[closest_obstacle_index].set_destroy();
            _player->play_fall_anim();
            return -2;
        }
        case ROCK_WALL_HOLE:
        {
            return get_next_scene();
        }
        default:
            break;
        }
    }

    return _scene;
}

int scene::update()
{
    int result = 0;

    while (true) {
        get_input();
        update_player();
        result = update_obstacle_interaction();

        //break out if death (-2) or result is greater than 0 and not the same as the current scene
        if (result < 0 || result != static_cast<int>(_scene)) {
            break;
        }

        bn::core::update();
    }

    if (result == -2)
        return _scene;
    else {
        return result;
    }
}

}
