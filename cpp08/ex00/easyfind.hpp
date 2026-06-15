#ifndef EASYFIND__HPP
# define EASYFIND__HPP

# include <iostream>
# include <vector>
# include <list>

# include <algorithm>

template <typename T>
int easyfind(T *container, int target)
{
    typename T::iterator it = std::find(container->begin(), container->end(), target);
    if (it != container->end())
        return (*it);
    throw std::exception();
}

#endif //EASYFIND__HPP