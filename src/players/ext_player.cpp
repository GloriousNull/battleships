//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player.h"
#include "std_player.h"
#include "../ships/typed_ship_base.h"

ext_player::ext_player()
{
    this->field = std::make_unique<std_battlefield>();
}

bool ext_player::reveal_self_impl(const coordinate_2d<std::size_t> & point)
{
    return field->reveal(point);
}

bool ext_player::kill_self_impl(const coordinate_2d<std::size_t> & point)
{
    bool is_revealed = this->get_field().reveal(point);
    auto ship = is_revealed ? this->get_field().get_ship(point) : nullptr;

    is_revealed = is_revealed && ship;
    if (is_revealed)
        ship->reduce_size();

    return is_revealed;
}

std::tuple<bool, bool> ext_player::attack_impl(const std::shared_ptr<std_player_base> & player_to_attack, const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->get_field().reveal(coordinate_to_attack);

    auto ship = is_revealed ? player_to_attack->get_field().get_ship(coordinate_to_attack) : nullptr;

    if (ship)
    {
        ship->reduce_size();

        if (ship->is_destroyed())
        {
            auto temp = dynamic_cast<typed_ship_base*>(ship.get());
            if (temp)
                _duty = temp->get_duty();
        }
    }

    return std::make_tuple(is_revealed, static_cast<bool>(ship));
}

bool ext_player::place_ship_impl(const std::shared_ptr<std_ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    return field->place_ship(ship_to_place, _segment);
}
