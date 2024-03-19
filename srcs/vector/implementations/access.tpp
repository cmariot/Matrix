/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:31 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 20:31:34 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_TPP
# define ACCESS_TPP

# include "vector.hpp"


// Operator [] : Access element
template <typename T>
inline typename ft::Vector<T>::reference ft::Vector<T>::operator [] (const size_type & pos)
{
    return _vector[pos];
}

template <typename T>
inline typename ft::Vector<T>::const_reference ft::Vector<T>::operator [] (const size_type &pos) const
{
    return _vector[pos];
}

#endif