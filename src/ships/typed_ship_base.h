//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_TYPED_SHIP_BASE_H
#define BATTLESHIPS_TYPED_SHIP_BASE_H

#include "std_ship_base.h"
#include "../duty.h"
#include "../players/std_player_base.h"

class typed_ship_base : public std_ship_base
{
protected:
    duty _duty;
public:
    typed_ship_base(const std::size_t & size, duty _duty) : std_ship_base(size), _duty{_duty} {}
    [[nodiscard]] duty get_duty() const;
    void set_duty(duty);
//    std::tuple<duty, void(std_player_base*)> on_destroy(std_player_base *);
};


#endif //BATTLESHIPS_TYPED_SHIP_BASE_H
