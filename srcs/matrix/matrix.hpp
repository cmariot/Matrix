/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:37 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 18:37:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace ft
{

    template <typename T>
    class Matrix
    {

        // Typedefs
        typedef T                               value_type;
        typedef T &                             reference;
        typedef const T &                       const_reference;
        typedef T *                             pointer;
        typedef const T *                       const_pointer;
        typedef std::ptrdiff_t                  difference_type;
        typedef size_t                          size_type;
        typedef std::vector<T>                  row_type;
        typedef std::vector<std::vector<T> >    matrix_type;
        typedef std::vector<T>                  column_type;
        typedef std::vector<std::vector<T> > &  matrix_reference;


        public:

            // Constructors
            Matrix();
            Matrix(size_type rows, size_type columns);
            Matrix(size_type rows, size_type columns, const_reference val);
            Matrix(matrix_reference matrix);
            Matrix(const Matrix &copy);

            // Destructor
            ~Matrix();

            // Size : return the shape of the matrix (rows, columns)
            std::pair<uint64_t, uint64_t> size() const;

        private:
            std::vector<std::vector<T> > _matrix;
    };

}

// Constructor : Default
template <typename T>
ft::Matrix<T>::Matrix()
{
    // Create a matrix of 1 rows and 0 columns
    _matrix.resize(0);
}

// Constructor : (rows, columns)
template <typename T>
ft::Matrix<T>::Matrix(size_type rows, size_type columns)
{
    // Create a matrix of rows rows and columns columns
    _matrix.resize(rows);
    for (uint64_t i = 0; i < rows; i++)
        _matrix[i].resize(columns);
}

// Constructor : (rows, columns, val)
template <typename T>
ft::Matrix<T>::Matrix(size_type rows, size_type columns, const_reference val)
{
    // Create a matrix of rows rows and columns columns
    _matrix.resize(rows);
    for (uint64_t i = 0; i < rows; i++)
        _matrix[i].resize(columns, val);
}

// Constructor : (matrix)
template <typename T>
ft::Matrix<T>::Matrix(matrix_reference matrix)
{
    // Create a matrix of rows rows and columns columns with the values of matrix
    _matrix.resize(matrix.size());
    for (uint64_t i = 0; i < matrix.size(); i++)
    {
        _matrix[i].resize(matrix[i].size());
        for (uint64_t j = 0; j < matrix[i].size(); j++)
            _matrix[i][j] = matrix[i][j];
    }
}

// Constructor : Copy
template <typename T>
ft::Matrix<T>::Matrix(const Matrix &copy)
{
    // Create a matrix of rows rows and columns columns
    _matrix.resize(copy.size().first);
    for (uint64_t i = 0; i < copy.size().first; i++)
        _matrix[i].resize(copy.size().second);
}

// Destructor
template <typename T>
ft::Matrix<T>::~Matrix()
{
    _matrix.clear();
}

// Size
template <typename T>
std::pair<uint64_t, uint64_t> ft::Matrix<T>::size() const
{
    const uint64_t rows = _matrix.size();

    if (rows == 0)
        return (std::make_pair<uint64_t, uint64_t>(0, 0));
    return (std::make_pair<uint64_t, uint64_t>(_matrix.size(), _matrix[0].size()));
}

#endif
