//
// Created by GloriousSir on 11/15/2020.
//

#include "result_manager.h"

#include <string>

std::vector<game_result> result_manager::receive(const std::string & user_name)
{
    if (!db.is_connected())
        return std::vector<game_result>();

    std::vector<game_result> results;

    std::string query;
    if (user_name.empty())
    {
        auto callback = +[](void* cont, int argc, char** argv, char** col_name)->int
        {
            static_cast<std::vector<game_result> *>(cont)->reserve(argc/2);

            for(int i = 0; i < argc; i+=2)
            {
                game_result res{argv[i], std::atoi(argv[i+1])};
                static_cast<std::vector<game_result> *>(cont)->push_back(res);
            }

            return 0;
        };

        db.execute_query("select winner_name, turns from results;", callback, &results);
    }
    else
    {
        sqlite3_stmt * stmt;

        auto result = sqlite3_prepare_v2(db.get_session(),
                                         "select winner_name, turns from results where winner_name=?;",
                                         -1, &stmt, nullptr);

        if (result == SQLITE_OK)
            sqlite3_bind_text(stmt, 1, user_name.data(), user_name.length(), nullptr);

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            game_result res{reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)),
                            std::atoi(reinterpret_cast<const char *>
                                                           (sqlite3_column_text(stmt, 1)))};
            results.push_back(res);
        }

        sqlite3_finalize(stmt);
    }

    return results;
}

void result_manager::send(const game_result & res)
{
    if (!db.is_connected())
        return;

    sqlite3_stmt * stmt_0, * stmt_1;

    auto result_0 = sqlite3_prepare_v2(db.get_session(),
                                     "update results set turns=? where winner_name=? and turns>?;",
                                     -1, &stmt_0, nullptr);
    auto result_1 = sqlite3_prepare_v2(db.get_session(),
                                     "insert or ignore into results ('winner_name', 'turns') values (?,?);",
                                     -1, &stmt_1, nullptr);

    if (result_0 == SQLITE_OK && result_1 == SQLITE_OK)
    {
        sqlite3_bind_int64(stmt_0, 1, res.amount_of_turns);
        sqlite3_bind_text(stmt_0, 2, res.winner_name.data(), res.winner_name.length(), nullptr);
        sqlite3_bind_int64(stmt_0, 3, res.amount_of_turns);
        sqlite3_bind_text(stmt_1, 1, res.winner_name.data(), res.winner_name.length(), nullptr);
        sqlite3_bind_int64(stmt_1, 2, res.amount_of_turns);

        sqlite3_step(stmt_0);
        sqlite3_finalize(stmt_0);
        sqlite3_step(stmt_1);
        sqlite3_finalize(stmt_1);
    }
}