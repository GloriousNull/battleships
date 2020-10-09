//
// Created by spector on 9/23/20.
//

#ifndef BATTLESHIPS_STD_BATTLEFIELD_BASE_H
#define BATTLESHIPS_STD_BATTLEFIELD_BASE_H

#include <vector>
#include <array>
#include <memory>

#include "../config.h"
#include "../ships/std_ship_base.h"
#include "../utils/non_inclined_segment.h"

class std_battlefield_base
{
protected:
    struct point_info
    {
        bool is_hidden{true};
        std::shared_ptr<std_ship_base> containable_ship{nullptr};
    };

    bool is_all_placed{false};
    std::size_t amount_of_ships{0};
    std::array<std::array<point_info, FIELD_SIZE>, FIELD_SIZE> field{};
private:
    [[nodiscard]] virtual bool is_all_ships_placed_impl() const = 0;
    [[nodiscard]] virtual bool place_ship_impl(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t, std::size_t> &) = 0;
    virtual bool remove_ship_segment_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool reveal_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual std::shared_ptr<std_ship_base> get_ship_impl(const coordinate_2d<std::size_t> &) = 0;
public:
    virtual ~std_battlefield_base() = default;

    [[nodiscard]] bool is_all_ships_placed() const;
    [[nodiscard]] bool place_ship(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t, std::size_t> &);
    bool remove_ship_segment(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool reveal(const coordinate_2d<std::size_t> &);
    [[nodiscard]] std::shared_ptr<std_ship_base> get_ship(const coordinate_2d<std::size_t> &);
};


#endif //BATTLESHIPS_STD_BATTLEFIELD_BASE_H
