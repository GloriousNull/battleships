//
// Created by GloriousSir on 12/7/2020.
//

#include "renderable_table.h"
#include "../../battlefields/std_battlefield.h"

void renderable_table::render_impl() const
{
    auto[player_field, enemy_field] = table_to_render;

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