//
// Created by GloriousSir on 11/13/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_AI_H
#define SRC_BATTLEFIELDS_STD_AI_H

#include <random>
#include <chrono>

#include "../../battlefields/battlefield_base.h"
#include "../input_handler_base.h"

class std_ai final : public input_handler_base
{
private:
    std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE> field_to_analyze;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
    std::int64_t prev_x, prev_y;

    void set_coors(game_event &);

    bool poll_event_impl(game_event &) override;
public:
    explicit std_ai(std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE> f) :
    field_to_analyze{f}, generator(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
    distribution(0, FIELD_SIZE-1), prev_x{-1}, prev_y{-1}
    {}
};


#endif //SRC_BATTLEFIELDS_STD_AI_H
