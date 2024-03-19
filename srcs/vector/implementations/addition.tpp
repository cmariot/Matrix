/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:13:51 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 21:14:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITION_TPP
# define ADDITION_TPP

# include "vector.hpp"


// Addition : Add two vectors and return the result
template <typename T>
ft::Vector<T>  ft::Vector<T>::operator + (const Vector<T> &rhs) const
{
    // Check if the vectors are the same size
    if (this->size() != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    Vector          result(*this);
    iterator        it_result = result.begin();
    const_iterator  it_rhs = rhs.begin();
    while (it_result != result.end())
    {
        *it_result += + *it_rhs;
        ++it_result;
        ++it_rhs;
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