//
// Created by spector on 10/19/20.
//

#include "concurrent_input_handler_base.h"

void concurrent_input_handler_base::start(volatile const bool & running)
{
    start_impl(running);
}

void concurrent_input_handler_base::end()
{
    end_impl();
}
