//
// Created by GloriousSir on 11/15/2020.
//

#ifndef SRC_BATTLEFIELDS_RESULT_MANAGER_H
#define SRC_BATTLEFIELDS_RESULT_MANAGER_H

#include "../../utils/database/database.h"
#include "game_result.h"
#include "boost/asio.hpp"

#include <vector>

namespace ba = boost::asio;

class result_manager
{
private:
    std::unique_ptr<ba::ip::tcp::socket> socket;
public:
    result_manager() : socket{nullptr} {}

    std::vector<game_result> receive() const;
    void send(const game_result &) const;
    void set_context(ba::io_context & context);
};


#endif //SRC_BATTLEFIELDS_RESULT_MANAGER_H
