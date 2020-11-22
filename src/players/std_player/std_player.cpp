//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player.h"
#include "../../std_game_config.h"

std_player::std_player()
{
    this->field = std::make_unique<std_battlefield>();
    this->ship_counter = std::vector<std::size_t>(4,0);
}

bool std_player::is_ready_impl() const
{
    return ship_counter[0] == STD_MAX_DECKS[0] &&
           ship_counter[1] == STD_MAX_DECKS[1] &&
           ship_counter[2] == STD_MAX_DECKS[2] &&
           ship_counter[3] == STD_MAX_DECKS[3];
}

std::size_t std_player::amount_of_owned_ships_impl() const
{
    return ship_counter[0]+ship_counter[1]+ship_counter[2]+ship_counter[3];
}

std::tuple<bool, bool> std_player::attack_impl(std::unique_ptr<player_base> & player_to_attack,
                                               const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->field->reveal(coordinate_to_attack);

    auto ship = is_revealed ? player_to_attack->field->get_ship(coordinate_to_attack) : nullptr;

    if (ship)
    {
        ship->apply_damage();

        if (ship->is_destroyed())
            --player_to_attack->ship_counter[ship->size()-1];

        player_to_attack->field->remove_ship_segment(coordinate_to_attack);
    }

    return std::make_tuple(is_revealed, static_cast<bool>(ship));
}

bool std_player::place_ship_impl(const std::shared_ptr<ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    bool placed = this->field->place_ship(ship_to_place, _segment);

    if (placed)
        ++ship_counter[ship_to_place->size()-1];

    return placed;
}
