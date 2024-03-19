/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:07:06 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 11:08:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

// Size
template <typename T>
std::map<bool, size_t> ft::Matrix<T>::size() const
{
    return std::map<bool, size_t> {
        {0, _matrix.size()},
        {1, _matrix[0].size()}
    };
}
