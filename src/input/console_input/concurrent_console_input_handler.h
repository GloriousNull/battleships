//
// Created by spector on 10/19/20.
//

#ifndef SRC_BATTLEFIELDS_CONCURRENT_CONSOLE_INPUT_HANDLER_H
#define SRC_BATTLEFIELDS_CONCURRENT_CONSOLE_INPUT_HANDLER_H

#include <iostream>

#include "../concurrent_input_handler_base.h"

class concurrent_console_input_handler final : public concurrent_input_handler_base
{
private:
    bool poll_event_impl(game_event &) override;
    void start_impl(volatile const bool &) override;
    void end_impl() override;
};


#endif //SRC_BATTLEFIELDS_CONCURRENT_CONSOLE_INPUT_HANDLER_H
