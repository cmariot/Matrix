
#include "matrix.hpp"


// matrix_iterator(ft::Vector<ft::Vector<T> > * matrix, size_type i, size_type j);
template <typename T>
ft::matrix_iterator<T>::matrix_iterator(ft::Vector<ft::Vector<T> > & matrix, size_type i, size_type j) : _matrix(matrix), _i(i), _j(j) {}


// matrix_iterator(const matrix_iterator & copy);
template <typename T>
ft::matrix_iterator<T>::matrix_iterator(const matrix_iterator & copy) : _matrix(copy._matrix), _i(copy._i), _j(copy._j) {}

// ~matrix_iterator();
template <typename T>
ft::matrix_iterator<T>::~matrix_iterator() {}

// matrix_iterator &   operator = (const matrix_iterator & rhs);
template <typename T>
ft::matrix_iterator<T> & ft::matrix_iterator<T>::operator = (const matrix_iterator & rhs)
{
    _matrix = rhs._matrix;
    _i = rhs._i;
    _j = rhs._j;
    return *this;
}

// bool                operator == (const matrix_iterator & rhs) const;
template <typename T>
bool ft::matrix_iterator<T>::operator == (const matrix_iterator & rhs) const
{
    return (_matrix == rhs._matrix && _i == rhs._i && _j == rhs._j);
}

// bool                operator != (const matrix_iterator & rhs) const;
template <typename T>
bool ft::matrix_iterator<T>::operator != (const matrix_iterator & rhs) const
{
    return (_matrix != rhs._matrix || _i != rhs._i || _j != rhs._j);
}

// matrix_iterator &   operator ++ ();
template <typename T>
ft::matrix_iterator<T> & ft::matrix_iterator<T>::operator ++ ()
{
    if (_j < this->_matrix[0].size() - 1)
        _j++;
    else
    {
        _j = 0;
        _i++;
    }
    return *this;
}

// matrix_iterator     operator ++ (int);
template <typename T>
ft::matrix_iterator<T> ft::matrix_iterator<T>::operator ++ (int)
{
    matrix_iterator tmp(*this);
    operator++();
    return tmp;
}

// matrix_iterator &   operator -- ();
template <typename T>
ft::matrix_iterator<T> & ft::matrix_iterator<T>::operator -- ()
{
    if (_j > 0)
        _j--;
    else
    {
        _j = this->_matrix[0].size() - 1;
        _i--;
    }
    return *this;
}

// matrix_iterator     operator -- (int);
template <typename T>
ft::matrix_iterator<T> ft::matrix_iterator<T>::operator -- (int)
{
    matrix_iterator tmp(*this);
    operator--();
    return tmp;
}

// reference           operator * ();
template <typename T>
T & ft::matrix_iterator<T>::operator * ()
{
    return (_matrix)[_i][_j];
}

