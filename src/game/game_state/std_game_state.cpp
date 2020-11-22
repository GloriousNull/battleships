//
// Created by GloriousSir on 10/29/2020.
//

#include "std_game_state.h"
#include "../player_manager/std_player_manager.h"
#include "../../players/std_player/std_player.h"
#include "../../std_game_config.h"

std_game_state::std_game_state()
{
    player_manager = std::make_unique<std_player_manager>(0, std::make_unique<std_player>(),
                                                          std::make_unique<std_player>());

    stage = game_stage::preparation_stage;
    _changed = false;
}

std::tuple<std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>,
           std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>>
std_game_state::get_render_info_impl() const
{
    return std::make_tuple(player_manager->get_user(0).player->get_field_view(),
                           player_manager->get_user(1).player->get_field_view());
}

void std_game_state::handle_nick_change(const game_event & input)
{
    player_manager->get_active().res.winner_name = std::move(input.change_nick.name);
}

void std_game_state::handle_attack(const game_event & input)
{
    if (stage != game_stage::attack_stage)
        return;

    auto[revealed, hit] = player_manager->get_active().player->attack(player_manager->get_inactive().player,
                                                               input.attack.coordinate_to_attack);

    ++player_manager->get_active().res.amount_of_turns;

    if (revealed && hit)
    {
        if (player_manager->get_inactive().player->amount_of_owned_ships() == 0)
        {
            stage = game_stage::ended;
            res_manager.send(player_manager->get_active().res);
        }
    }
    else
    if (revealed)
        player_manager->turn();

    _changed = revealed;
}

void std_game_state::handle_ship_placement(const game_event & input)
{
    if (stage != game_stage::preparation_stage
        || input.ship_placement.ship_to_place->size() > STD_MAX_SHIP_LENGTH
        || player_manager->get_active().player->get_ship_counter()[input.ship_placement.ship_to_place->size()-1]
           == STD_MAX_DECKS[input.ship_placement.ship_to_place->size()-1])
        return;

    _changed = player_manager->get_active().player->place_ship(std::move(input.ship_placement.ship_to_place),
                                                        input.ship_placement.placement_space);

    if (player_manager->get_active().player->is_ready())
    {
        if (player_manager->get_inactive().player->is_ready())
            stage = game_stage::attack_stage;

        player_manager->turn();
    }
}

bool std_game_state::process_input_impl()
{
    _changed = false;
    game_event input{};

    if (stage == game_stage::ended)
        return false;

    player_manager->get_active().input_handler->poll_event(input);

    switch (input.type)
    {
        case game_event::event_type::change_nick:
            handle_nick_change(input);
            break;
        case game_event::event_type::ship_placement:
            handle_ship_placement(input);
            break;
        case game_event::event_type::attack:
            handle_attack(input);
            break;
        case game_event::event_type::quit:
            return false;
        default:
            break;
    }

    return true;
}
