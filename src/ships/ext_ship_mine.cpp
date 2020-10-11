//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_mine.h"
#include "../players/ext_player_base.h"

ext_ship_mine::ext_ship_mine(const std::size_t & size)
{
    this->_size = size;
}

void ext_ship_mine::apply_damage_impl()
{
    --this->_size;
}

bool ext_ship_mine::is_destroyed_impl() const
{
    return !this->_size;
}

duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &> ext_ship_mine::on_destroy_impl() const
{
    return duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &>
           {
                [](const std::shared_ptr<std_player_base> & player, const coordinate_2d<std::size_t> & point) -> bool
                {
                    auto checked_player = dynamic_cast<ext_player_base*>(player.get());

                    if (checked_player)
                        return checked_player->reveal_self_ship(point);

                    return false;
                }
           };
}

