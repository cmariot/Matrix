/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:53 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 10:16:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
T ft::Matrix<T>::trace() const
{
    /*
    Sum of the elements on the main diagonal of a square matrix.
    */

    if (!is_square())
        throw std::length_error("The matrix must be square.");

    value_type      result = T();
    const size_type _size = get_nb_lines();

    for (size_type i = 0; i < _size; i++)
        result += (*this)[i][i];
    return result;
}