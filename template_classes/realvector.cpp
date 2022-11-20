#include <algorithm>
#include "realvector.h"


template <typename T>
RealVector<T>::RealVector() : len{0}, cap{kInitialSize}
{
    data = new T[kInitialSize];
}

template <typename T>
RealVector<T>::~RealVector()
{
    delete[] data;
}

template <typename T>
typename RealVector<T>::size_type RealVector<T>::size() const
{
    return len;
}

template <typename T>
typename RealVector<T>::iterator RealVector<T>::begin()
{
    return data;
}

template <typename T>
typename RealVector<T>::iterator RealVector<T>::end()
{
    return data + len;
}

template <typename T>
typename RealVector<T>::const_iterator RealVector<T>::cbegin() const
{
    return data;
}

template <typename T>
typename RealVector<T>::const_iterator RealVector<T>::cend() const
{
    return cbegin() + size();
}

template <typename T>
void RealVector<T>::grow()
{
    value_type *temp = new value_type[cap*2];
    std::copy(begin(), end(), temp);
    delete[] data;
    data = temp;
    cap *= 2;
}

template <typename T>
void RealVector<T>::insert(size_type pos, const_reference val)
{
    if (len == size())
        grow();
    
    std::copy_backward(begin()+pos, end(), end()+1);
    data[pos] = val;
    ++len;
}


// template <typename T>
// RealVector<T>::RealVector() : len(0), cap(kInitialSize)
// {
//     data = new T[cap];
// }
