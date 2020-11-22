//
// Created by spector on 10/19/20.
//

#include "concurrent_console_input_handler.h"

#include "../../ships/std_ship/std_ship.h"
#include "../../ships/ext_ship/ext_ship_mine.h"
#include "../../ships/ext_ship/ext_ship_minesweeper.h"

void concurrent_console_input_handler::start_impl(volatile const bool & running)
{
    input_thread = std::thread
    {
        [this, &running]()
        {
            std::cout << "Thread " << &std::this_thread::get_id << " started\n";

            while (running)
            {
                char choice;
                if (!running)
                    break;
                std::cin >> choice;
                switch (choice)
                {
                    case 'n':
                    {
                        game_event ev{game_event::event_type::change_nick};
                        if (!running)
                            break;
                        std::cin >> ev.change_nick.name;

                        this->_mutex.lock();
                        this->pending_events.push(ev);
                        this->_mutex.unlock();

                        break;
                    }
                    case 'a':
                    {
                        game_event ev{game_event::event_type::attack};
                        if (!running)
                            break;
                        std::cin >> ev.attack.coordinate_to_attack;
                        this->_mutex.lock();
                        this->pending_events.push(ev);
                        this->_mutex.unlock();

                        break;
                    }
                    case 'p':
                    {
                        game_event ev{game_event::event_type::ship_placement};

                        char ship_type;
                        std::size_t length;
                        if (!running)
                            break;
                        std::cin >> ship_type >> length;
                        switch (ship_type)
                        {
                            case 'b':
                                ev.ship_placement.ship_to_place = std::make_shared<std_ship>(length);
                                break;
                            case 'm':
                                ev.ship_placement.ship_to_place = std::make_shared<ext_ship_mine>(length);
                                break;
                            case 's':
                                ev.ship_placement.ship_to_place = std::make_shared<ext_ship_minesweeper>(length);
                                break;
                            default:
                                ev.ship_placement.ship_to_place = nullptr;
                                break;
                        }
                        coordinate_2d<std::size_t> first, second;
                        if (!running)
                            break;
                        std::cin >> first >> second;
                        ev.ship_placement.placement_space = {first, second};
                        this->_mutex.lock();
                        this->pending_events.push(ev);
                        this->_mutex.unlock();

                        break;
                    }
                    case 'q':
                    {
                        game_event ev{game_event::event_type::quit};
                        this->_mutex.lock();
                        this->pending_events.push(ev);
                        this->_mutex.unlock();
                    }
                    default:
                        break;
                }
            }

            std::cout << "Thread " << &std::this_thread::get_id << " finished\n";
        }
    };
}

void concurrent_console_input_handler::end_impl()
{
    this->input_thread.join();
}

bool concurrent_console_input_handler::poll_event_impl(game_event & _event)
{
    std::scoped_lock lock{this->_mutex};

    if (!this->pending_events.empty())
    {
        _event = this->pending_events.back();
        this->pending_events.pop();

        return true;
    }

    return false;
}