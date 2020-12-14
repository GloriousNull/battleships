//
// Created by GloriousSir on 12/7/2020.
//

#include "renderable_table.h"
#include "../../battlefields/std_battlefield.h"

void renderable_table::render_impl() const
{
    std::cout << "Your field\n";

    std::size_t index{9};
    for (auto column = player_table.rbegin(); column != player_table.rend(); ++column)
    {
        std::cout << index-- << ' ';
        for (const auto & row_el : *column)
        {
            if (row_el.containable_ship && row_el._status == std_battlefield::point_info::status::burning)
                std::cout << '!';
            else
            if(row_el.containable_ship)
                row_el.containable_ship->get_render_info()->render();
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
    for (auto column = enemy_table.rbegin(); column != enemy_table.rend(); ++column)
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
                row_el.containable_ship->get_render_info()->render();
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