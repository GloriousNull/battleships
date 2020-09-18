//
// Created by spector on 9/18/20.
//

#ifndef BATTLESHIPS_NON_INCLINED_SEGMENT_H
#define BATTLESHIPS_NON_INCLINED_SEGMENT_H

#include "segment.h"

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
class non_inclined_segment : public segment<T,L>
{
private:
    bool horizontality;
    bool valid;
public:
    non_inclined_segment(const coordinate_2d<T> &, const coordinate_2d<T> &);
    [[nodiscard]] bool is_horizontal() const;
    void set_horizontality(bool);
};

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
non_inclined_segment<T,L>::non_inclined_segment(const coordinate_2d<T> & begin, const coordinate_2d<T> & end)
{
    this->begin = begin;
    this->end = end;

    horizontality = begin.get_y() == end.get_y();
    valid = be
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
bool non_inclined_segment<T,L>::is_horizontal() const
{
    return horizontality;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::floating_point<L> || std::integral<L>)
void non_inclined_segment<T,L>::set_horizontality(bool is_horizontal)
{
    horizontality = is_horizontal;
}

#endif //BATTLESHIPS_NON_INCLINED_SEGMENT_H
