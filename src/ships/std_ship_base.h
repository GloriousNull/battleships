//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_STD_SHIP_BASE_H
#define BATTLESHIPS_STD_SHIP_BASE_H

#include <cstddef>

class std_ship_base
{
protected:
    std::size_t _size;

public:
    std_ship_base() : _size{0} {}
    explicit std_ship_base(const std::size_t & size) : _size{size} {}
    virtual ~std_ship_base() = default;

    void reduce_size();
    [[nodiscard]] bool is_destroyed() const;
    [[nodiscard]] std::size_t size() const;
};


#endif //BATTLESHIPS_STD_SHIP_BASE_H
