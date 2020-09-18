//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include <vector>
#include <array>

#include "config.h"

class battle_field
{
private:
    struct point_info
    {
        bool is_hidden{true}, contains_ship{false};
        ship * containable_ship{nullptr};
    };

    std::vector<ship*> ships;
    std::array<std::array<point_info, FIELD_SIZE>, FIELD_SIZE> field;

    template<std::unsigned_integral T>
    bool is_enough_space_to_place(const std::size_t &, const non_inclined_segment<T, T> &) const;
public:
    battle_field() : ships(AMOUNT_OF_SHIPS), field{} {}
    ~battle_field();

    [[nodiscard]] bool is_all_ships_placed() const;
    template<std::unsigned_integral T>
    [[nodiscard]] bool place_ship(ship*, const non_inclined_segment<T,T> &);
    template<std::unsigned_integral T>
    [[nodiscard]] bool reveal(const coordinate_2d<T> &);
};

battle_field::~battle_field()
{
    for (auto elem : ships)
        delete elem;
}

bool battle_field::is_all_ships_placed() const
{
    return ships.size() == AMOUNT_OF_SHIPS;
}

template<std::unsigned_integral T>
bool battle_field::is_enough_space_to_place(const std::size_t & ship_size, const non_inclined_segment<T, T> & segment) const
{

}

template<std::unsigned_integral T>
bool battle_field::place_ship(ship* ship_ptr, const non_inclined_segment<T, T> & segment)
{
    if (!is_enough_space_to_place(ship_ptr->size(), segment))
    {
        delete ship_ptr;

        return false;
    }

}

template <std::unsigned_integral T>
bool battle_field::reveal(const coordinate_2d<T> & point)
{
    if (field[point.get_x()][point.get_y()].is_hidden)
    {
        field[point.get_x()][point.get_y()].is_hidden = false;

        return true;
    }

    return false;
}

#endif //BATTLESHIPS_BATTLE_FIELD_H
