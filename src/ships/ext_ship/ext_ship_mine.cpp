//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_mine.h"

ext_ship_mine::ext_ship_mine(const std::size_t & size)
{
    this->_size = size;
    this->_durability = size;
}

void ext_ship_mine::apply_damage_impl()
{
    --this->_durability;
}

std::unique_ptr<renderable_ship> ext_ship_mine::get_render_info_impl() const
{
    return std::make_unique<renderable_ship>('m');
}

bool ext_ship_mine::is_destroyed_impl() const
{
    return !this->_durability;
}

duty<ext_player_base &, const coordinate_2d<std::size_t> &> ext_ship_mine::on_destroy_impl() const
{
    return duty<ext_player_base &, const coordinate_2d<std::size_t> &>
           {
                +[](ext_player_base & player, const coordinate_2d<std::size_t> & point) -> bool
                {
                    return player.reveal_self_ship(point);
                }, "You must reveal part of your ship"
           };
}

