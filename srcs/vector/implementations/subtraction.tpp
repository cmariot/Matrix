/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:13:45 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/17 16:26:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"


// Subtraction : Subtract two vectors
template <typename T>
ft::Vector<T>   ft::Vector<T>::operator -(const Vector &rhs) const
{
    // Check if the vectors are the same size
    const size_type _size = this->size();
    if (_size != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    // Subtract the vectors
    Vector result(*this);
    for (size_type i = 0; i < _size; i++)
        result[i] -= rhs[i];
    return result;
}

// Operator -= : Subtract two vectors
template <typename T>
ft::Vector<T> & ft::Vector<T>::operator -=(const Vector &rhs)
{
    *this = *this - rhs;
    return *this;
}

// Subtract : Subtract two vectors
template <typename T>
ft::Vector<T> & ft::Vector<T>::sub(const Vector &rhs)
{
    *this = *this - rhs;
    return *this;
}