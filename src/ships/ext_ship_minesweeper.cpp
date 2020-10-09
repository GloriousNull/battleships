//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_minesweeper.h"
#include "../players/ext_player_base.h"

void ext_ship_minesweeper::apply_damage_impl()
{
    --this->_size;
}

bool ext_ship_minesweeper::is_destroyed_impl() const
{
    return !this->_size;
}

duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &> ext_ship_minesweeper::on_destroy_impl() const
{
    return duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &>
           {
                [](const std::shared_ptr<std_player_base> & player, const coordinate_2d<std::size_t> & point) -> bool
                {
                    auto checked_player = dynamic_cast<ext_player_base*>(player.get());

                    if (checked_player)
                        return checked_player->reveal_self(point);

                    return false;
                }
           };
}