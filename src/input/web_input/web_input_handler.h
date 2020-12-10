//
// Created by GloriousSir on 12/8/2020.
//

#ifndef SRC_BATTLEFIELDS_WEB_INPUT_HANDLER_H
#define SRC_BATTLEFIELDS_WEB_INPUT_HANDLER_H

#include "boost/asio.hpp"
namespace ba = boost::asio;

#include "../input_handler_base.h"

class web_input_handler final : public input_handler_base
{
private:
    ba::ip::tcp::socket socket;

    bool poll_event_impl(game_event &) override;
public:
    web_input_handler(ba::ip::tcp::socket && socket) : socket{std::move(socket)}
    {}

    ba::ip::tcp::socket & get_socket();
};


#endif //SRC_BATTLEFIELDS_WEB_INPUT_HANDLER_H
