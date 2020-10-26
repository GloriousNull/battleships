//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_minesweeper.h"

ext_ship_minesweeper::ext_ship_minesweeper(const std::size_t & size)
{
    this->_size = size;
}

void ext_ship_minesweeper::apply_damage_impl()
{
    --this->_size;
}

bool ext_ship_minesweeper::is_destroyed_impl() const
{
    return !this->_size;
}

duty<ext_player_base &, const coordinate_2d<std::size_t> &> ext_ship_minesweeper::on_destroy_impl() const
{
    return duty<ext_player_base &, const coordinate_2d<std::size_t> &>
           {
                +[](ext_player_base & player, const coordinate_2d<std::size_t> & point) -> bool
                {
                    return player.kill_self(point);
                }
           };
}