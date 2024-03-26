/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:10:26 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:52:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_MULTIPLICATION_TPP
# define MATRIX_MULTIPLICATION_TPP

# include "matrix.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                 Scale                                      */
/*                                                                            */
/* ************************************************************************** */


// Operator * : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator * (const_reference rhs) const
{
    Matrix      result(*this);
    iterator    it_res = result.begin();

    while (it_res != result.end())
    {
        *it_res *= rhs;
        ++it_res;
    }
    return result;
}


// Operator *= : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator *= (const_reference rhs)
{
    iterator    it = this->begin();

    while (it != this->end())
    {
        *it *= rhs;
        ++it;
    }
    return (*this);
}


// Method scl : Multiply a matrix by a scalar
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::scl(const_reference rhs)
{
    return (*this *= rhs);
}


/* ************************************************************************** */
/*                                                                            */
/*                               Mat_mul                                      */
/*                                                                            */
/* ************************************************************************** */


// Operator * : Multiply a matrix by a matrix
template <typename T>
ft::Matrix<T> ft::Matrix<T>::operator * (const Matrix & rhs) const
{
    const size_type nb_row = size()[0];
    const size_type nb_col = rhs.size()[1];

    if (nb_col != rhs.size()[0])
        throw std::length_error(
            "The number of columns in the first matrix must be equal to the number of rows in the second matrix"
        );

    Matrix  result = Matrix(nb_row, nb_col, 0);

    for (size_type i = 0; i < nb_col; i++)
        for (size_type j = 0; j < nb_row; j++)
            for (size_type k = 0; k < nb_row; k++)
                result[i][j] += (*this)[i][k] * rhs[k][j];
    return result;
}


// Operator *= : Multiply a matrix by a matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator*=(const Matrix<T> & rhs)
{
    *this = *this * rhs;
    return (*this);
}



// Method mul_mat : Multiply two matrix
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::mul_mat(const Matrix & rhs)
{
    return (*this *= rhs);
}


/* ************************************************************************** */
/*                                                                            */
/*                               Vec_mul                                      */
/*                                                                            */
/* ************************************************************************** */


// Operator * : Multiply a matrix by a vector
template <typename T>
ft::Vector<T> ft::Matrix<T>::operator*(const Vector<T> & rhs) const
{
    const size_type m = size()[0];
    const size_type n = size()[1];

    if (n != rhs.size())
        throw std::length_error("The number of columns in the matrix must be equal to the number of rows in the vector");

    ft::Vector<T> result = ft::Vector<T>(m);

    for (size_type i = 0 ; i < m ; i++)
        for (size_type j = 0 ; j < n ; j++)
            result[i] += (*this)[i][j] * rhs[j];
    return result;
}


// Operator *= : Multiply a matrix by a vector
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::operator*=(const Vector<T> & rhs)
{
    *this = *this * rhs;
    return (*this);
}


// Method mul_vec : Multiply a matrix by a vector
template <typename T>
ft::Matrix<T> &ft::Matrix<T>::mul_vec(const Vector<T> & rhs)
{
    return (*this *= rhs);
}

#endif
