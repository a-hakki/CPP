#ifndef ITER_HPP

# define ITER_HPP

# include <cstddef>
#include <iostream>


template <typename T, typename Func> void iter(T *array, const size_t length, Func f){
    if (!array || length < 1)
        return ;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T, typename Func> void iter(const T *array, const size_t length, Func f){
    if (!array || length < 1)
        return ;

    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif // ITER_HPP