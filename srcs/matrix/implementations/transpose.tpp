/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:50 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:50:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSPOSE_TPP
# define MATRIX_TRANSPOSE_TPP

# include "matrix.hpp"

template <typename T>
ft::Matrix<T> ft::Matrix<T>::transpose() const
{
    // Transpose any m x n matrix to n x m
    const size_type nb_lines = get_nb_lines();
    const size_type nb_columns = get_nb_columns();
    Matrix result(nb_columns, nb_lines);

    for (size_type i = 0; i < nb_lines; ++i)
        for (size_type j = 0; j < nb_columns; ++j)
            result[j][i] = (*this)[i][j];
    return result;
}

#endif