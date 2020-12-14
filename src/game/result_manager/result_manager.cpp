//
// Created by GloriousSir on 11/15/2020.
//

#include "spdlog/spdlog.h"
#include "result_manager.h"
#include "../../web/message/db_message.h"

#include <string>

std::vector<game_result> result_manager::receive() const
{
    try
    {
        if (!socket->is_open())
            socket->connect(ba::ip::tcp::endpoint(ba::ip::address::from_string("127.0.0.1"), 4510));

        db_message mes = db_message::give_result;
        std::uint8_t placeholder{0};
        socket->write_some(ba::buffer(&mes, 1));
        socket->write_some(ba::buffer(&placeholder, 1));

        socket->read_some(ba::buffer(&mes, 1));

        if (mes == db_message::receive_results)
        {
            std::uint8_t size, size_in_bytes;
            socket->read_some(ba::buffer(&size, 1));
            socket->read_some(ba::buffer(&size_in_bytes, 1));

            char * received_bytes = new char[size_in_bytes];
            socket->read_some(ba::buffer(received_bytes, size_in_bytes));

            std::vector<game_result> results(size);

            std::uint8_t offset{0};
            for (std::uint8_t it{0}; it < size; ++it)
            {
                std::uint8_t name_size;
                std::memcpy(&name_size, received_bytes+offset, 1);
                ++offset;
                results[it].winner_name = std::string(received_bytes+offset, name_size);
                offset += name_size;
                std::size_t turns;
                std::memcpy(&turns, received_bytes+offset, sizeof(std::size_t));
                offset += sizeof(std::size_t);
                results[it].amount_of_turns = turns;
            }

            return results;
        }

        return {};

    }
    catch (std::exception & exception)
    {
        spdlog::error("Database connection error: {}", exception.what());

        return {};
    }
}

void result_manager::send(const game_result & res) const
{
    try
    {
        socket->connect(ba::ip::tcp::endpoint(ba::ip::address::from_string("127.0.0.1"), 4510));

        db_message mes = db_message::add_result;
        std::uint8_t name_length = static_cast<std::uint8_t>(res.winner_name.size());
        socket->write_some(ba::buffer(&mes, 1));
        socket->write_some(ba::buffer(&name_length, 1));
        socket->write_some(ba::buffer(res.winner_name.data(), name_length));
        socket->write_some(ba::buffer(&res.amount_of_turns, sizeof(std::size_t)));
    }
    catch (std::exception & exception)
    {
        spdlog::error("Database connection error: {}", exception.what());
    }
}

void result_manager::set_context(ba::io_context & context)
{
    socket = std::make_unique<ba::ip::tcp::socket>(context);
}