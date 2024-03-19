/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:13:45 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 21:15:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBTRACTION_TPP
# define SUBTRACTION_TPP

# include "vector.hpp"

// Subtraction : Subtract two vectors
template <typename T>
ft::Vector<T>   ft::Vector<T>::operator - (const Vector &rhs) const
{
    if (this->size() != rhs.size())
        throw std::length_error("Vectors are not the same size.");
    Vector          result(*this);
    const_iterator  it_rhs = rhs.begin();
    iterator        it_result = result.begin();
    while (it_result != result.end())
    {
        *it_result -= *it_rhs;
        ++it_result;
        ++it_rhs;
    }
    return result;
}

// Operator -= : Subtract two vectors
template <typename T>
ft::Vector<T> & ft::Vector<T>::operator -= (const Vector &rhs)
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

#endif