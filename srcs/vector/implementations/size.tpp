/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:58:47 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 14:58:53 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIZE_TPP
# define SIZE_TPP

# include "vector.hpp"

// Size
template <typename T>
typename ft::Vector<T>::size_type ft::Vector<T>::size() const
{
    return _vector.size();
}

#endif