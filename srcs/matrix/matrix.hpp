/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:37 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 15:07:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{

    template <typename T>
    class Vector;

    template <typename T>
    class Matrix
    {

        // Typedefs
        typedef T                               value_type;
        typedef T &                             reference;
        typedef const T &                       const_reference;
        typedef size_t                          size_type;


        public:

            // Constructors
            Matrix();
            Matrix(size_type rows, size_type columns);
            Matrix(size_type rows, size_type columns, const_reference val);
            Matrix(std::initializer_list<std::initializer_list<T> > initList);
            Matrix(const Matrix &copy);
            Matrix(const ft::Vector<T> &copy);

            // Destructor
            ~Matrix();

            // Size : return the shape of the matrix (rows, columns)
            std::map<bool, size_t> size() const;

            // is_square : return true if the matrix is square
            bool is_square() const;

            // Operator + : Add two matrix
            Matrix operator+(const Matrix &rhs) const
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
            Matrix &operator+=(const Matrix &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Matrices are not the same size.");
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] += rhs[i][j];
                return (*this);
            }

            // Method add : Add two matrix
            Matrix &add(const Matrix &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Matrices are not the same size.");
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] += rhs[i][j];
                return (*this);
            }

            // Operator - : Subtract two matrix
            Matrix operator-(const Matrix &rhs) const
            {
                Matrix result(*this);

                if (result.size() != rhs.size())
                    throw std::length_error("Matrices are not the same size.");
                for (size_type i = 0; i < result.size()[0]; i++)
                    for (size_type j = 0; j < result.size()[1]; j++)
                        result[i][j] -= rhs[i][j];
                return result;
            }

            // Operator -= : Subtract two matrix
            Matrix &operator-=(const Matrix &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Matrices are not the same size.");
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] -= rhs[i][j];
                return (*this);
            }

            // Method sub : Subtract two matrix
            Matrix &sub(const Matrix &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Matrices are not the same size.");
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] -= rhs[i][j];
                return (*this);
            }

            // Operator * : Multiply a matrix by a scalar
            Matrix operator*(const_reference rhs) const
            {
                Matrix result(*this);

                for (size_type i = 0; i < result.size()[0]; i++)
                    for (size_type j = 0; j < result.size()[1]; j++)
                        result[i][j] *= rhs;
                return result;
            }

            // Operator *= : Multiply a matrix by a scalar
            Matrix &operator*=(const_reference rhs)
            {
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] *= rhs;
                return (*this);
            }

            // Method scl : Multiply a matrix by a scalar
            Matrix &scl(const_reference rhs)
            {
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        (*this)[i][j] *= rhs;
                return (*this);
            }


            // Operator << : Display the matrix
            friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
            {

                os << "[";
                for (size_type i = 0; i < matrix.size()[0] ; i++)
                {
                    os << "[";
                    for (size_type j = 0; j < matrix.size()[1]; j++)
                    {
                        os << matrix._matrix[i][j];
                        if (j < matrix.size()[1] - 1)
                            os << ", ";
                    }
                    os << "]";
                    if (i < matrix.size()[0] - 1)
                        os << ", ";
                }
                os << "]";
                return (os);
            }

            // Operator [] : Access element
            std::vector<T> &operator[](size_type pos)
            {
                return _matrix[pos];
            }

            const std::vector<T> &operator[](size_type pos) const
            {
                return _matrix[pos];
            }

            // Operator = : Assign content
            Matrix &operator=(const Matrix &rhs)
            {
                _matrix.clear();
                _matrix.resize(rhs.size()[0]);
                for (size_type i = 0; i < rhs.size()[0]; i++)
                {
                    _matrix[i].resize(rhs.size()[1]);
                    for (size_type j = 0; j < rhs.size()[1]; j++)
                        _matrix[i][j] = rhs._matrix[i][j];
                }
                return (*this);
            }

            // Operator == : Compare content
            bool operator==(const Matrix &rhs) const
            {
                if (this->size() != rhs.size())
                    return false;
                for (size_type i = 0; i < this->size()[0]; i++)
                    for (size_type j = 0; j < this->size()[1]; j++)
                        if ((*this)[i][j] != rhs[i][j])
                            return false;
                return true;
            }

            // Operator != : Compare content
            bool operator!=(const Matrix &rhs) const
            {
                return !(*this == rhs);
            }


        private:
            std::vector<std::vector<T> > _matrix;
    };

}

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
ft::Matrix<T>::Matrix(size_type rows, size_type columns)
{
    _matrix.resize(rows);
    for (size_type i = 0; i < rows; i++)
        _matrix[i].resize(columns);
}

// Constructor : (rows, columns, val)
template <typename T>
ft::Matrix<T>::Matrix(size_type rows, size_type columns, const_reference val)
{
    _matrix.resize(rows);
    for (size_type i = 0; i < rows; i++)
        _matrix[i].resize(columns, val);
}

// Constructor : Initializer list
template <typename T>
ft::Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T> > initList)
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
ft::Matrix<T>::Matrix(const Matrix &copy)
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
{
    _matrix.clear();
}

// Size
template <typename T>
std::map<bool, size_t> ft::Matrix<T>::size() const
{
    return std::map<bool, size_t> {{0, _matrix.size()}, {1, _matrix[0].size()}};
}

// is_square
template <typename T>
bool ft::Matrix<T>::is_square() const
{
    return (_matrix.size() == _matrix[0].size());
}


#endif
