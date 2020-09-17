//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include <vector>
#include <array>

#include "config.h"
#include "ship.h"

#include "utils/coordinate_2d.h"

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
public:
    battle_field() : ships(AMOUNT_OF_SHIPS), field{} {}
    ~battle_field();
    [[nodiscard]] bool is_all_ships_placed() const;

    template<std::unsigned_integral T>
    [[nodiscard]] bool place_ship(ship*, const coordinate_2d<T> &, const coordinate_2d<T> &);
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
bool battle_field::place_ship(ship* ship_ptr, const coordinate_2d<T> & begin, const coordinate_2d<T> & end)
{
    std::size_t size = begin.x - end.x ? std::abs(begin.x-end.x) : std::abs(begin.y-end.y);

    if (ship_ptr->size() != size)
        return false;
}

template <std::unsigned_integral T>
bool battle_field::reveal(const coordinate_2d<T> & point)
{
    if (field[point.x][point.y].is_hidden)
    {
        field[point.x][point.y].is_hidden = false;

        return true;
    }

    return false;
}

#endif //BATTLESHIPS_BATTLE_FIELD_H
