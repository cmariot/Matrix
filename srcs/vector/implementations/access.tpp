/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:31 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:41:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_TPP
# define ACCESS_TPP

# include "vector.hpp"


// Operator [] : Access element
template <typename T>
typename ft::Vector<T>::reference ft::Vector<T>::operator [] (size_type pos)
{
    return _vector[pos];
}

template <typename T>
typename ft::Vector<T>::const_reference ft::Vector<T>::operator [] (size_type pos) const
{
    return _vector[pos];
}

#endif