/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:14 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 10:16:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_RANK_TPP
# define MATRIX_RANK_TPP

# include "matrix.hpp"

template <typename T>
typename ft::Matrix<T>::size_type ft::Matrix<T>::rank() const
{

    /*
    The rank of a matrix is the number of non-zero rows in its row echelon form.
    */

    Matrix<T> row_echelon_form = row_echelon();
    size_type rank_value = 0;

    for (size_type i = 0; i < row_echelon_form.size()[0]; i++)
    {
        bool full_zero = true;

        for (size_type j = 0; j < row_echelon_form.size()[1]; j++)
        {
            if (row_echelon_form[i][j] != T())
            {
                full_zero = false;
                break;
            }
        }
        if (full_zero == false)
            ++rank_value;
    }

    return rank_value;
}

#endif