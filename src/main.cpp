#include "spdlog/spdlog.h"

#include "ships/battle_ship.h"
#include "ships/surprise_ship.h"
#include "ships/unsurprising_ship.h"

#include "utils/non_inclined_segment.h"
#include "battle_field.h"

int main()
{
    battle_field bf;

    bool b = bf.place_ship<std::size_t>(new surprise_ship(), {{5,4},{4,4}});

    coordinate_2d<std::size_t> coordinate(5,4);
    coordinate_2d<std::size_t> coor(10,4);

    segment<std::size_t, std::size_t> * seg = new non_inclined_segment<std::size_t, std::size_t>(coordinate,coor);

    spdlog::info("{} {} {}", b, seg->get_length(), coordinate.get_y());

    return 0;
}
