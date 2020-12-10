//
// Created by spector on 9/18/20.
//

#ifndef BATTLESHIPS_NON_INCLINED_SEGMENT_H
#define BATTLESHIPS_NON_INCLINED_SEGMENT_H

#include "segment.h"

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::integral<L> || std::floating_point<L>)
class non_inclined_segment final : public segment<T,L>
{
private:
    bool horizontality;
    bool valid;
public:
    non_inclined_segment() : horizontality{false}, valid{false}
    {
        this->begin = {0,0};
        this->end = {0,0};
    }
    non_inclined_segment(const coordinate_2d<T> &, const coordinate_2d<T> &);
    [[nodiscard]] bool is_horizontal() const;
    [[nodiscard]] bool is_valid() const;
};

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::integral<L> || std::floating_point<L>)
non_inclined_segment<T,L>::non_inclined_segment(const coordinate_2d<T> & begin, const coordinate_2d<T> & end)
{
    horizontality = begin.get_y() == end.get_y();
    valid = horizontality || begin.get_x() == end.get_x();

    if (valid)
    {
        this->_length = horizontality ? std::abs(static_cast<int64_t>(begin.get_x() - end.get_x()))
                                      : std::abs(static_cast<int64_t>(begin.get_y() - end.get_y()));
        if ((horizontality && begin.get_x() <= end.get_x()) || (!horizontality && begin.get_y() <= end.get_y()))
        {
            this->begin = begin;
            this->end = end;
        }
        else
        {
            this->begin = end;
            this->end = begin;
        }
    }
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::integral<L> || std::floating_point<L>)
bool non_inclined_segment<T,L>::is_horizontal() const
{
    return horizontality;
}

template <typename T, typename L>
requires (std::integral<T> || std::floating_point<T>) && (std::integral<L> || std::floating_point<L>)
bool non_inclined_segment<T,L>::is_valid() const
{
    return valid;
}

#endif //BATTLESHIPS_NON_INCLINED_SEGMENT_H
