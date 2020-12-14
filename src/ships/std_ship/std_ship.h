//
// Created by GloriousSir on 10/6/2020.
//

#ifndef BATTLEFIELDS_STD_SHIP_H
#define BATTLEFIELDS_STD_SHIP_H

#include "../ship_base.h"

class std_ship final : public ship_base
{
private:
    void apply_damage_impl() override;
    std::unique_ptr<renderable_ship> get_render_info_impl() const override;
    [[nodiscard]] bool is_destroyed_impl() const override;
public:
    explicit std_ship(const std::size_t &);
};


#endif //BATTLEFIELDS_STD_SHIP_H
