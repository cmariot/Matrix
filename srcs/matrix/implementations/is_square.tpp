/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_square.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:30 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:52:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_IS_SQUARE_TPP
# define MATRIX_IS_SQUARE_TPP

# include "matrix.hpp"

template <typename T>
bool ft::Matrix<T>::is_square() const
{
    return (get_nb_columns() == get_nb_lines());
}

#endif