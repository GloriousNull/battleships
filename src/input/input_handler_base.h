//
// Created by spector on 10/19/20.
//

#ifndef SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H
#define SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H

#include <memory>

#include "../ships/std_ship_base.h"

#include "../utils/coordinate_2d.h"

class input_handler_base
{
private:
    virtual std::shared_ptr<std_ship_base> get_ship_impl(const std::size_t &) = 0;
    virtual coordinate_2d<std::size_t> get_coordinate_impl() = 0;
public:
    virtual ~input_handler_base() = default;

    std::shared_ptr<std_ship_base> get_ship(const std::size_t &);
    coordinate_2d<std::size_t> get_coordinate();
};


#endif //SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H
