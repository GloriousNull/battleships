//
// Created by GloriousSir on 12/7/2020.
//

#include "menu_game_state.h"
#include "ext_game_state.h"

void menu_game_state::initialize_web_game(ba::io_context & context, const game_event & input,
                                          std::shared_ptr<ba::ip::tcp::socket> socket,
                                          std::uint8_t first_player_index)
{
    auto web_input = std::make_unique<web_input_handler>(socket);

    user<player_base> player{.input_handler=std::make_unique<web_wrapper>(socket),
                             .res={name, 0}};
    user<player_base> enemy{.input_handler=std::make_unique<web_input_handler>(socket)};

    input.start_game->state_to_start->initialize(first_player_index, player, enemy);
    input.start_game->state_to_start->get_result_manager().set_context(context);

    next_state = std::unique_ptr<action_state_base>(input.start_game->state_to_start);
}

void menu_game_state::handle_nick_change(const game_event & input)
{
    name = std::move(input.change_nick.value().name);
}

bool menu_game_state::handle_game_starting(const game_event & input)
{
    if (input.start_game->address.empty() || input.start_game->port.empty())
    {
        user<player_base> player{.input_handler=std::make_unique<std_console_input_handler>(),
                                 .res = {name, 0}},
                          enemy{.input_handler=nullptr};
        input.start_game->state_to_start->initialize(0, player, enemy);

        next_state = std::unique_ptr<action_state_base>(input.start_game->state_to_start);

        return false;
    }
    else
    {
        try
        {
            static ba::io_context io_context;

            ba::ip::tcp::endpoint endpoint(ba::ip::address::from_string(input.start_game->address.data()),
                                           std::atoi(input.start_game->port.data()));

            auto socket = std::make_shared<ba::ip::tcp::socket>(io_context);
            socket->connect(endpoint);

            if (socket->is_open())
            {
                std::uint8_t index = std::rand() % 2;
                socket->write_some(ba::buffer(&input.start_game->type, 1));
                socket->write_some(ba::buffer(&index, 1));

                initialize_web_game(io_context, input, socket, !index);
                spdlog::info("Game initialized");

                return false;
            }
        }
        catch (std::exception & exception)
        {
            spdlog::error("Error while listening: {}, try harder", exception.what());

            return true;
        }

        return true;
    }
}

bool menu_game_state::handle_port_opening(game_event & input)
{
    try
    {
        static ba::io_context io_context;

        ba::ip::tcp::endpoint endpoint(ba::ip::tcp::v4(), std::atoi(input.open_port->port.data()));
        ba::ip::tcp::acceptor acceptor(io_context, endpoint);
        auto socket = std::make_shared<ba::ip::tcp::socket>(io_context);

        acceptor.accept(*socket);

        if (socket->is_open())
        {
            game_event::start_game_event::game_type type;
            socket->read_some(ba::buffer(&type, 1));
            std::uint8_t mark;
            socket->read_some(ba::buffer(&mark, 1));

            if (mark == 1 || mark == 0)
            {
                if (type == game_event::start_game_event::game_type::std)
                    input.start_game->state_to_start = new std_game_state();
                else
                if (type == game_event::start_game_event::game_type::ext)
                    input.start_game->state_to_start = new ext_game_state();
                else
                {
                    spdlog::error("Invalid game state received");

                    return true;
                }

                initialize_web_game(io_context, input, socket, mark);
                spdlog::info("Game initialized");

                return false;
            }
            else
            {
                spdlog::error("Invalid player index received");

                return true;
            }
        }
    }
    catch (std::exception & exception)
    {
        spdlog::error("Error while listening: {}, try harder", exception.what());

        return true;
    }

    return true;
}

bool menu_game_state::process_input_impl()
{
    bool result{true};

    game_event input;

    if (stage == game_stage::ended)
        return false;

    input_handler->poll_event(input);

    switch (input.type)
    {
        case game_event::event_type::change_nick:
            handle_nick_change(input);
            break;
        case game_event::event_type::start_game:
            result = handle_game_starting(input);
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

const std::vector<renderable_ptr> menu_game_state::get_render_info_impl() const
{
    return {};
}