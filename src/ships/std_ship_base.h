//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_STD_SHIP_BASE_H
#define BATTLESHIPS_STD_SHIP_BASE_H

#include <cstddef>

class std_ship_base
{
protected:
    std::size_t _size{0};
private:
    virtual void apply_damage_impl() = 0;
    [[nodiscard]] virtual bool is_destroyed_impl() const = 0;
public:
    virtual ~std_ship_base() = default;

    void apply_damage();
    [[nodiscard]] bool is_destroyed() const;
    [[nodiscard]] std::size_t size() const;
};


#endif //BATTLESHIPS_STD_SHIP_BASE_H
