//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player.h"

std_player::std_player()
{
    this->field = std::make_unique<std_battlefield>();
}

bool std_player::is_ready_impl() const
{
    return this->field->is_all_ships_placed();
}

std::tuple<bool, bool> std_player::attack_impl(const std::shared_ptr<std_player_base> & player_to_attack, const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->field->reveal(coordinate_to_attack);

    auto ship = is_revealed ? player_to_attack->field->get_ship(coordinate_to_attack) : nullptr;

    if (ship)
    {
        ship->apply_damage();

        player_to_attack->field->remove_ship_segment(coordinate_to_attack);
    }

    return std::make_tuple(is_revealed, static_cast<bool>(ship));
}

bool std_player::place_ship_impl(const std::shared_ptr<std_ship_base> & ship_to_place, const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    return this->field->place_ship(ship_to_place, _segment);
}
