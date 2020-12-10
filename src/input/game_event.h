//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_EVENT_H
#define SRC_BATTLEFIELDS_EVENT_H

#endif //SRC_BATTLEFIELDS_EVENT_H

#include <memory>

#include "../utils/math/non_inclined_segment.h"
#include "../ships/ship_base.h"

struct game_event
{
    struct open_port_event
    {
        std::string port;
    };

    struct set_enemy_event
    {
        std::string address, port;
    };

    struct change_nickname_event
    {
        std::string name;
    };

    struct ship_placement_event
    {
        std::shared_ptr<ship_base> ship_to_place;
        non_inclined_segment<std::size_t, std::size_t> placement_space;
    };

    struct attack_event
    {
        coordinate_2d<std::size_t> coordinate_to_attack;
    };

    enum class event_type
    {
        open_port,
        set_enemy,
        change_nick,
        ship_placement,
        attack,
        quit,
        none
    };

    event_type type;


    std::optional<open_port_event> open_port;
    std::optional<set_enemy_event> set_enemy;
    std::optional<change_nickname_event> change_nick;
    std::optional<ship_placement_event> ship_placement;
    std::optional<attack_event> attack;


    game_event() : type{event_type::none} {}
    explicit game_event(event_type type) : type{type} {}

    explicit game_event(const game_event & _event)
    {
        this->type = _event.type;

        switch (_event.type)
        {
            case event_type::open_port:
                this->open_port = _event.open_port;
                break;
            case event_type::set_enemy:
                this->set_enemy = _event.set_enemy;
                break;
            case event_type::change_nick:
                this->change_nick = _event.change_nick;
                break;
            case event_type::ship_placement:
                this->ship_placement = _event.ship_placement;
                break;
            case event_type::attack:
                this->attack = _event.attack;
                break;
            default:
                break;
        }
    }

    game_event & operator=(const game_event & _event)
    {
        this->type = _event.type;

        switch (_event.type)
        {
            case event_type::open_port:
                this->open_port = _event.open_port;
                break;
            case event_type::set_enemy:
                this->set_enemy = _event.set_enemy;
                break;
            case event_type::change_nick:
                this->change_nick = _event.change_nick;
                break;
            case event_type::ship_placement:
                this->ship_placement = _event.ship_placement;
                break;
            case event_type::attack:
                this->attack = _event.attack;
                break;
            default:
                break;
        }

        return *this;
    }

    game_event & operator=(game_event && _event)
    {
        this->type = _event.type;

        switch (_event.type)
        {
            case event_type::open_port:
                this->open_port = _event.open_port;
                break;
            case event_type::set_enemy:
                this->set_enemy = _event.set_enemy;
                break;
            case event_type::change_nick:
                this->change_nick = _event.change_nick;
                break;
            case event_type::ship_placement:
                this->ship_placement = _event.ship_placement;
                break;
            case event_type::attack:
                this->attack = _event.attack;
                break;
            default:
                break;
        }

        return *this;
    }
};