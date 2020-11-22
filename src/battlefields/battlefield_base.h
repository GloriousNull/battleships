//
// Created by spector on 9/23/20.
//

#ifndef BATTLESHIPS_STD_BATTLEFIELD_BASE_H
#define BATTLESHIPS_STD_BATTLEFIELD_BASE_H

#include <vector>
#include <array>
#include <memory>
#include <span>

#include "../config.h"
#include "../ships/ship_base.h"
#include "../utils/math/non_inclined_segment.h"

class battlefield_base
{
public:
    struct point_info
    {
        enum class status
        {
            hidden,
            open,
            burning
        };

        status _status{status::hidden};
        std::shared_ptr<ship_base> containable_ship{nullptr};
    };
protected:
    std::array<std::array<point_info, FIELD_SIZE>, FIELD_SIZE> field{};
private:
    [[nodiscard]] virtual bool place_ship_impl(const std::shared_ptr<ship_base> &, const non_inclined_segment<std::size_t, std::size_t> &) = 0;
    virtual bool remove_ship_segment_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool reveal_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual std::shared_ptr<ship_base> get_ship_impl(const coordinate_2d<std::size_t> &) = 0;
public:
    virtual ~battlefield_base() = default;

    [[nodiscard]] bool place_ship(const std::shared_ptr<ship_base> &, const non_inclined_segment<std::size_t, std::size_t> &);
    bool remove_ship_segment(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool reveal(const coordinate_2d<std::size_t> &);
    [[nodiscard]] std::shared_ptr<ship_base> get_ship(const coordinate_2d<std::size_t> &);
    [[nodiscard]] std::span<const std::array<point_info, FIELD_SIZE>, FIELD_SIZE> get_field_view() const;
};


#endif //BATTLESHIPS_STD_BATTLEFIELD_BASE_H
