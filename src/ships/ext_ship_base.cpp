//
// Created by GloriousSir on 10/9/2020.
//

#include "ext_ship_base.h"

duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &> ext_ship_base::on_destroy() const
{
    return on_destroy_impl();
}