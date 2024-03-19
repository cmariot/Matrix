/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:33 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 10:12:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCTORS_TPP
# define CONSTRUCTORS_TPP

# include "vector.hpp"


// Constructor : Default
template <typename T>
ft::Vector<T>::Vector() : _vector()
{
}

// Constructor : Size
template <typename T>
ft::Vector<T>::Vector(const size_type & size)
{
    _vector = std::vector<T>(size);
}

// Constructor : Size and value
template <typename T>
ft::Vector<T>::Vector(const size_type & size, const_reference val)
{
    _vector = std::vector<T>(size, val);
}

// Constructor : Copy
template <typename T>
ft::Vector<T>::Vector(const Vector &copy)
{
    _vector = std::vector<T>(copy._vector);
}

// Constructor : Copy from Matrix
template <typename T>
ft::Vector<T>::Vector(const Matrix<T> &copy)
{
    const size_type n_rows = copy.size()[0];
    const size_type n_cols = copy.size()[1];

    _vector.reserve(n_rows * n_cols);
    for (size_type i = 0; i < n_rows; i++)
        for (size_type j = 0; j < n_cols; j++)
            _vector.emplace_back(copy[i][j]);
}

// Constructor : Initializer list
template <typename T>
ft::Vector<T>::Vector(const std::initializer_list<T> & initList)
{
    _vector = std::vector<T>(initList);
}

// Destructor
template <typename T>
ft::Vector<T>::~Vector()
{
    _vector.clear();
}

#endif