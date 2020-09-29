#include "players/ext_player.h"
#include "players/std_player.h"
#include "ships/typed_ship_base.h"
#include "ships/std_ship_base.h"
#include "duty.h"

#include "iostream"

int main()
{
    std::shared_ptr<std_player_base> p = std::make_shared<ext_player>();
    std::shared_ptr<std_player_base> p_2 = std::make_shared<ext_player>();

    bool b1 = p_2->place_ship(std::make_shared<typed_ship_base>(typed_ship_base(1, duty::destroy_self_surprise)), {{2,3},{2,3}});
    auto[b4,b5] = p->attack(p_2, {2,3});
    auto _duty = dynamic_cast<ext_player*>(p.get())->get_duty();


    std::cout << b1 << ' ' << b4 << ' ' << b5 << ' ' << (int)_duty;

    return 0;
}
