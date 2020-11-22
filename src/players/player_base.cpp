//
// Created by GloriousSir on 9/21/2020.
//

#include "player_base.h"

const std::vector<std::size_t> & player_base::get_ship_counter_impl() const
{
    return ship_counter;
}

const std::vector<std::size_t> & player_base::get_ship_counter() const
{
    return get_ship_counter_impl();
}

bool player_base::is_ready() const
{
    return is_ready_impl();
}

std::size_t player_base::amount_of_owned_ships() const
{
    return amount_of_owned_ships_impl();
}

std::tuple<bool, bool> player_base::attack(std::unique_ptr<player_base> & player, const coordinate_2d<std::size_t> & point)
{
    return attack_impl(player, point);
}

bool player_base::place_ship(const std::shared_ptr<ship_base> & ship_to_place,
                             const non_inclined_segment<std::size_t, std::size_t> & seg)
{
    return place_ship_impl(ship_to_place, seg);
}

std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE> player_base::get_field_view() const
{
    return field->get_field_view();
}
