//
// Created by GloriousSir on 10/31/2020.
//

#ifndef SRC_BATTLEFIELDS_PLAYER_MANAGER_H
#define SRC_BATTLEFIELDS_PLAYER_MANAGER_H

#include "player_manager_base.h"
#include "../../input/AI/std_ai.h"
#include "../../ships/std_ship/std_ship.h"
#include "../../input/input_handler_base.h"
#include "../../players/ext_player/ext_player_base.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

template <typename T>
class player_manager final : public player_manager_base<T>
{
private:
    user<T> & get_user_impl(std::size_t) override;
    const user<T> & get_user_impl(std::size_t) const override;
    user<T> & get_active_impl() override;
    user<T> & get_inactive_impl() override;
    std::size_t get_active_id_impl() const override;
    void turn_impl() override;
public:
    player_manager()
    {
        this->active_player_index = 0;
        this->players[0].player = nullptr;
        this->players[0].player = nullptr;
    }

    template<class P>
    player_manager(std::uint8_t index,
                   std::unique_ptr<P> && player,
                   std::unique_ptr<P> && enemy,
                   std::unique_ptr<input_handler_base> && first_input_handler,
                   std::unique_ptr<input_handler_base> && second_input_handler)
    {
        this->active_player_index = index;

        this->players[0].player = std::move(player);
        this->players[0].input_handler = std::move(first_input_handler);

        this->players[1].player = std::move(player);
        this->players[1].input_handler = std::move(second_input_handler);
    }

    void set_ai(std::unique_ptr<input_handler_base> && ai)
    {
        this->players[1].input_handler = std::move(ai);
        this->players[1].player->place_ship(std::make_shared<std_ship>(4), {{1,1},{1,4}});
    }

    void set_active_player(std::size_t index)
    {
        this->active_player_index = index;
    }

    // speeding up shit
    void set_ships()
    {
        if (dynamic_cast<ext_player_base*>(this->players[1].player.get()))
        {
            this->players[0].player->place_ship(std::make_shared<ext_ship_mine>(1), {{7,6},{7,6}});
            this->players[0].player->place_ship(std::make_shared<ext_ship_minesweeper>(1), {{6,9},{6,9}});
            this->players[1].player->place_ship(std::make_shared<ext_ship_mine>(1), {{7,6},{7,6}});
            this->players[1].player->place_ship(std::make_shared<ext_ship_minesweeper>(1), {{6,9},{6,9}});
        }
        else
        {
            this->players[0].player->place_ship(std::make_shared<std_ship>(1), {{7,6},{7,6}});
            this->players[0].player->place_ship(std::make_shared<std_ship>(1), {{6,9},{6,9}});
            this->players[1].player->place_ship(std::make_shared<std_ship>(1), {{7,6},{7,6}});
            this->players[1].player->place_ship(std::make_shared<std_ship>(1), {{6,9},{6,9}});
        }

        this->players[0].player->place_ship(std::make_shared<std_ship>(3), {{9,5},{9,7}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(3), {{9,0},{9,2}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(2), {{6,1},{7,1}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(2), {{4,6},{4,7}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(2), {{1,8},{1,9}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(1), {{3,0},{3,0}});
        this->players[0].player->place_ship(std::make_shared<std_ship>(1), {{4,3},{4,3}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(3), {{9,5},{9,7}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(3), {{9,0},{9,2}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(2), {{6,1},{7,1}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(2), {{4,6},{4,7}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(2), {{1,8},{1,9}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(1), {{3,0},{3,0}});
        this->players[1].player->place_ship(std::make_shared<std_ship>(1), {{4,3},{4,3}});
    }
};


template <typename T>
std::size_t player_manager<T>::get_active_id_impl() const
{
    return this->active_player_index;
}

template <typename T>
const user<T> & player_manager<T>::get_user_impl(std::size_t index) const
{
    if (index >= this->players.size())
        return this->players[0];

    return this->players[index];
}

template <typename T>
user<T> & player_manager<T>::get_user_impl(std::size_t index)
{
    if (index >= this->players.size())
        return this->players[0];

    return this->players[index];
}

template <typename T>
void player_manager<T>::turn_impl()
{
    this->active_player_index = static_cast<std::size_t>(!this->active_player_index);
}

template <typename T>
user<T> & player_manager<T>::get_active_impl()
{
    return this->players[this->active_player_index];
}

template <typename T>
user<T> & player_manager<T>::get_inactive_impl()
{
    return this->players[static_cast<std::size_t>(!this->active_player_index)];
}

#endif //SRC_BATTLEFIELDS_PLAYER_MANAGER_H
