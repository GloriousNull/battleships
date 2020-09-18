//
// Created by spector on 9/18/20.
//

#ifndef BATTLESHIPS_SEGMENT_H
#define BATTLESHIPS_SEGMENT_H

#include <cmath>

#include "coordinate_2d.h"

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
class segment
{
protected:
    coordinate_2d<T> begin;
    coordinate_2d<T> end;
    L _length;
public:
    segment() : begin{}, end{}, _length{} {}
    segment(const coordinate_2d<T> & begin, const coordinate_2d<T> & end) : begin{begin}, end{end}
    { _length = std::sqrt((begin.get_x() - end.get_x())*(begin.get_x() - end.get_x())+(begin.get_y() - end.get_y())*(begin.get_y() - end.get_y())); }
    L get_length() const;
    auto get_begin() const;
    auto get_end() const;
    void set_begin(const coordinate_2d<T>&);
    void set_end(const coordinate_2d<T>&);

    virtual ~segment() = default;
};

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
L segment<T,L>::get_length() const
{
    return _length;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
auto segment<T,L>::get_begin() const
{
    return begin;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
auto segment<T,L>::get_end() const
{
    return end;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
void segment<T,L>::set_begin(const coordinate_2d<T> & coor_to_set)
{
    begin = coor_to_set;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
void segment<T,L>::set_end(const coordinate_2d<T> & coor_to_set)
{
    end = coor_to_set;
}
#endif //BATTLESHIPS_SEGMENT_H
