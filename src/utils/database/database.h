//
// Created by GloriousSir on 11/15/2020.
//

#ifndef SRC_BATTLEFIELDS_DATABASE_H
#define SRC_BATTLEFIELDS_DATABASE_H

#include <string_view>

#include "sqlite3.h"

class database
{
private:
    sqlite3 * db;
    bool connected;
public:
    database() : db{nullptr}, connected{false} {}
    explicit database(std::string_view);
    ~database();

    [[nodiscard]] bool is_connected() const;
    void connect(std::string_view);
    void disconnect();
    void execute_query(std::string_view, int(*)(void*,int,char**,char**), void * param = nullptr);
    sqlite3 * get_session();
};


#endif //SRC_BATTLEFIELDS_DATABASE_H
