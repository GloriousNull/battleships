//
// Created by GloriousSir on 12/10/2020.
//

#ifndef SRC_BATTLEFIELDS_WEB_WRAPPER_H
#define SRC_BATTLEFIELDS_WEB_WRAPPER_H

#include "boost/asio.hpp"
namespace ba = boost::asio;

#include "../input_handler_base.h"
#include "../console_input/std_console_input_handler.h"

class web_wrapper final : public input_handler_base
{
private:
    ba::ip::tcp::socket & socket;
    std_console_input_handler handler;

    bool poll_event_impl(game_event &) override;

public:
    web_wrapper(ba::ip::tcp::socket & socket)
    : socket{socket} {}
};


#endif //SRC_BATTLEFIELDS_WEB_WRAPPER_H
