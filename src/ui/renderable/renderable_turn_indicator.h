//
// Created by GloriousSir on 12/11/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_TURN_INDICATOR_H
#define SRC_BATTLEFIELDS_RENDERABLE_TURN_INDICATOR_H

#include <string_view>

#include "renderable_base.h"

class renderable_turn_indicator final : public renderable_base
{
private:
    std::uint16_t id;

    void render_impl() const override;
public:
    explicit renderable_turn_indicator(std::uint16_t id) : id{id} {}
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_TURN_INDICATOR_H
