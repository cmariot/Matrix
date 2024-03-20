/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:05:42 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 15:54:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

// Constructor : Default
template <typename T>
ft::Matrix<T>::Matrix()
{
    // Create a matrix of 1 rows and 0 columns
    _matrix.resize(1);
    _matrix[0].resize(0);
}

// Constructor : (rows, columns)
template <typename T>
ft::Matrix<T>::Matrix(const size_type & rows, const size_type & columns)
{
    _matrix.resize(rows);
    for (size_type i = 0; i < rows; i++)
        _matrix[i].resize(columns);
}

// Constructor : (rows, columns, val)
template <typename T>
ft::Matrix<T>::Matrix(const size_type & rows, const size_type & columns, const_reference val) : Matrix(rows, columns)
{
    iterator it = begin();
    while (it != end())
    {
        *it = val;
        ++it;
    }
}

// Constructor : Initializer list
template <typename T>
ft::Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T> > & initList)
{
    size_type first_line_len = initList.begin()[0].size();

    _matrix.resize(initList.size());
    for (size_type i = 0; i < initList.size(); i++)
    {
        if (initList.begin()[i].size() != first_line_len)
            throw std::invalid_argument("All lines must have the same length.");
        _matrix[i].resize(initList.begin()[i].size());
        for (size_type j = 0; j < initList.begin()[i].size(); j++)
            _matrix[i][j] = initList.begin()[i].begin()[j];
    }
}

// Constructor : Copy
template <typename T>
ft::Matrix<T>::Matrix(const Matrix & copy)
{
    _matrix.resize(copy.size()[0]);
    for (size_type i = 0; i < copy.size()[0]; i++)
    {
        _matrix[i].resize(copy.size()[1]);
        for (size_type j = 0; j < copy.size()[1]; j++)
            _matrix[i][j] = copy._matrix[i][j];
    }
}

// Constructor : Copy from Vector
template <typename T>
ft::Matrix<T>::Matrix(const ft::Vector<T> &copy)
{
    // If the vector is empty, create a matrix of 1 rows and 0 columns
    if (copy.size() == 0)
    {
        _matrix.resize(1);
        _matrix[0].resize(0);
        return ;
    }
    // Else, create a matrix of n rows and 1 column
    _matrix.resize(copy.size());
    for (size_type i = 0; i < copy.size(); i++)
    {
        _matrix[i].resize(1);
        _matrix[i][0] = copy[i];
    }
}

// Destructor
template <typename T>
ft::Matrix<T>::~Matrix()
{}