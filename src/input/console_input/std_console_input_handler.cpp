//
// Created by GloriousSir on 11/22/2020.
//

#include "std_console_input_handler.h"
#include "../../ships/std_ship/std_ship.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

bool std_console_input_handler::poll_event_impl(game_event & ev)
{
    char choice;
    std::cin >> choice;
    switch (choice)
    {
        case 'n':
        {
            ev.type = game_event::event_type::change_nick;
            std::string temp;
            std::cin >> temp;
            ev.change_nick.name = std::move(temp);

            break;
        }
        case 'a':
        {
            ev.type = game_event::event_type::attack;

            std::cin >> ev.attack.coordinate_to_attack;

            break;
        }
        case 'p':
        {
            ev.type = game_event::event_type::ship_placement;

            char ship_type;
            std::size_t length;

            std::cin >> ship_type >> length;
            switch (ship_type)
            {
                case 'b':
                    ev.ship_placement.ship_to_place = std::make_shared<std_ship>(length);
                    break;
                case 'm':
                    ev.ship_placement.ship_to_place = std::make_shared<ext_ship_mine>(length);
                    break;
                case 's':
                    ev.ship_placement.ship_to_place = std::make_shared<ext_ship_minesweeper>(length);
                    break;
                default:
                    ev.ship_placement.ship_to_place = nullptr;
                    break;
            }
            coordinate_2d<std::size_t> first, second;

            std::cin >> first >> second;
            ev.ship_placement.placement_space = {first, second};

            break;
        }
        case 'q':
        {
            ev.type = game_event::event_type::quit;

            break;
        }
        default:
            break;
    }

    return true;
}