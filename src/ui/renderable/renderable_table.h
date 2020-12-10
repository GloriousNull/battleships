//
// Created by GloriousSir on 12/7/2020.
//

#ifndef SRC_BATTLEFIELDS_RENDERABLE_TABLE_H
#define SRC_BATTLEFIELDS_RENDERABLE_TABLE_H

#include <tuple>
#include <span>

#include "renderable_base.h"
#include "../../std_game_config.h"
#include "../../battlefields/battlefield_base.h"

class renderable_table final : public renderable_base
{
private:
    using table_type = std::tuple<std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>,
            std::span<const std::array<battlefield_base::point_info, STD_FIELD_SIZE>, STD_FIELD_SIZE>>;

    table_type table_to_render;

    void render_impl() const override;
public:
    explicit renderable_table(table_type field) : table_to_render{field} {};
};


#endif //SRC_BATTLEFIELDS_RENDERABLE_TABLE_H
