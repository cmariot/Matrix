#include "matrix.hpp"

template <typename T>
ft::Matrix<T> & ft::Matrix<T>::operator = (const Matrix & rhs)
{
    if (this == &rhs)
        return (*this);

    if (get_nb_lines() != rhs.get_nb_lines())
        _matrix.resize(rhs.get_nb_lines());

    for (size_type i = 0; i < rhs.size()[0]; i++)
    {
        if (get_nb_columns() != rhs.get_nb_columns())
            _matrix[i].resize(rhs.get_nb_columns());

        for (size_type j = 0; j < rhs.size()[1]; j++)
            _matrix[i][j] = rhs._matrix[i][j];
    }

    return (*this);
}
