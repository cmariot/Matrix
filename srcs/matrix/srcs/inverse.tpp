/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:53:06 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 15:42:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
ft::Matrix<T> ft::Matrix<T>::adjoint() const
{
    if (!is_square())
        throw std::invalid_argument("Matrix must be square to have an adjoint");

    Matrix<T> result(size()[0], size()[1]);

    for (size_t i = 0; i < size()[0]; i++)
    {
        for (size_t j = 0; j < size()[1]; j++)
        {
            result[i][j] = cofactor(i, j);
        }
    }
    result = result.transpose();
    return result;
};

template <typename T>
ft::Matrix<T> ft::Matrix<T>::inverse() const
{
    if (!is_square())
        throw std::invalid_argument("Matrix must be square to be inversed");

    T det = determinant();

    if (det == 0)
        throw std::invalid_argument("Matrix must have a non-zero determinant to be inversed");

    Matrix<T> adj = adjoint();

    Matrix<T> result(adj);

    for (size_t i = 0; i < size()[0]; i++)
    {
        for (size_t j = 0; j < size()[1]; j++)
        {
            result[i][j] = adj[i][j] / det;
        }
    }


    return result;
};