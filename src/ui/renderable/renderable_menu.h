//
// Created by GloriousSir on 12/7/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_MENU_H
#define SRC_BATTLEFIELDS_RENDERABLE_MENU_H

#include "renderable_base.h"

class renderable_menu final : public renderable_base
{
private:
    void render_impl() const override;
public:
    explicit renderable_menu()  {}
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_MENU_H
