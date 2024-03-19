/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:10:26 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 11:21:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

// Operator * : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator * (const_reference rhs) const
{
    Matrix result(*this);

    for (size_type i = 0; i < result.size()[0]; i++)
        for (size_type j = 0; j < result.size()[1]; j++)
            result[i][j] *= rhs;
    return result;
}

// Operator * : Multiply a matrix by a matrix
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator*(const Matrix &rhs) const
{
    const size_type nb_col = size()[0];
    const size_type nb_row = size()[1];
    Matrix result(nb_col, nb_row);

    if (nb_col != rhs.size()[0])
        throw std::length_error("The number of columns in the first matrix must be equal to the number of rows in the second matrix");

    for (size_type i = 0; i < nb_col; i++)
        for (size_type j = 0; j < nb_row; j++)
            for (size_type k = 0; k < nb_row; k++)
                result[i][j] += (*this)[i][k] * rhs[k][j];
    return result;
}

// Operator * : Multiply a matrix by a vector
template <typename T>
ft::Vector<T> ft::Matrix<T>::operator*(const Vector<T> &rhs) const
{
    const size_type m = size()[0];
    const size_type n = size()[1];

    ft::Vector<T> result = ft::Vector<T>(m);

    if (n != rhs.size())
        throw std::length_error("The number of columns in the matrix must be equal to the number of rows in the vector");

    for (size_type i = 0 ; i < m ; i++)
        for (size_type j = 0 ; j < n ; j++)
            result[i] += (*this)[i][j] * rhs[j];

    return result;
}

// Operator *= : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator*=(const_reference rhs)
{
    for (size_type i = 0; i < this->size()[0]; i++)
        for (size_type j = 0; j < this->size()[1]; j++)
            (*this)[i][j] *= rhs;
    return (*this);
}

// Operator *= : Multiply a matrix by a matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    *this = *this * rhs;
    return (*this);
}

// Operator *= : Multiply a matrix by a vector
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator*=(const Vector<T> &rhs)
{
    *this = *this * rhs;
    return (*this);
}

// Method scl : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::scl(const_reference rhs)
{
    for (size_type i = 0; i < this->size()[0]; i++)
        for (size_type j = 0; j < this->size()[1]; j++)
            (*this)[i][j] *= rhs;
    return (*this);
}

// Method mul_mat : Multiply two matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::mul_mat(const Matrix &rhs)
{
    return (*this *= rhs);
}

// Method mul_vec : Multiply a matrix by a vector
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::mul_vec(const Vector<T> &rhs)
{
    return (*this *= rhs);
}