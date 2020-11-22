//
// Created by spector on 10/19/20.
//

#ifndef SRC_BATTLEFIELDS_CONCURRENT_INPUT_HANDLER_BASE_H
#define SRC_BATTLEFIELDS_CONCURRENT_INPUT_HANDLER_BASE_H

#include <memory>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

#include "input_handler_base.h"

class concurrent_input_handler_base : public input_handler_base
{
protected:
    std::thread input_thread;
    std::mutex _mutex;
    std::queue<game_event> pending_events;
private:
    virtual void start_impl(volatile const bool &) = 0;
    virtual void end_impl() = 0;
public:
    virtual ~concurrent_input_handler_base() = default;

    void start(volatile const bool &);
    void end();
};


#endif //SRC_BATTLEFIELDS_CONCURRENT_INPUT_HANDLER_BASE_H
