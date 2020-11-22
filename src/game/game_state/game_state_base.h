//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_GAME_STATE_BASE_H
#define SRC_BATTLEFIELDS_GAME_STATE_BASE_H

#include <queue>

#include "../../players/player_base.h"
#include "../../input/concurrent_input_handler_base.h"
#include "../player_manager/player_manager_base.h"
#include "../result_manager/result_manager.h"

enum class game_stage : std::uint8_t
{
    preparation_stage,
    attack_stage,
    ended
};

class game_state_base
{
protected:
    game_stage stage;
    bool _changed;

    result_manager res_manager{};
    std::unique_ptr<player_manager_base> player_manager;
private:
    [[nodiscard]] virtual std::tuple<std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>,
                          std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>>
    get_render_info_impl() const = 0;
    [[nodiscard]] virtual bool changed_impl() const;
    virtual bool process_input_impl() = 0;
public:
    virtual ~game_state_base() = default;

    [[nodiscard]] std::tuple<std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>,
                  std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>>
    get_render_info() const;
    [[nodiscard]] bool changed() const;

    bool process_input();
};


#endif //SRC_BATTLEFIELDS_GAME_STATE_BASE_H
