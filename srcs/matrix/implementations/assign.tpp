/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:34:14 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:53:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ASSIGN_TPP
# define MATRIX_ASSIGN_TPP

# include "matrix.hpp"

template <typename T>
ft::Matrix<T> & ft::Matrix<T>::operator = (const Matrix & rhs)
{
    if (this == &rhs)
        return (*this);

    if (get_nb_lines() != rhs.get_nb_lines())
        _matrix.resize(rhs.get_nb_lines());

    for (size_type i = 0; i < rhs.size()[0]; i++)
    {
        if (get_nb_columns() != rhs.get_nb_columns())
            _matrix[i].resize(rhs.get_nb_columns());

        for (size_type j = 0; j < rhs.size()[1]; j++)
            _matrix[i][j] = rhs._matrix[i][j];
    }

    return (*this);
}

#endif
