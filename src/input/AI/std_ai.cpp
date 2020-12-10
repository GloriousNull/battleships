//
// Created by GloriousSir on 11/13/2020.
//

#include "std_ai.h"
#include "../../battlefields/std_battlefield.h"

void std_ai::set_coors(game_event & ev)
{
    ev.attack.value().coordinate_to_attack = {static_cast<std::size_t>(prev_x), static_cast<std::size_t>(prev_y)};

    if (!field_to_analyze[prev_y][prev_x].containable_ship
        || (field_to_analyze[prev_y][prev_x].containable_ship
            && field_to_analyze[prev_y][prev_x].containable_ship->size() == 1))
    {
        prev_x = -1;
        prev_y = -1;
    }
}

bool std_ai::poll_event_impl(game_event & ev)
{
    ev.type = game_event::event_type::attack;

    if (prev_x == -1 && prev_y == -1)
    {
        while (true)
        {
            prev_x = distribution(generator);
            prev_y = distribution(generator);

            if (field_to_analyze[prev_y][prev_x]._status == std_battlefield::point_info::status::hidden)
                break;
        }

        set_coors(ev);

        return true;
    }

    std::vector<void(*)(std::int64_t &)> opportunities;
    opportunities.reserve(2);

    std::uniform_int_distribution decision{1,2};

    std::int64_t & ref = prev_x;
    switch (decision(generator))
    {
        case 1:
        {
            if (prev_x < field_to_analyze.size()-1)
                opportunities.push_back(+[](std::int64_t & value){++value;});
            if (prev_x > 1)
                opportunities.push_back(+[](std::int64_t & value){--value;});

            break;
        }
        case 2:
        {
            ref = prev_y;
            if (prev_y < field_to_analyze.size()-1)
                opportunities.push_back(+[](std::int64_t & value){++value;});
            if (prev_y > 1)
                opportunities.push_back(+[](std::int64_t & value){--value;});

            break;
        }
    }

    if (!opportunities.empty())
    {
        decision = std::uniform_int_distribution{1, static_cast<int>(opportunities.size())};

        opportunities[decision(generator) - 1](ref);
    }

    set_coors(ev);

    return true;
}