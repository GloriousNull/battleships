//
// Created by GloriousSir on 12/8/2020.
//

#ifndef SRC_BATTLEFIELDS_WEB_GAME_STATE_H
#define SRC_BATTLEFIELDS_WEB_GAME_STATE_H

#include "game_state_base.h"

class web_game_state final : public game_state_base
{
private:
    bool process_input_impl() override;
    std::unique_ptr<renderable_base> get_render_info_impl() const override;
public:

};


#endif //SRC_BATTLEFIELDS_WEB_GAME_STATE_H
