#include "spdlog/spdlog.h"

#include "ships/battle_ship.h"
#include "ships/surprise_ship.h"
#include "ships/unsurprising_ship.h"

#include "utils/coordinate_2d.h"
#include "battle_field.h"

int main()
{
    battle_field bf;

    bool b = bf.reveal<std::size_t>({5,4});

    coordinate_2d<int> coordinate(5,4);

    spdlog::info("{} {} {}", b, coordinate.get_y(), s_1->size());

    delete s;
    delete s_0;
    delete s_1;

    return 0;
}
