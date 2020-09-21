#include "players/ext_player.h"
#include "ships/typed_ship_base.h"
#include "duty.h"

#include "iostream"

int main()
{
    std_player_base * p = new ext_player();
    std_player_base * p_2 = new ext_player();

    bool b1 = p->place_ship(std::make_shared<typed_ship_base>(typed_ship_base(1, duty::destroy_self_surprise)), {{2,3},{2,3}});
    bool b2 = dynamic_cast<ext_player*>(p)->kill_self({2,3});

    std::cout << b2;

    delete p_2;
    delete p;

    return 0;
}
