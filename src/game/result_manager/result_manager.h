//
// Created by GloriousSir on 11/15/2020.
//

#ifndef SRC_BATTLEFIELDS_RESULT_MANAGER_H
#define SRC_BATTLEFIELDS_RESULT_MANAGER_H

#include "../../utils/database/database.h"
#include "game_result.h"

#include <vector>

class result_manager
{
private:
    database db;
public:
    result_manager() : db("file:/home/spector/db/game_results.db") {}

    std::vector<game_result> receive(const std::string & user_name = "");
    void send(const game_result &);
};


#endif //SRC_BATTLEFIELDS_RESULT_MANAGER_H
