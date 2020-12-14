//
// Created by GloriousSir on 12/12/2020.
//

#ifndef SRC_BATTLEFIELDS_ACTION_STATE_BASE_H
#define SRC_BATTLEFIELDS_ACTION_STATE_BASE_H

#include "game_state_base.h"
#include "../../input/input_handler_base.h"
#include "../player_manager/user.h"
#include "../result_manager/result_manager.h"

template <typename T>
class user;

class action_state_base : public game_state_base
{
protected:
    bool _changed;
    result_manager res_manager;
private:
    virtual void initialize_impl(std::size_t, user<player_base> &, user<player_base> &) = 0;
public:
    void initialize(std::size_t, user<player_base> &, user<player_base> &);
    result_manager & get_result_manager();
};


#endif //SRC_BATTLEFIELDS_ACTION_STATE_BASE_H
