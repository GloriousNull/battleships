//
// Created by GloriousSir on 12/7/2020.
//

#include "menu_game_state.h"

void menu_game_state::initialize_web_game(ba::ip::tcp::socket && socket, std::uint8_t first_player_index)
{
    auto web_input = std::make_unique<web_input_handler>(std::move(socket));

    auto player_manager =
    std::make_unique<std_player_manager>(first_player_index, std::make_unique<web_wrapper>(web_input->get_socket()),
                                         std::move(web_input));

    next_state = std::make_unique<std_game_state>(std::move(player_manager));
}

void menu_game_state::handle_nick_change(const game_event & input)
{
    player_manager->get_active().res.winner_name = std::move(input.change_nick.value().name);
}

bool menu_game_state::handle_enemy_setting(const game_event & input)
{
    if (input.set_enemy->address.empty() || input.set_enemy->port.empty())
    {
        auto player_manager =
                std::make_unique<std_player_manager>(0, std::make_unique<std_console_input_handler>());

        next_state = std::make_unique<std_game_state>(std::move(player_manager));

        return false;
    }
    else
    {
        boost::system::error_code err;
        ba::io_context io_context;

        ba::ip::tcp::endpoint endpoint(ba::ip::address::from_string(input.set_enemy->address.data()),
                                       std::atoi(input.set_enemy->port.data()));

        ba::ip::tcp::socket socket{io_context};
        socket.connect(endpoint, err);

        if (socket.is_open() && !err)
        {
            std::uint8_t index = std::rand() % 2;
            socket.write_some(ba::buffer(&index, 1));

            initialize_web_game(std::move(socket), !index);

            return false;
        }
        else
        {
            spdlog::error("Error while listening: {}, try harder", err.message());

            return true;
        }
    }
}

bool menu_game_state::handle_port_opening(const game_event & input)
{
    boost::system::error_code err;
    ba::io_context io_context;

    ba::ip::tcp::endpoint endpoint(ba::ip::tcp::v4(), std::atoi(input.open_port->port.data()));
    ba::ip::tcp::acceptor acceptor(io_context, endpoint);
    ba::ip::tcp::socket socket{io_context};

    acceptor.accept(socket, err);

    if (socket.is_open() && !err)
    {
        std::uint8_t mark;
        socket.read_some(ba::buffer(&mark, 1));

        if (mark == 1 || mark == 0)
        {
            initialize_web_game(std::move(socket), mark);

            return false;
        }
        else
        {
            spdlog::error("Invalid data received");

            return true;
        }
    }
    else
    {
        spdlog::error("Error while listening: {}, try harder", err.message());

        return true;
    }
}

bool menu_game_state::process_input_impl()
{
    bool result{true};

    _changed = false;
    game_event input;

    if (stage == game_stage::ended)
        return false;

    player_manager->get_active().input_handler->poll_event(input);

    switch (input.type)
    {
        case game_event::event_type::change_nick:
            handle_nick_change(input);
            break;
        case game_event::event_type::set_enemy:
            result = handle_enemy_setting(input);
            break;
        case game_event::event_type::open_port:
            result = handle_port_opening(input);
            break;
        case game_event::event_type::quit:
            return false;
        default:
            break;
    }

    return result;
}

std::unique_ptr<renderable_base> menu_game_state::get_render_info_impl() const
{
    return nullptr;
}