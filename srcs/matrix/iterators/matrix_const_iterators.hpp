/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_const_iterators.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:34:53 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 09:53:43 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_CONST_ITERATORS_HPP
# define MATRIX_CONST_ITERATORS_HPP

# include "matrix.hpp"

namespace ft
{

    template <typename T>
    class Vector;

    template <typename T>
    class Matrix;

    template <typename T>
    class matrix_const_iterator
    {

        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;

        public:

            matrix_const_iterator(const ft::Vector<ft::Vector<T>> & matrix, const size_type & i, const size_type & j);
            matrix_const_iterator(const matrix_const_iterator &copy);
            ~matrix_const_iterator();

            matrix_const_iterator &operator=(const matrix_const_iterator &rhs);
            bool operator==(const matrix_const_iterator &rhs) const;
            bool operator!=(const matrix_const_iterator &rhs) const;
            matrix_const_iterator &operator++();
            matrix_const_iterator operator++(int);
            matrix_const_iterator &operator--();
            matrix_const_iterator operator--(int);
            const_reference operator*() const;

        private:

            const ft::Vector<ft::Vector<T>> &_matrix;
            size_type _i;
            size_type _j;

    };

    template <typename T>
    matrix_const_iterator<T>::matrix_const_iterator(const ft::Vector<ft::Vector<T>> &matrix, const size_type &i, const size_type &j)
        : _matrix(matrix), _i(i), _j(j)
    {}

    template <typename T>
    matrix_const_iterator<T>::matrix_const_iterator(const matrix_const_iterator &copy)
        : _matrix(copy._matrix), _i(copy._i), _j(copy._j)
    {}

    template <typename T>
    matrix_const_iterator<T>::~matrix_const_iterator()
    {}

    template <typename T>
    matrix_const_iterator<T> &matrix_const_iterator<T>::operator=(const matrix_const_iterator &rhs)
    {
        _matrix = rhs._matrix;
        _i = rhs._i;
        _j = rhs._j;
        return *this;
    }

    template <typename T>
    bool matrix_const_iterator<T>::operator==(const matrix_const_iterator &rhs) const
    {
        if (_i >= _matrix.size() || _j >= _matrix[0].size())
            return true;
        return (_matrix == rhs._matrix && _i == rhs._i && _j == rhs._j && _i < _matrix.size() && _j < _matrix[0].size());
    }

    template <typename T>
    bool matrix_const_iterator<T>::operator!=(const matrix_const_iterator &rhs) const
    {
        if (_i >= _matrix.size() || _j >= _matrix[0].size())
            return false;
        return (_matrix != rhs._matrix || _i != rhs._i || _j != rhs._j || _i >= _matrix.size() || _j >= _matrix[0].size());
    }

    template <typename T>
    matrix_const_iterator<T> &matrix_const_iterator<T>::operator++()
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

    template <typename T>
    matrix_const_iterator<T> matrix_const_iterator<T>::operator++(int)
    {
        matrix_const_iterator tmp(*this);
        operator++();
        return tmp;
    }

    template <typename T>
    matrix_const_iterator<T> &matrix_const_iterator<T>::operator--()
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

    template <typename T>
    matrix_const_iterator<T> matrix_const_iterator<T>::operator--(int)
    {
        matrix_const_iterator tmp(*this);
        operator--();
        return tmp;
    }

    template <typename T>
    typename matrix_const_iterator<T>::const_reference matrix_const_iterator<T>::operator*() const
    {
        return _matrix[_i][_j];
    }

}

#endif
