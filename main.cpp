#include <memory>

#include "src/ui/console_user_interface.h"

#include "src/game/game.h"
#include "src/game/game_state/std_game_state.h"

int main()
{
    game demo(std::make_unique<console_user_interface>(),
              std::make_unique<std_game_state>());

    demo.run();

    return 0;
}