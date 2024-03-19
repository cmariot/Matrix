#include "matrix.hpp"

template <typename T>
ft::Vector<T> &ft::Matrix<T>::operator[](size_type pos)
{
    return _matrix[pos];
}

template <typename T>
const ft::Vector<T> & ft::Matrix<T>::operator[](size_type pos) const
{
    return _matrix[pos];
}
