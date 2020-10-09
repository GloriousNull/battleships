//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_EXT_SHIP_BASE_H
#define BATTLEFIELDS_EXT_SHIP_BASE_H

#include <memory>
#include "std_ship_base.h"

#include "duty/duty.h"
#include "../players/std_player_base.h"

class ext_ship_base : public std_ship_base
{
private:
    [[nodiscard]] virtual duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &> on_destroy_impl() const = 0;
public:
    [[nodiscard]] duty<const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &> on_destroy() const;
};


#endif //BATTLEFIELDS_EXT_SHIP_BASE_H