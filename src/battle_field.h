//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include <vector>
#include <array>
#include <memory>

#include "config.h"
#include "ship.h"
#include "utils/non_inclined_segment.h"

class battle_field
{
private:
    struct point_info
    {
        bool is_hidden{true};
        std::shared_ptr<ship> containable_ship{nullptr};
    };

    std::vector<std::shared_ptr<ship>> ships;
    std::array<std::array<point_info, FIELD_SIZE>, FIELD_SIZE> field{};

    template<std::unsigned_integral T>
    bool is_enough_space_to_place(const std::size_t &, const non_inclined_segment<T, T> &) const;
public:
    battle_field();

    [[nodiscard]] bool is_all_ships_placed() const;
    template<std::unsigned_integral T>
    [[nodiscard]] bool place_ship(const std::shared_ptr<ship>&, const non_inclined_segment<T,T> &);
    template<std::unsigned_integral T>
    [[nodiscard]] std::tuple<bool, std::shared_ptr<ship>> reveal(const coordinate_2d<T> &);
};

battle_field::battle_field()
{
    ships.reserve(AMOUNT_OF_SHIPS);
}

bool battle_field::is_all_ships_placed() const
{
    return ships.size() == AMOUNT_OF_SHIPS;
}

template<std::unsigned_integral T>
bool battle_field::is_enough_space_to_place(const std::size_t & ship_size, const non_inclined_segment<T, T> & segment) const
{
    if (ship_size - 1 != segment.get_length())
        return false;

    const T y_it_start = !segment.get_begin().get_y() ? 0 : segment.get_begin().get_y() - 1;
    const T x_it_start = !segment.get_begin().get_x() ? 0 : segment.get_begin().get_x() - 1;
    const T y_end = segment.get_end().get_y();
    const T x_end = segment.get_end().get_x();

    for (T y_it{y_it_start}; y_it <= y_end; ++y_it)
        for (T x_it{x_it_start}; x_it <= x_end; ++x_it)
            if (field[y_it][x_it].containable_ship)
                return false;

    return true;
}

template<std::unsigned_integral T>
bool battle_field::place_ship(const std::shared_ptr<ship>& ship_ptr, const non_inclined_segment<T, T> & segment)
{
    if (!segment.is_valid() || !is_enough_space_to_place(ship_ptr->size(), segment))
    {
        return false;
    }

    T begin = segment.get_begin().get_x();
    T end = segment.get_begin().get_y();
    T & it = segment.is_horizontal() ? begin : end;
    const T & it_end = segment.is_horizontal() ? segment.get_end().get_x() : segment.get_end().get_y();

    for (; it <= it_end; ++it)
        field[begin][end].containable_ship = ship_ptr;

    ships.push_back(ship_ptr);

    return true;
}

template <std::unsigned_integral T>
std::tuple<bool, std::shared_ptr<ship>> battle_field::reveal(const coordinate_2d<T> & point)
{
    if (point.get_x() < 0 || point.get_x() >= FIELD_SIZE || point.get_y() < 0 || point.get_y() >= FIELD_SIZE)
        return std::make_tuple(false, nullptr);

    if (field[point.get_x()][point.get_y()].is_hidden)
    {
        field[point.get_x()][point.get_y()].is_hidden = false;

        return std::make_tuple(true, field[point.get_x()][point.get_y()].containable_ship);
    }

    return std::make_tuple(false, nullptr);
}

#endif //BATTLESHIPS_BATTLE_FIELD_H
