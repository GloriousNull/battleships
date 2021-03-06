//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player.h"
#include "../std_player/std_player.h"
#include "../../ships/ext_ship/ext_ship_base.h"
#include "../../ext_game_config.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

ext_player::ext_player()
{
    this->_duty = nullptr;
    this->field = std::make_unique<std_battlefield>();
    this->ship_counter = std::vector<std::size_t>(6,0);
}

bool ext_player::has_duty_impl() const
{
    return static_cast<bool>(this->_duty);
}

void ext_player::fulfill_duty_impl(const coordinate_2d<std::size_t> & point)
{
    this->_duty->try_to_fulfill(*this, point);

    if (this->_duty->is_fulfilled())
        this->_duty = nullptr;
}

bool ext_player::reveal_self_ship_impl(const coordinate_2d<std::size_t> & point)
{
    if (static_cast<bool>(this->field->get_ship(point)))
        return this->field->reveal(point);

    return false;
}

bool ext_player::kill_self_impl(const coordinate_2d<std::size_t> & point)
{
    bool is_revealed = this->field->reveal(point);

    auto ship = this->field->get_ship(point);

    if (ship)
    {
        ship->apply_damage();

        this->field->remove_ship_segment(point);
    }

    return is_revealed || ship;
}

bool ext_player::is_ready_impl() const
{
    return ship_counter[0] == EXT_MAX_DECKS[0] &&
           ship_counter[1] == EXT_MAX_DECKS[1] &&
           ship_counter[2] == EXT_MAX_DECKS[2] &&
           ship_counter[3] == EXT_MAX_DECKS[3] &&
           ship_counter[4] == EXT_MAX_MINE_DECKS &&
           ship_counter[5] == EXT_MAX_MINESWEEPER_DECKS;
}

std::size_t ext_player::amount_of_owned_ships_impl() const
{
    return ship_counter[0]+ship_counter[1]+ship_counter[2]+ship_counter[3]+ship_counter[4]+ship_counter[5];
}

std::tuple<bool, bool> ext_player::attack_impl(std::unique_ptr<player_base> & player_to_attack,
                                               const coordinate_2d<std::size_t> & coordinate_to_attack)
{
    bool is_revealed = player_to_attack->field->reveal(coordinate_to_attack);

    auto ship = player_to_attack->field->get_ship(coordinate_to_attack);

    if (ship)
    {
        ship->apply_damage();

        player_to_attack->field->remove_ship_segment(coordinate_to_attack);

        if (ship->is_destroyed())
        {
            auto checked_ship = dynamic_cast<ext_ship_base*>(ship.get());

            if (dynamic_cast<ext_ship_mine*>(ship.get()))
                --player_to_attack->ship_counter[4];
            else
            if (dynamic_cast<ext_ship_minesweeper*>(ship.get()))
                --player_to_attack->ship_counter[5];
            else
                --player_to_attack->ship_counter[ship->size()-1];

            if (checked_ship)
                this->_duty = std::make_unique<duty<ext_player_base &, const coordinate_2d<std::size_t> &>>
                              (checked_ship->on_destroy());
        }
    }

    return std::make_tuple(is_revealed, static_cast<bool>(ship));
}

bool ext_player::place_ship_impl(const std::shared_ptr<ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & _segment)
{
    bool placed = this->field->place_ship(ship_to_place, _segment);

    if (placed)
    {
        if (dynamic_cast<ext_ship_mine*>(ship_to_place.get()))
            ++this->ship_counter[4];
        else
        if (dynamic_cast<ext_ship_minesweeper*>(ship_to_place.get()))
            ++this->ship_counter[5];
        else
            ++this->ship_counter[ship_to_place->size()-1];
    }

    return placed;
}

std::unique_ptr<renderable_message> ext_player::get_render_info_impl() const
{
    return std::make_unique<renderable_message>(_duty->get_message());
}
