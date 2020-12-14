//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_minesweeper.h"

ext_ship_minesweeper::ext_ship_minesweeper(const std::size_t & size)
{
    this->_size = size;
    this->_durability = size;
}

void ext_ship_minesweeper::apply_damage_impl()
{
    --this->_durability;
}
std::unique_ptr<renderable_ship> ext_ship_minesweeper::get_render_info_impl() const
{
    return std::make_unique<renderable_ship>('s');
}

bool ext_ship_minesweeper::is_destroyed_impl() const
{
    return !this->_durability;
}

duty<ext_player_base &, const coordinate_2d<std::size_t> &> ext_ship_minesweeper::on_destroy_impl() const
{
    return duty<ext_player_base &, const coordinate_2d<std::size_t> &>
           {
                +[](ext_player_base & player, const coordinate_2d<std::size_t> & point) -> bool
                {
                    return player.kill_self(point);
                }, "You must destroy part of your ship"
           };
}