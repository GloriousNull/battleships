#include <memory>

#include "src/ui/console_user_interface.h"

#include "src/game/game.h"

int main()
{
    game demo(std::make_unique<console_user_interface>());

    demo.run();

    return 0;
}