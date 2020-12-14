//
// Created by GloriousSir on 12/13/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_SHIP_H
#define SRC_BATTLEFIELDS_RENDERABLE_SHIP_H

#include "renderable_base.h"

class renderable_ship final : public renderable_base
{
private:
    char ship;

    void render_impl() const override;
public:
    renderable_ship(char ship) : ship{ship} {}
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_SHIP_H
