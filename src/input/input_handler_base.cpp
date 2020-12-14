//
// Created by GloriousSir on 11/1/2020.
//

#include "input_handler_base.h"

bool input_handler_base::poll_event(game_event & ev)
{
    return poll_event_impl(ev);
}