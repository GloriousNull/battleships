//
// Created by GloriousSir on 11/22/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_CONSOLE_INPUT_HANDLER_H
#define SRC_BATTLEFIELDS_STD_CONSOLE_INPUT_HANDLER_H

#include "../input_handler_base.h"

class std_console_input_handler final : public input_handler_base
{
private:
    bool poll_event_impl(game_event &) override;
};


#endif //SRC_BATTLEFIELDS_STD_CONSOLE_INPUT_HANDLER_H
