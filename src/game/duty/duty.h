//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_DUTY_H
#define BATTLEFIELDS_DUTY_H

#include <functional>

template <typename ...ARGS>
class duty
{
private:
    bool fulfilled{false};
    std::function<bool(ARGS...)> work{nullptr};
public:
    explicit duty(std::function<bool(ARGS...)> && work) : work{work} {}
    [[nodiscard]] bool is_fulfilled() const;
    void try_to_fulfill(ARGS &&...);
};

template<typename ...ARGS>
[[nodiscard]] bool duty<ARGS...>::is_fulfilled() const
{
    return fulfilled;
}

template<typename ...ARGS>
void duty<ARGS...>::try_to_fulfill(ARGS &&... args)
{
    fulfilled = work(std::forward<ARGS>(args)...);
}

#endif //BATTLEFIELDS_DUTY_H
