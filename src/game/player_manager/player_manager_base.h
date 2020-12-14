//
// Created by GloriousSir on 10/31/2020.
//

#ifndef SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H
#define SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H

#include <array>

#include "user.h"

template <typename T>
class player_manager_base
{
protected:
    std::array<user<T>, 2> players;
    std::uint8_t active_player_index;
private:
    [[nodiscard]] virtual user<T> & get_user_impl(std::size_t) = 0;
    [[nodiscard]] virtual const user<T> & get_user_impl(std::size_t) const = 0;
    [[nodiscard]] virtual user<T> & get_active_impl() = 0;
    [[nodiscard]] virtual user<T> & get_inactive_impl() = 0;
    [[nodiscard]] virtual std::size_t get_active_id_impl() const = 0;
    virtual void turn_impl() = 0;
public:
    [[nodiscard]] user<T> & get_user(std::size_t);
    [[nodiscard]] const user<T> & get_user(std::size_t) const;
    [[nodiscard]] user<T> & get_active();
    [[nodiscard]] user<T> & get_inactive();
    [[nodiscard]] std::size_t get_active_id() const;
    void turn();
};

template <typename T>
const user<T> & player_manager_base<T>::get_user(std::size_t index) const
{
    return get_user_impl(index);
}

template <typename T>
user<T> & player_manager_base<T>::get_user(std::size_t index)
{
    return get_user_impl(index);
}

template <typename T>
std::size_t player_manager_base<T>::get_active_id() const
{
    return get_active_id_impl();
}

template <typename T>
user<T> & player_manager_base<T>::get_active()
{
    return get_active_impl();
}

template <typename T>
user<T> & player_manager_base<T>::get_inactive()
{
    return get_inactive_impl();
}

template <typename T>
void player_manager_base<T>::turn()
{
    turn_impl();
}

#endif //SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H
