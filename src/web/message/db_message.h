//
// Created by GloriousSir on 12/13/2020.
//

#ifndef SRC_BATTLEFIELDS_DB_MESSAGE_H
#define SRC_BATTLEFIELDS_DB_MESSAGE_H

#include <cstdint>

enum class db_message : std::uint8_t
{
    add_result,
    give_result,
    receive_results
};

#endif //SRC_BATTLEFIELDS_DB_MESSAGE_H
