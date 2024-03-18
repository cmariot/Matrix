/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:13:51 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:51:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITION_TPP
# define ADDITION_TPP

# include "vector.hpp"


// Addition : Add two vectors and return the result
template <typename T>
ft::Vector<T> ft::Vector<T>::operator + (const Vector<T> &rhs) const
{
    // Check if the vectors are the same size
    const size_type _size = this->size();
    if (_size != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    Vector          result(*this);
    const_iterator  it = this->begin();
    const_iterator  it_rhs = rhs.begin();
    iterator        it_result = result.begin();
    while (it != this->end())
    {
        *it_result = *it + *it_rhs;
        ++it;
        ++it_rhs;
        ++it_result;
    }
    return result;
}

// Operator += : Add a vector to the current vector
template <typename T>
ft::Vector<T> & ft::Vector<T>::operator += (const Vector<T> & rhs)
{
    *this = *this + rhs;
    return *this;
}

// add : Add a vector to the current vector
template <typename T>
ft::Vector<T> & ft::Vector<T>::add(const Vector & rhs)
{
    *this = *this + rhs;
    return *this;
}

#endif