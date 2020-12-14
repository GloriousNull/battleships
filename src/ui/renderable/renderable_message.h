//
// Created by GloriousSir on 12/13/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_MESSAGE_H
#define SRC_BATTLEFIELDS_RENDERABLE_MESSAGE_H

#include "renderable_base.h"

class renderable_message final : public renderable_base
{
private:
    const char * duty_to_render;
    void render_impl() const override;
public:
    explicit renderable_message(const char * duty) : duty_to_render{duty} {}
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_MESSAGE_H
