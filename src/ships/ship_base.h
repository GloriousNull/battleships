//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_STD_SHIP_BASE_H
#define BATTLESHIPS_STD_SHIP_BASE_H

#include <cstddef>
#include <memory>
#include "../ui/renderable/renderable_ship.h"

class ship_base
{
protected:
    std::size_t _size{0};
    std::size_t _durability{0};
private:
    virtual void apply_damage_impl() = 0;
    [[nodiscard]] virtual std::unique_ptr<renderable_ship> get_render_info_impl() const = 0;
    [[nodiscard]] virtual bool is_destroyed_impl() const = 0;
public:
    virtual ~ship_base() = default;


    void apply_damage();
    [[nodiscard]] std::unique_ptr<renderable_ship> get_render_info() const;
    [[nodiscard]] bool is_destroyed() const;
    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] std::size_t durability() const;
};


#endif //BATTLESHIPS_STD_SHIP_BASE_H
