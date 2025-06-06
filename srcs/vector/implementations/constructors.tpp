/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:33 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 10:20:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCTORS_TPP
# define CONSTRUCTORS_TPP

# include "vector.hpp"


// Constructor : Default
template <typename T>
ft::Vector<T>::Vector() : _vector()
{}

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
    const size_type n_lines = copy.get_nb_lines();
    const size_type n_cols = copy.get_nb_columns();

    _vector.reserve(n_lines * n_cols);
    for (size_type i = 0; i < n_lines; i++)
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