//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_GAME_STATE_BASE_H
#define SRC_BATTLEFIELDS_GAME_STATE_BASE_H

#include <vector>

#include "../../players/player_base.h"
#include "../../ui/renderable/renderable_base.h"

using renderable_ptr = std::unique_ptr<renderable_base>;

enum class game_stage : std::uint8_t
{
    menu,
    preparation_stage,
    attack_stage,
    ended
};

class game_state_base
{
protected:
    game_stage stage;
private:
    [[nodiscard]] virtual const std::vector<renderable_ptr> get_render_info_impl() const = 0;
    virtual bool process_input_impl() = 0;
public:
    virtual ~game_state_base() = default;

    [[nodiscard]] const std::vector<renderable_ptr> get_render_info() const;

    bool process_input();
};


#endif //SRC_BATTLEFIELDS_GAME_STATE_BASE_H
