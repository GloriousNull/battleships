//
// Created by GloriousSir on 12/10/2020.
//

#include "web_wrapper.h"
#include "../../web/message/web_message.h"
#include "../../web/message/std_message.h"

#include "spdlog/spdlog.h"

bool web_wrapper::poll_event_impl(game_event & ev)
{
    auto is_pending = handler.poll_event(ev);

    web_message<std_message> message;
    switch (ev.type)
    {
        case game_event::event_type::ship_placement:
            message << std_message::place_ship << 'b' << ev.ship_placement->ship_to_place->size()
                    << ev.ship_placement->placement_space.get_begin().get_x()
                    << ev.ship_placement->placement_space.get_begin().get_y()
                    << ev.ship_placement->placement_space.get_end().get_x()
                    << ev.ship_placement->placement_space.get_end().get_y();
            break;
        case game_event::event_type::attack:
            message << std_message::attack << ev.attack->coordinate_to_attack.get_x()
                    << ev.attack->coordinate_to_attack.get_y();
            break;
        default:
            return is_pending;
    }

    boost::system::error_code error;
    socket.write_some(ba::buffer(message.data(), message.size()), error);

    if (error)
        spdlog::error("Error occurred during writing: {}", error.message());

    return is_pending;
}