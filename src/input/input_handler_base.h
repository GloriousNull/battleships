//
// Created by GloriousSir on 11/1/2020.
//

#ifndef SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H
#define SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H

#include "game_event.h"

class input_handler_base
{
private:
    virtual bool poll_event_impl(game_event &) = 0;
public:
    virtual ~input_handler_base() = default;

    bool poll_event(game_event &);
};


#endif //SRC_BATTLEFIELDS_INPUT_HANDLER_BASE_H
