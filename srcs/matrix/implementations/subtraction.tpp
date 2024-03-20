/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:10:31 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 15:52:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

// Operator - : Subtract two matrix
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator - (const Matrix & rhs) const
{
    if (size() != rhs.size())
        throw std::length_error("Matrices are not the same size.");

    Matrix          result(*this);
    iterator        it_res = result.begin();
    const_iterator  it_rhs = rhs.begin();

    while (it_res != result.end())
    {
        *it_res -= *it_rhs;
        ++it_res;
        ++it_rhs;
    }
    return result;
}

// Operator -= : Subtract two matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator -= (const Matrix & rhs)
{
    *this = *this - rhs;
    return (*this);
}

// Method sub : Subtract two matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::sub(const Matrix & rhs)
{
    return (*this -= rhs);
}