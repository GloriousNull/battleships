//
// Created by spector on 10/19/20.
//

#ifndef SRC_BATTLEFIELDS_CONSOLE_INPUT_HANDLER_H
#define SRC_BATTLEFIELDS_CONSOLE_INPUT_HANDLER_H

#include <iostream>

#include "input_handler_base.h"

class console_input_handler final : public input_handler_base
{
    std::shared_ptr<std_ship_base> get_ship_impl(const std::size_t &) override;
    coordinate_2d<std::size_t> get_coordinate_impl() override;
};


#endif //SRC_BATTLEFIELDS_CONSOLE_INPUT_HANDLER_H
