/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:33 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:18:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCTORS_TPP
# define CONSTRUCTORS_TPP

# include "vector.hpp"


// Constructor : Default
template <typename T>
ft::Vector<T>::Vector()
{
    _vector = std::vector<T>();
}

// Constructor : Size
template <typename T>
ft::Vector<T>::Vector(size_type size)
{
    _vector = std::vector<T>(size);
}

// Constructor : Size and value
template <typename T>
ft::Vector<T>::Vector(size_type size, const_reference val)
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
    for (size_type i = 0; i < copy.size()[0]; i++)
        for (size_type j = 0; j < copy.size()[1]; j++)
            _vector.push_back(copy[i][j]);
}

// Constructor : Copy from Matrix
template <typename T>
ft::Vector<T>::Vector(std::initializer_list<T> initList)
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