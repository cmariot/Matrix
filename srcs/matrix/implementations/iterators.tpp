/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:25:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:52:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ITERATORS_TPP
# define MATRIX_ITERATORS_TPP

# include "matrix.hpp"

template <typename T>
typename ft::Matrix<T>::iterator ft::Matrix<T>::begin()
{
    iterator it(_matrix, 0, 0);
    return it;
}

template <typename T>
typename ft::Matrix<T>::const_iterator ft::Matrix<T>::begin() const
{
    const_iterator it(_matrix, 0, 0);
    return it;
}

template <typename T>
typename ft::Matrix<T>::iterator ft::Matrix<T>::end()
{
    iterator it(_matrix, size()[0], size()[1]);
    return it;
}

template <typename T>
typename ft::Matrix<T>::const_iterator ft::Matrix<T>::end() const
{
    const_iterator it(_matrix, size()[0], size()[1]);
    return it;
}

#endif
