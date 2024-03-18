/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:16 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 14:57:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_TPP
# define COMPARE_TPP

# include "vector.hpp"

// Operator == : Compare content
template <typename T>
bool ft::Vector<T>::operator == (const Vector & rhs) const
{
    const size_type _size = this->size();

    if (_size != rhs.size())
        return false;
    for (size_type i = 0; i < _size; i++)
        if (_vector[i] != rhs._vector[i])
            return false;
    return true;
}

// Operator != : Compare content
template <typename T>
bool ft::Vector<T>::operator != (const Vector &rhs) const
{
    return !(*this == rhs);
}

#endif