/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:50 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 10:15:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
ft::Matrix<T> ft::Matrix<T>::transpose() const
{
    /*
    A matrix obtained from a given matrix by interchanging the rows and columns.
    */

    if (!is_square())
        throw std::length_error("The matrix must be square.");

    const size_type _size = get_nb_lines();
    Matrix          result(_size, _size);

    for (size_type i = 0; i < _size; i++)
        for (size_type j = 0; j < _size; j++)
            result[j][i] = (*this)[i][j];
    return result;
}