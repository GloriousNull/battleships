//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player.h"
#include "std_player.h"
#include "../ships/ext_ship_base.h"

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
    bool is_revealed = this->field->reveal(point);
    auto ship = is_revealed ? this->field->get_ship(point) : nullptr;

    is_revealed = is_revealed && ship;
    if (is_revealed)
    {
        ship->apply_damage();

        this->field->remove_ship_segment(point);
    }

    return is_revealed;
}

std::tuple<bool, bool> ext_player::attack_impl(const std::shared_ptr<std_player_base> & player_to_attack, const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->field->reveal(coordinate_to_attack);

    auto ship = is_revealed ? player_to_attack->field->get_ship(coordinate_to_attack) : nullptr;

    if (ship)
    {
        ship->apply_damage();

        player_to_attack->field->remove_ship_segment(coordinate_to_attack);

        if (ship->is_destroyed())
        {
            auto checked_ship = dynamic_cast<ext_ship_base*>(ship.get());

            if (checked_ship)
                this->_duty = std::make_unique<duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &>>
                              (checked_ship->on_destroy());
        }
    }

    return std::make_tuple(is_revealed, static_cast<bool>(ship));
}

bool ext_player::place_ship_impl(const std::shared_ptr<std_ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    return field->place_ship(ship_to_place, _segment);
}
