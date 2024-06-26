/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:11 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:53:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_COMPARE_TPP
# define MATRIX_COMPARE_TPP

# include "matrix.hpp"

template <typename T>
bool ft::Matrix<T>::operator == (const Matrix & rhs) const
{
    if (this->size() != rhs.size())
        return false;

    const T         epsilon = 10e-5;
    const_iterator  it = this->begin();
    const_iterator  it_rhs = rhs.begin();

    while (it != this->end())
    {
        if (std::abs(*it - *it_rhs) > epsilon)
            return false;
        ++it;
        ++it_rhs;
    }
    return true;
}

// Operator != : Compare content
template <typename T>
bool ft::Matrix<T>::operator != (const Matrix & rhs) const
{
    return !(*this == rhs);
}

#endif