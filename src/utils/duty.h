//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_DUTY_H
#define BATTLEFIELDS_DUTY_H

template <typename ...ARGS>
class duty
{
private:
    bool fulfilled;
    bool(*work)(ARGS...);
public:
    duty() : fulfilled{false}, work{nullptr} {}
    explicit duty(auto work) : work{work} {}

    void set_work(auto duty);
    [[nodiscard]] bool is_fulfilled() const;
    void try_to_fulfill(ARGS...);
};

template<typename ...ARGS>
void duty<ARGS...>::set_work(auto _work)
{
    work = _work;
}

template<typename ...ARGS>
[[nodiscard]] bool duty<ARGS...>::is_fulfilled() const
{
    return fulfilled;
}

template<typename ...ARGS>
void duty<ARGS...>::try_to_fulfill(ARGS... args)
{
    fulfilled = work(args...);
}

#endif //BATTLEFIELDS_DUTY_H
