//
// Created by GloriousSir on 10/25/2020.
//

#include "console_user_interface.h"
#include <iostream>

void console_user_interface::render_impl(const std::unique_ptr<game_state_base> & state)
{
    if (!state->changed())
        return;

    auto[player_field, enemy_field] = state->get_render_info();

    std::cout << "Your field\n";

    std::size_t index{9};
    for (auto column = player_field.rbegin(); column != player_field.rend(); ++column)
    {
        std::cout << index-- << ' ';
        for (const auto & row_el : *column)
        {
            if (row_el.containable_ship && row_el._status == std_battlefield::point_info::status::burning)
                std::cout << '!';
            else
            if(row_el.containable_ship)
                std::cout << '*';
            else
            if (row_el._status == std_battlefield::point_info::status::open)
                std::cout << '@';
            else
                std::cout << '#';

            std::cout << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "  ";
    for (int in{0}; in < 10; ++in)
        std::cout << in << ' ';

    std::cout << "\n\nEnemy field\n";

    index = 9;
    for (auto column = enemy_field.rbegin(); column != enemy_field.rend(); ++column)
    {
        std::cout << index-- << ' ';
        for (const auto & row_el : *column)
        {
            if (row_el._status == std_battlefield::point_info::status::hidden)
                std::cout << '#';
            else
            if (row_el.containable_ship && row_el._status == std_battlefield::point_info::status::burning)
                std::cout << '!';
            else
            if(row_el.containable_ship)
                std::cout << '*';
            else
                std::cout << '@';

            std::cout << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "  ";
    for (int in{0}; in < 10; ++in)
        std::cout << in << ' ';

    std::cout << "\n---------------------\n";
}