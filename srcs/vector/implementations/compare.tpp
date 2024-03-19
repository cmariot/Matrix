/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:16 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 21:07:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_TPP
# define COMPARE_TPP

# include "vector.hpp"

// Operator == : Compare content
template <typename T>
bool ft::Vector<T>::operator == (const Vector & rhs) const
{
    const_iterator  it = this->begin();
    const_iterator  rhs_it = rhs.begin();

    if (this->size() != rhs.size())
        return false;
    while (it != this->end())
    {
        if (*it != *rhs_it)
            return false;
        ++it;
        ++rhs_it;
    }
    return true;
}

// Operator != : Compare content
template <typename T>
bool ft::Vector<T>::operator != (const Vector &rhs) const
{
    return !(*this == rhs);
}

#endif