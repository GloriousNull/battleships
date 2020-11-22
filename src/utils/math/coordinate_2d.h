//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_COORDINATE_2D_H
#define BATTLESHIPS_COORDINATE_2D_H

#include <iostream>

template <typename T> requires std::integral<T> || std::floating_point<T>
class coordinate_2d
{
private:
    T x, y;
public:
    constexpr coordinate_2d() : x{}, y{} {}
    constexpr coordinate_2d(T x, T y) : x{x}, y{y} {}
    [[nodiscard]] constexpr T get_x() const;
    [[nodiscard]] constexpr T get_y() const;
    void set_x(const T &);
    void set_y(const T &);

    template<typename V> requires std::integral<V> || std::floating_point<V>
    friend std::istream & operator>>(std::istream & in, coordinate_2d<V> & point);
};

template<typename T> requires std::integral<T> || std::floating_point<T>
std::istream & operator>>(std::istream & in, coordinate_2d<T> & point)
{
    in >> point.x >> point.y;

    return in;
}

template<typename T> requires std::integral<T> || std::floating_point<T>
constexpr T coordinate_2d<T>::get_x() const
{
    return x;
}

template<typename T> requires std::integral<T> || std::floating_point<T>
constexpr T coordinate_2d<T>::get_y() const
{
    return y;
}

template<typename T> requires std::integral<T> || std::floating_point<T>
void coordinate_2d<T>::set_x(const T & _x)
{
    x = _x;
}

template<typename T> requires std::integral<T> || std::floating_point<T>
void coordinate_2d<T>::set_y(const T & _y)
{
    y = _y;
}

#endif //BATTLESHIPS_COORDINATE_2D_H
