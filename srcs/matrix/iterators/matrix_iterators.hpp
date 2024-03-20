/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:49:56 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 09:52:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ITERATORS_HPP
# define MATRIX_ITERATORS_HPP

# include "matrix.hpp"

namespace ft {

    template <typename T>
    class matrix_iterator
    {

        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;

        public:

            matrix_iterator(ft::Vector<ft::Vector<T>> & matrix, const size_type & i, const size_type & j);
            matrix_iterator(const matrix_iterator &copy);
            ~matrix_iterator();

            matrix_iterator &operator=(const matrix_iterator &rhs);
            bool operator==(const matrix_iterator &rhs) const;
            bool operator!=(const matrix_iterator &rhs) const;
            matrix_iterator &operator++();
            matrix_iterator operator++(int);
            matrix_iterator &operator--();
            matrix_iterator operator--(int);
            reference operator*();

        private:

            ft::Vector<ft::Vector<T> > &_matrix;
            size_type _i;
            size_type _j;

    };

    template <typename T>
    ft::matrix_iterator<T>::matrix_iterator(ft::Vector<ft::Vector<T>> &matrix, const size_type &i, const size_type &j)
        : _matrix(matrix), _i(i), _j(j)
    {}

    template <typename T>
    ft::matrix_iterator<T>::matrix_iterator(const matrix_iterator &copy)
        : _matrix(copy._matrix), _i(copy._i), _j(copy._j)
    {}

    template <typename T>
    ft::matrix_iterator<T>::~matrix_iterator()
    {}

    template <typename T>
    ft::matrix_iterator<T> &ft::matrix_iterator<T>::operator=(const matrix_iterator &rhs)
    {
        _matrix = rhs._matrix;
        _i = rhs._i;
        _j = rhs._j;
        return *this;
    }

    template <typename T>
    bool ft::matrix_iterator<T>::operator==(const matrix_iterator &rhs) const
    {
        if (_i >= _matrix.size() || _j >= _matrix[0].size())
            return true;
        return (_matrix == rhs._matrix && _i == rhs._i && _j == rhs._j && _i < _matrix.size() && _j < _matrix[0].size());
    }

    template <typename T>
    bool ft::matrix_iterator<T>::operator!=(const matrix_iterator &rhs) const
    {
        if (_i >= _matrix.size() || _j >= _matrix[0].size())
            return false;
        return (_matrix != rhs._matrix || _i != rhs._i || _j != rhs._j || _i >= _matrix.size() || _j >= _matrix[0].size());
    }

    template <typename T>
    ft::matrix_iterator<T> &ft::matrix_iterator<T>::operator++()
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
    ft::matrix_iterator<T> ft::matrix_iterator<T>::operator++(int)
    {
        matrix_iterator tmp(*this);
        operator++();
        return tmp;
    }

    template <typename T>
    ft::matrix_iterator<T> &ft::matrix_iterator<T>::operator--()
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
    ft::matrix_iterator<T> ft::matrix_iterator<T>::operator--(int)
    {
        matrix_iterator tmp(*this);
        operator--();
        return tmp;
    }

    template <typename T>
    T &ft::matrix_iterator<T>::operator*()
    {
        return (_matrix)[_i][_j];
    }

}

#endif
