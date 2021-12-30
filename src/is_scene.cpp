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
    if (details.event_scene) {
        bounds_max_y = (bn::display::height() / 2) - 40;

        text_generator.set_center_alignment();
        text_generator.generate(0, bounds_max_y + 26, details.event_message, text_sprites);

        _bg = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
    }
    else {
        bounds_max_y = (bn::display::height() / 2) - 8;
        _bg = bn::regular_bg_items::stage_scene.create_bg(0, 0);
    }

    BN_LOG("Background and text set");

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

    _player = player(details._player_pos.x(), details._player_pos.y(), details._player_dir);
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

game_scene scene::get_next_scene()
{
    int current = static_cast<int>(_scene);
    current ++;
    BN_LOG("Current Scene is: ", current);
    return helper::cast_to_scene(current);
}

void scene::get_input() {
    if (bn::keypad::start_pressed()) {
        scene_paused = !scene_paused;

        if (scene_paused) {
            //display pause display
        }
    }
    if (!scene_paused && bn::keypad::a_pressed()) {
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

obstacle* scene::get_closest_object() {
    bn::fixed_point player_point = _player->get_position();
    bn::fixed min_distance = 280;
    bn::fixed dist = 0;
    obstacle* object = nullptr;

    for (int i = 0; i < map_objects.size(); i ++) {
        if (!map_objects[i].get_destroyed()) {
            bn::fixed_point obj_point = map_objects[i].get_position();

            switch(_player->get_direction()) {
            case LEFT:
                dist = player_point.x() - obj_point.x();
                if (obj_point.y() == player_point.y() && obj_point.x() < player_point.x() &&
                        dist < min_distance) {
                    object = &map_objects[i];
                    min_distance = dist;
                }
                break;
            case RIGHT:
                dist = obj_point.x() - player_point.x();
                if (obj_point.y() == player_point.y() && obj_point.x() > player_point.x() &&
                        dist < min_distance) {
                    object = &map_objects[i];
                    min_distance = dist;
                }
                break;
            case UP:
                dist = player_point.y() - obj_point.y();
                if (obj_point.x() == player_point.x() && obj_point.y() < player_point.y() &&
                        dist < min_distance) {
                    object = &map_objects[i];
                    min_distance = dist;
                }
                break;
            case DOWN:
                dist = obj_point.y() - player_point.y();
                if (obj_point.x() == player_point.x() && obj_point.y() > player_point.y() &&
                        dist < min_distance) {
                    object = &map_objects[i];
                    min_distance = dist;
                }
                break;
            default:
                break;
            }
        }
    }

    return object;
}

void scene::set_player_move_limit() {
    obstacle* closest_obj = get_closest_object();
    switch(_player->get_direction()) {
    case LEFT:
        if (closest_obj)
            _player->set_move_limit(closest_obj->get_collision_edge(_player->get_direction()),
                                   _player->get_position().y());
        else
            _player->set_move_limit(bounds_min_x, _player->get_position().y());
        break;
    case RIGHT:
        if (closest_obj)
            _player->set_move_limit(closest_obj->get_collision_edge(_player->get_direction()),
                                   _player->get_position().y());
        else
            _player->set_move_limit(bounds_max_x, _player->get_position().y());
        break;
    case UP:
        if (closest_obj)
            _player->set_move_limit(_player->get_position().x(),
                                   closest_obj->get_collision_edge(_player->get_direction()));
        else
            _player->set_move_limit(_player->get_position().x(), bounds_min_y);
        break;
    case DOWN:
        if (closest_obj)
            _player->set_move_limit(_player->get_position().x(),
                                   closest_obj->get_collision_edge(_player->get_direction()));
        else
            _player->set_move_limit(_player->get_position().x(), bounds_max_y);
        break;
    default:
        break;
    }

    BN_LOG("Move Limit x: ", _player->get_move_limit().x());
    BN_LOG("Move Limit y: ", _player->get_move_limit().y());
}

game_scene scene::update()
{
    while (true) {
        get_input();

        if (!scene_paused) {
            _player->update();
            if (bn::keypad::pressed(bn::keypad::key_type::UP) ||
                     bn::keypad::pressed(bn::keypad::key_type::DOWN) ||
                     bn::keypad::pressed(bn::keypad::key_type::LEFT) ||
                     bn::keypad::pressed(bn::keypad::key_type::RIGHT)) {
                set_player_move_limit();
            }
            if (_player->get_position() == map_objects[0].get_position()) {
                return get_next_scene();
            }
        }

        bn::core::update();
    }

    return game_scene::MAIN_MENU;
}

}