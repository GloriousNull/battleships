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
    const char * duty_message;
public:
    duty() : fulfilled{false}, work{nullptr} {}
    duty(auto work, const char * m) : work{work}, duty_message{m} {}

    void set_work(auto duty);
    [[nodiscard]] bool is_fulfilled() const;
    void try_to_fulfill(ARGS...);
    const char * get_message() const;
};

template<typename ...ARGS>
const char * duty<ARGS...>::get_message() const
{
    return duty_message;
}

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
