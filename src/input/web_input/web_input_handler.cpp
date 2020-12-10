//
// Created by GloriousSir on 12/8/2020.
//

#include "web_input_handler.h"
#include "../../web/message/std_message.h"
#include "../../ships/std_ship/std_ship.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

#include "spdlog/spdlog.h"

bool web_input_handler::poll_event_impl(game_event & ev)
{
    boost::system::error_code error;

    std_message msg;
    socket.read_some(ba::buffer(&msg, sizeof(std_message)), error);

    if (error)
    {
        spdlog::error("Error occurred during reading: {}", error.message());

        return true;
    }

    switch (msg)
    {
        case std_message::place_ship:
        {
            ev.type = game_event::event_type::ship_placement;

            char ship_type;
            std::size_t length;
            socket.read_some(ba::buffer(&ship_type, sizeof(char)));

            socket.read_some(ba::buffer(&length, sizeof(std::size_t)));

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
            socket.read_some(ba::buffer(&x_0, sizeof(std::size_t)));
            socket.read_some(ba::buffer(&y_0, sizeof(std::size_t)));
            socket.read_some(ba::buffer(&x_1, sizeof(std::size_t)));
            socket.read_some(ba::buffer(&y_1, sizeof(std::size_t)));

            ev.ship_placement->placement_space = {{x_0, y_0}, {x_1, y_1}};
            
            break;
        }
        case std_message::attack:
        {
            ev.type = game_event::event_type::attack;

            std::size_t x, y;
            socket.read_some(ba::buffer(&x, sizeof(std::size_t)));
            socket.read_some(ba::buffer(&y, sizeof(std::size_t)));

            ev.attack->coordinate_to_attack = {x, y};
        }
    }

    return true;
}

ba::ip::tcp::socket & web_input_handler::get_socket()
{
    return socket;
}