/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:01:49 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 14:01:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
ft::Vector<T> &ft::Matrix<T>::operator [] (const size_type & pos)
{
    return _matrix[pos];
}

template <typename T>
const ft::Vector<T> & ft::Matrix<T>::operator [] (const size_type & pos) const
{
    return _matrix[pos];
}
