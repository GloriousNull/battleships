//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_PLAYER_H
#define BATTLESHIPS_PLAYER_H

#include "battle_field.h"

class player
{
private:
    battle_field field{};
public:
    template <typename T> requires std::integral<T> || std::floating_point<T>
    [[nodiscard]] std::tuple<bool, std::function<void()>> attack(player &, const coordinate_2d<T> &);
    template <typename T> requires std::integral<T> || std::floating_point<T>
    [[nodiscard]] bool place_ship(const std::shared_ptr<ship> &, const non_inclined_segment<T,T> &);
    template <typename T> requires std::integral<T> || std::floating_point<T>
    [[nodiscard]] bool reveal_self(const non_inclined_segment<T,T> &);
};

template<typename T> requires std::integral<T> || std::floating_point<T>
[[nodiscard]] std::tuple<bool, std::function<void()>> player::attack(player & player_to_attack, const coordinate_2d<T> & coordinate_to_attack)
{
    auto[is_revealed, ship] = player_to_attack.field.reveal(coordinate_to_attack);

    if (is_revealed && ship)
    {
        ship->reduce_size();

        if (ship->is_destroyed())
            return std::make_tuple(is_revealed, ship->on_destroy());
    }

    return std::make_tuple(is_revealed, nullptr);
}

template<typename T> requires std::integral<T> || std::floating_point<T>
bool player::place_ship(const std::shared_ptr<ship> & ship_to_place, const non_inclined_segment<T, T> & _segment)
{
    return field.place_ship(ship_to_place, _segment);
}

template<typename T> requires std::integral<T> || std::floating_point<T>
bool player::reveal_self(const non_inclined_segment<T, T> & point)
{
    return field.reveal(point);
}


#endif //BATTLESHIPS_PLAYER_H
