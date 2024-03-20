/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:07:06 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 15:23:46 by cmariot          ###   ########.fr       */
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

// const size_type get_nb_columns() const;
template <typename T>
typename ft::Matrix<T>::size_type ft::Matrix<T>::get_nb_columns() const
{
    return _matrix[0].size();
}

// const size_type get_nb_lines() const;
template <typename T>
typename ft::Matrix<T>::size_type ft::Matrix<T>::get_nb_lines() const
{
    return _matrix.size();
}
