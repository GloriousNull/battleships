//
// Created by GloriousSir on 9/21/2020.
//

#include "typed_ship_base.h"

duty typed_ship_base::get_duty() const
{
    return _duty;
}

void typed_ship_base::set_duty(duty duty_to_set)
{
    _duty = duty_to_set;
}