//
// Created by GloriousSir on 12/8/2020.
//

#include "web_input_handler.h"
#include "../../web/message/input_message.h"
#include "../../ships/std_ship/std_ship.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

#include "spdlog/spdlog.h"

bool web_input_handler::poll_event_impl(game_event & ev)
{
    input_message msg;

    try
    {
        socket->read_some(ba::buffer(&msg, sizeof(input_message)));

        switch (msg)
        {
            case input_message::duty:
            {
                ev.type = game_event::event_type::duty;
                ev.attack.emplace();

                std::size_t x, y;
                socket->read_some(ba::buffer(&x, sizeof(std::size_t)));
                socket->read_some(ba::buffer(&y, sizeof(std::size_t)));

                ev.attack->coordinate_to_attack = {x, y};

                break;
            }
            case input_message::place_ship:
            {
                ev.type = game_event::event_type::ship_placement;

                char ship_type;
                std::size_t length;
                socket->read_some(ba::buffer(&ship_type, sizeof(char)));

                socket->read_some(ba::buffer(&length, sizeof(std::size_t)));
                ev.ship_placement.emplace();

                switch (ship_type)
                {
                    case 'b':
                        ev.ship_placement->ship_to_place = std::make_shared<std_ship>(length);
                        break;
                    case 'm':
                        ev.ship_placement->ship_to_place = std::make_shared<ext_ship_mine>(length);
                        break;
                    case 's':
                        ev.ship_placement->ship_to_place = std::make_shared<ext_ship_minesweeper>(length);
                        break;
                    default:
                        ev.ship_placement->ship_to_place = nullptr;
                }

                std::size_t x_0, y_0, x_1, y_1;
                socket->read_some(ba::buffer(&x_0, sizeof(std::size_t)));
                socket->read_some(ba::buffer(&y_0, sizeof(std::size_t)));
                socket->read_some(ba::buffer(&x_1, sizeof(std::size_t)));
                socket->read_some(ba::buffer(&y_1, sizeof(std::size_t)));

                ev.ship_placement->placement_space = {{x_0, y_0}, {x_1, y_1}};

                break;
            }
            case input_message::attack:
            {
                ev.type = game_event::event_type::attack;
                ev.attack.emplace();

                std::size_t x, y;
                socket->read_some(ba::buffer(&x, sizeof(std::size_t)));
                socket->read_some(ba::buffer(&y, sizeof(std::size_t)));

                ev.attack->coordinate_to_attack = {x, y};

                break;
            }
        }

        return true;
    }
    catch (std::exception & exception)
    {
        spdlog::error("Error occurred during reading: {}", exception.what());

        ev.type = game_event::event_type::quit;

        return true;
    }
}

std::shared_ptr<ba::ip::tcp::socket> web_input_handler::get_socket()
{
    return socket;
}