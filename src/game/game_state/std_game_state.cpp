//
// Created by GloriousSir on 10/29/2020.
//

#include "../../players/std_player/std_player.h"
#include "../../std_game_config.h"
#include "../../ui/renderable/renderable_table.h"
#include "../../ui/renderable/renderable_turn_indicator.h"
#include "std_game_state.h"
#include "../../ui/renderable/renderable_results_board.h"

std_game_state::std_game_state()
{
    stage = game_stage::preparation_stage;
    _changed = false;
}

const std::vector<renderable_ptr> std_game_state::get_render_info_impl() const
{
    std::vector<renderable_ptr> temp;

    if (_changed)
    {
        temp.reserve(2);
        temp.push_back(std::move(std::make_unique<renderable_table>
                (_player_manager.get_user(0).player->get_field_view(),
                 _player_manager.get_user(1).player->get_field_view())));
    }

    if (stage != game_stage::ended)
        temp.push_back(std::move(std::make_unique<renderable_turn_indicator>(_player_manager.get_active_id())));
    else
    {
        if (_player_manager.get_active_id() == 0)
            temp.push_back(std::make_unique<renderable_message>("You won"));
        else
            temp.push_back(std::make_unique<renderable_message>("You lost"));

        auto results = res_manager.receive();

        temp.push_back(std::make_unique<renderable_results_board>(std::move(results)));
    }

    return std::move(temp);
}

bool std_game_state::handle_attack(const game_event & input)
{
    if (stage != game_stage::attack_stage)
        return false;

    auto[revealed, hit] = _player_manager.get_active().player->attack(_player_manager.get_inactive().player,
                                                               input.attack->coordinate_to_attack);

    ++_player_manager.get_active().res.amount_of_turns;

    if (hit && revealed)
    {
        if (_player_manager.get_inactive().player->amount_of_owned_ships() == 0)
        {
            stage = game_stage::ended;

            if (_player_manager.get_active_id() == 0)
                res_manager.send(_player_manager.get_active().res);

            return false;
        }
    }
    else
    if (revealed)
        _player_manager.turn();

    _changed = revealed;

    return true;
}

void std_game_state::handle_ship_placement(const game_event & input)
{
    if (stage != game_stage::preparation_stage
        || input.ship_placement->ship_to_place->size() > STD_MAX_SHIP_LENGTH
        || _player_manager.get_active().player->get_ship_counter()[input.ship_placement->ship_to_place->size()-1]
           == STD_MAX_DECKS[input.ship_placement->ship_to_place->size()-1])
        return;

    _changed = _player_manager.get_active().player->place_ship(std::move(input.ship_placement->ship_to_place),
                                                               input.ship_placement->placement_space)
               && !_player_manager.get_active_id();

    if (_player_manager.get_active().player->is_ready())
    {
        if (_player_manager.get_inactive().player->is_ready())
            stage = game_stage::attack_stage;

        _player_manager.turn();
    }
}

bool std_game_state::process_input_impl()
{
    _changed = false;
    game_event input;

    if (stage == game_stage::ended)
        return false;

    _player_manager.get_active().input_handler->poll_event(input);

    switch (input.type)
    {
        case game_event::event_type::ship_placement:
            handle_ship_placement(input);
            break;
        case game_event::event_type::attack:
            return handle_attack(input);
        case game_event::event_type::quit:
            return false;
        default:
            break;
    }

    return true;
}

void std_game_state::initialize_impl(std::size_t active_player_index, user<player_base> & player, user<player_base> & enemy)
{
    _player_manager.set_active_player(active_player_index);
    _player_manager.get_user(0).player = std::make_unique<std_player>();
    _player_manager.get_user(0).input_handler = std::move(player.input_handler);
    _player_manager.get_user(0).res = player.res;

    _player_manager.get_user(1).player = std::make_unique<std_player>();
    if (enemy.input_handler)
        _player_manager.get_user(1).input_handler = std::move(enemy.input_handler);
    else
        _player_manager.set_ai(std::make_unique<std_ai>(_player_manager.get_user(0).player->get_field_view()));

    _player_manager.set_ships();
}
