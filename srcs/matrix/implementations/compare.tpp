/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:11 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 11:52:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
bool ft::Matrix<T>::operator==(const Matrix &rhs) const
{
    double epsilon = 10e-5;

    if (this->size() != rhs.size())
        return false;
    for (size_type i = 0; i < this->size()[0]; i++)
        for (size_type j = 0; j < this->size()[1]; j++)
            if (abs((*this)[i][j] - rhs[i][j]) > epsilon)
                return false;
    return true;
}

// Operator != : Compare content
template <typename T>
bool ft::Matrix<T>::operator!=(const Matrix &rhs) const
{
    return !(*this == rhs);
}