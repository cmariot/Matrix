#include "matrix.hpp"

template <typename T>
ft::Matrix<T> & ft::Matrix<T>::operator=(const Matrix &rhs)
{
    _matrix.clear();
    _matrix.resize(rhs.size()[0]);
    for (size_type i = 0; i < rhs.size()[0]; i++)
    {
        _matrix[i].resize(rhs.size()[1]);
        for (size_type j = 0; j < rhs.size()[1]; j++)
            _matrix[i][j] = rhs._matrix[i][j];
    }
    return (*this);
}

