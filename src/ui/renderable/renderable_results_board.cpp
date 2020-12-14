//
// Created by GloriousSir on 12/14/2020.
//

#include <iostream>

#include "renderable_results_board.h"

void renderable_results_board::render_impl() const
{
    std::cout << "\nResults table:\n";

    std::uint16_t counter{0};
    for (const auto & el : results_to_render)
        std::cout << ++counter << ' ' << el.winner_name << ' ' << el.amount_of_turns << '\n';
}