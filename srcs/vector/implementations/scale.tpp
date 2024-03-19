/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 21:03:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_TPP
# define SCALE_TPP

# include "vector.hpp"

// Operator * : Scale a vector by a scalar
template <typename T>
ft::Vector<T>   ft::Vector<T>::operator * (const_reference scalar) const
{
    Vector      result(*this);
    iterator    it = result.begin();

    while (it != result.end())
    {
        *it *= scalar;
        ++it;
    }
    return result;
}

// Operator *= : Scale a vector
template <typename T>
ft::Vector<T> & ft::Vector<T>::operator *= (const_reference scalar)
{
    *this = *this * scalar;
    return *this;
}

// Scale : Scale a vector
template <typename T>
ft::Vector<T> & ft::Vector<T>::scl(const_reference scalar)
{
    *this = *this * scalar;
    return *this;
}

#endif