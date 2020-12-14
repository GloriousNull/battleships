//
// Created by spector on 9/17/20.
//

#include "ship_base.h"

void ship_base::apply_damage()
{
    apply_damage_impl();
}

std::unique_ptr<renderable_ship> ship_base::get_render_info() const
{
    return get_render_info_impl();
}

bool ship_base::is_destroyed() const
{
    return is_destroyed_impl();
}

std::size_t ship_base::size() const
{
    return _size;
}

std::size_t ship_base::durability() const
{
    return _durability;
}