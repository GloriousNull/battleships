//
// Created by GloriousSir on 11/15/2020.
//

#ifndef SRC_BATTLEFIELDS_USER_H
#define SRC_BATTLEFIELDS_USER_H

#include <memory>

#include "../../input/input_handler_base.h"
#include "../result_manager/game_result.h"

class input_handler_base;

template <typename T>
class user
{
public:
    std::unique_ptr<T> player;
    std::unique_ptr<input_handler_base> input_handler;
    game_result res{"John Doe", 0};
};


#endif //SRC_BATTLEFIELDS_USER_H
