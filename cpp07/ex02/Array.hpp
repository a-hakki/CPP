#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstddef>
# include <stdexcept>

template <typename T> class ARRAY {
    public:
        ARRAY();
        ARRAY(unsigned int n);
        ARRAY(const ARRAY& other);
        ARRAY& operator=(const ARRAY& other);
        T& operator[](unsigned int ind);
        const T& operator[](unsigned int ind) const;
        ~ARRAY();
        unsigned int size();
    private :
        T *arr;
        unsigned int _size;
};

#endif //ARRAY_HPP

template <typename T> ARRAY<T>::ARRAY()
    : arr(0), _size(0)
{
}

template <typename T> ARRAY<T>::ARRAY(unsigned int n)
    : arr(new T[n]()), _size(n)
{   
}

template <typename T> ARRAY<T>::ARRAY(const ARRAY<T> &other)
    : arr(new T[other._size]()), _size(other._size)
{
    for (unsigned int  i = 0; i < this->_size; i++)
        arr[i] = other.arr[i];
}


template <typename T> ARRAY<T> &ARRAY<T>::operator=(const ARRAY<T> &other)
{
    if (this != &other)
    {
        delete[] this->arr;
        this->_size = other._size;
        this->arr = new T[other._size]();
        for (unsigned int  i = 0; i < other._size; i++)
            arr[i] = other.arr[i];
    }

    return *this;
}

template <typename T> T &ARRAY<T>::operator[](unsigned int ind)
{
    if( ind >= this->_size )
        throw std::out_of_range("Index out of bounds");

    return arr[ind];
}

template <typename T> const T &ARRAY<T>::operator[](unsigned int ind) const
{
    if( ind >= this->_size )
        throw std::out_of_range("Index out of bounds");

    return arr[ind];
}

template <typename T> ARRAY<T>::~ARRAY()
{
    delete[] arr;
}

template <typename T> unsigned int ARRAY<T>::size()
{
    return this->_size;
}
