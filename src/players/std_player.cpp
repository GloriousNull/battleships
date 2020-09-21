//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player.h"

bool std_player::attack_impl(std_player_base * player_to_attack, const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->get_field().reveal(coordinate_to_attack);

    auto ship = is_revealed ? player_to_attack->get_field().get_ship(coordinate_to_attack) : nullptr;

    if (ship)
        ship->reduce_size();

    return is_revealed;
}

bool std_player::place_ship_impl(const std::shared_ptr<std_ship_base> & ship_to_place, const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    return field.place_ship(ship_to_place, _segment);
}