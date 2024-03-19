/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:35 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 10:20:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cmath>


template <typename T>
T ft::Matrix<T>::minor(size_type i, size_type j) const
{
    if (is_square() == false)
        throw std::invalid_argument("The matrix must be square to have a minor.");

    size_type _size = size()[0];

    Matrix<T> minor_matrix(_size - 1, _size - 1);

    size_type x = 0;
    size_type y = 0;

    for (size_type k = 0; k < _size; k++)
    {
        if (k != i)
        {
            for (size_type l = 0; l < _size; l++)
            {
                if (l != j)
                {
                    minor_matrix[x][y] = _matrix[k][l];
                    y++;
                }
            }
            x++;
            y = 0;
        }
    }

    return (minor_matrix.determinant());
}


template <typename T>
T ft::Matrix<T>::cofactor(size_type i, size_type j) const
{
    return (std::pow(-1, i + j) * minor(i, j));
}


template <typename T>
T ft::Matrix<T>::determinant() const
{
    if (is_square() == false)
        throw std::invalid_argument("The matrix must be square to have a determinant.");

    size_type _size = size()[0];

    // If the matrix is 1x1, the determinant is the only element of the matrix
    if (_size == 1)
        return (_matrix[0][0]);

    // If the matrix is 2x2, the determinant is calculated as ad - bc
    // Area of the parallelogram formed by the vectors (a, b) and (c, d)
    if (_size == 2)
        return (_matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0]);

    // If the matrix is 3x3, the determinant is calculated as a(ei − fh) − b(di − fg) + c(dh − eg)
    // Volume of the parallelepiped formed by the vectors (a, b, c), (d, e, f) and (g, h, i)
    if (_size == 3)
    {
        return (_matrix[0][0] * (_matrix[1][1] * _matrix[2][2] - _matrix[1][2] * _matrix[2][1]) -
                _matrix[0][1] * (_matrix[1][0] * _matrix[2][2] - _matrix[1][2] * _matrix[2][0]) +
                _matrix[0][2] * (_matrix[1][0] * _matrix[2][1] - _matrix[1][1] * _matrix[2][0]));
    }

    // If the matrix is larger than 3x3, the determinant is calculated using the Laplace expansion
    T det = T();

    // Find the row with the most zeros
    size_type max_zeros = 0;
    size_type max_zeros_index = 0;

    for (size_type i = 0; i < _size; i++)
    {
        size_type zeros = 0;
        for (size_type j = 0; j < _size; j++)
        {
            if (_matrix[i][j] == 0)
                zeros++;
        }
        if (zeros > max_zeros)
        {
            max_zeros = zeros;
            max_zeros_index = i;
        }
    }

    for (size_type i = 0; i < _size; i++)
    {
        if (_matrix[max_zeros_index][i] != 0)
        {
            det += _matrix[max_zeros_index][i] * cofactor(max_zeros_index, i);
        }
    }

    return (det);
}
