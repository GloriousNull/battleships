#include "ships/battle_ship.h"
#include "ships/surprise_ship.h"
#include "ships/unsurprising_ship.h"

#include "utils/non_inclined_segment.h"
#include "battle_field.h"
#include "player.h"

int main()
{
    player p_0, p_1;

    bool b = p_1.place_ship<std::size_t>(std::make_shared<battle_ship>(battle_ship(2)), {{2,2},{2,3}});

    auto[is_revealed, func] = p_0.attack<std::size_t>(p_1,{2,2});

    if (func && b)
        func();

    return 0;
}
