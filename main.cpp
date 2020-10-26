#include <iostream>
#include <memory>

#include "src/game/std_game.h"
#include "src/input/console_input_handler.h"
#include "src/ui/console_user_interface.h"

int main()
{
    std::unique_ptr<std_game_base> demo = std::make_unique<std_game>
                                          (
                                           std::make_unique<console_input_handler>(),
                                           std::make_unique<console_user_interface>()
                                          );

    demo->run();

    return 0;
}
