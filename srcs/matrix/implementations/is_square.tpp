/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_square.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:30 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 12:26:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
bool ft::Matrix<T>::is_square() const
{
    return (get_nb_columns() == get_nb_lines());
}