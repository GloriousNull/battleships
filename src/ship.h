//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H


#include <cstddef>
#include <functional>

class ship
{
protected:
    std::size_t _size;
    bool destroyed;

    [[nodiscard]] virtual std::function<void()> on_destroy_iml() const = 0;
public:
    ship() : _size{0}, destroyed{false} {}
    virtual ~ship() = default;
    void reduce_size();
    [[nodiscard]] bool is_destroyed() const;
    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] std::function<void()> on_destroy() const;
};


#endif //BATTLESHIPS_SHIP_H
