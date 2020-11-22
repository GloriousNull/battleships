//
// Created by GloriousSir on 11/15/2020.
//

#include "database.h"
#include "spdlog/spdlog.h"

database::database(std::string_view connection)
{
    int result = sqlite3_open(connection.data(), &db);

    if (result)
    {
        spdlog::error("Unable to access database: {}", sqlite3_errmsg(db));
        sqlite3_close(db);
        db = nullptr;
    }
    else
        connected = true;
}

database::~database()
{
    if (db)
        sqlite3_close(db);
}

bool database::is_connected() const
{
    return connected;
}

void database::connect(std::string_view connection)
{
    if (connected)
        disconnect();

    int result = sqlite3_open(connection.data(), &db);

    if (result)
    {
        spdlog::error("Unable to access database: {}", sqlite3_errmsg(db));
        sqlite3_close(db);
        db = nullptr;
        connected = false;
    }
    else
        connected = true;
}

void database::disconnect()
{
    int result = sqlite3_close(db);

    if (result)
    {
        spdlog::error("Unable to close connection to database: {}", sqlite3_errmsg(db));
        connected = false;
    }
    else
        connected = true;
}

void database::execute_query(std::string_view query, int (*callback)(void *, int, char **, char **), void * param)
{
    char * error_message;

    int result = sqlite3_exec(db, query.data(), callback, param, &error_message);

    if (result)
        spdlog::error("Error occurred: {}", error_message);
}

sqlite3 * database::get_session()
{
    return db;
}