/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:10:18 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 11:16:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

// Operator + : Add two matrix
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator +(const Matrix &rhs) const
{
    Matrix result(*this);

    if (result.size() != rhs.size())
        throw std::length_error("Matrices are not the same size.");
    for (size_type i = 0; i < result.size()[0]; i++)
        for (size_type j = 0; j < result.size()[1]; j++)
            result[i][j] += rhs[i][j];
    return result;
}

// Operator += : Add two matrix
template <typename T>
ft::Matrix<T> & ft::Matrix<T>::operator+=(const Matrix &rhs)
{
    *this = *this + rhs;
    return (*this);
}

// Method add : Add two matrix
template <typename T>
ft::Matrix<T> & ft::Matrix<T>::add(const Matrix &rhs)
{
    return (*this += rhs);
}