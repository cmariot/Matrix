/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:50 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 11:52:51 by cmariot          ###   ########.fr       */
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

    Matrix result(size()[1], size()[0]);

    for (size_type i = 0; i < size()[0]; i++)
        for (size_type j = 0; j < size()[1]; j++)
            result[j][i] = (*this)[i][j];
    return result;
}