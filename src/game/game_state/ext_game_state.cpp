//
// Created by GloriousSir on 12/12/2020.
//

#include "ext_game_state.h"
#include "../../players/ext_player/ext_player.h"
#include "../../ext_game_config.h"
#include "../../ui/renderable/renderable_table.h"
#include "../../ui/renderable/renderable_turn_indicator.h"

ext_game_state::ext_game_state()
{
    stage = game_stage::preparation_stage;
    _changed = false;
}

void ext_game_state::handle_duty_fulfillment(const game_event & input)
{
    if (stage != game_stage::attack_stage || !static_cast<ext_player*>(_player_manager.get_active().player.get())->has_duty())
        return;

    static_cast<ext_player*>(_player_manager.get_active().player.get())
                             ->fulfill_duty(input.attack->coordinate_to_attack);
    if (!static_cast<ext_player*>(_player_manager.get_active().player.get())->has_duty())
    {
        ++_player_manager.get_active().res.amount_of_turns;

        if (_player_manager.get_active().player->amount_of_owned_ships() == 0)
        {
            stage = game_stage::ended;
//            if (player_manager->get_active_id())
//            res_manager.send(player_manager->get_active().res);
        }
        else
        {
            _changed = true;
            _player_manager.turn();
        }
    }
}

void ext_game_state::handle_attack(const game_event & input)
{
    if (stage != game_stage::attack_stage || static_cast<ext_player*>(_player_manager.get_active().player.get())->has_duty())
        return;

    auto[revealed, hit] = _player_manager.get_active().player->attack(_player_manager.get_inactive().player,
                                                                      input.attack->coordinate_to_attack);

    ++_player_manager.get_active().res.amount_of_turns;

    if (hit && revealed)
    {
        if (_player_manager.get_inactive().player->amount_of_owned_ships() == 0)
        {
            stage = game_stage::ended;
//            if (player_manager->get_active_id())
//            res_manager.send(player_manager->get_active().res);
        }
    }
    else
    if (revealed)
        _player_manager.turn();

    _changed = revealed || hit;
}

void ext_game_state::handle_ship_placement(const game_event & input)
{
    switch (input.ship_placement->ship_type)
    {
        case 's':
        {
            if (input.ship_placement->ship_to_place->size() != 1
                || _player_manager.get_active().player->get_ship_counter()[5] == EXT_MAX_MINESWEEPER_DECKS)
                return;

            break;
        }
        case 'm':
        {
            if (input.ship_placement->ship_to_place->size() != 1
                || _player_manager.get_active().player->get_ship_counter()[4] == EXT_MAX_MINE_DECKS)
                return;

            break;
        }
    }

    if (stage != game_stage::preparation_stage
        || input.ship_placement->ship_to_place->size() > EXT_MAX_SHIP_LENGTH
        || _player_manager.get_active().player->get_ship_counter()[input.ship_placement->ship_to_place->size()-1]
           == EXT_MAX_DECKS[input.ship_placement->ship_to_place->size()-1])
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

bool ext_game_state::process_input_impl()
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
            handle_attack(input);
            break;
        case game_event::event_type::duty:
            handle_duty_fulfillment(input);
            break;
        case game_event::event_type::quit:
            return false;
        default:
            break;
    }

    return true;
}

void ext_game_state::initialize_impl(std::size_t active_player_index, user<player_base> & player, user<player_base> & enemy)
{
    _player_manager.set_active_player(active_player_index);
    _player_manager.get_user(0).player = std::make_unique<ext_player>();
    _player_manager.get_user(0).input_handler = std::move(player.input_handler);
    _player_manager.get_user(0).res = player.res;

    _player_manager.get_user(1).player = std::make_unique<ext_player>();
    if (enemy.input_handler)
        _player_manager.get_user(1).input_handler = std::move(enemy.input_handler);
    else
        _player_manager.set_ai(std::make_unique<std_ai>(_player_manager.get_user(0).player->get_field_view()));

    _player_manager.set_ships();
}

const std::vector<renderable_ptr> ext_game_state::get_render_info_impl() const
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
    {
        temp.push_back(std::move(std::make_unique<renderable_turn_indicator>(_player_manager.get_active_id())));
        if (static_cast<ext_player*>(_player_manager.get_user(_player_manager.get_active_id()).player.get())->has_duty())
            temp.push_back(static_cast<ext_player*>(_player_manager.get_user(_player_manager.get_active_id())
            .player.get())->get_render_info());
    }
    else
    {
        if (_player_manager.get_active_id() == 0)
            temp.push_back(std::make_unique<renderable_message>("You won"));
        else
            temp.push_back(std::make_unique<renderable_message>("You lost"));
    }

    return std::move(temp);
}