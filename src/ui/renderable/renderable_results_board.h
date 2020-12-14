//
// Created by GloriousSir on 12/14/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_RESULTS_BOARD_H
#define SRC_BATTLEFIELDS_RENDERABLE_RESULTS_BOARD_H

#include <vector>

#include "renderable_base.h"
#include "../../game/result_manager/game_result.h"

class renderable_results_board final : public renderable_base
{
private:
    std::vector<game_result> results_to_render;
    void render_impl() const override;
public:
    explicit renderable_results_board(std::vector<game_result> && v)
    : results_to_render{std::move(v)} {}
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_RESULTS_BOARD_H
