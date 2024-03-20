/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_echelon.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:22 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 16:57:07 cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"


template <typename T>
ft::Matrix<T>   ft::Matrix<T>::row_echelon() const
{
    /*

    Row reduction algorithm to transform a matrix into reduced
    row-echelon form.

    - Start with the given augmented matrix.
    - Find the row with the largest absolute value in the first column and swap
      that row with the first row.
    - Divide the first row by the pivot element to make it equal to 1.
    - Use the first row to eliminate the first column in all other lines by
      subtracting the appropriate multiple of the first row from each row.
    - Repeat steps 2-4 for the remaining columns, using the row with the largest
      absolute value as the pivot row for each column.
    - Back-substitute to obtain the values of the unknowns.

    */

    Matrix mat(*this);

    size_t lines = mat.get_nb_lines();
    size_t cols = mat.get_nb_columns();

    size_t i = 0;
    size_t j = 0;

    while (i < lines && j < cols)
    {

        // Find the pivot row
        size_t max_row = i;
        for (size_t k = i + 1; k < lines; k++)
        {
            if (std::abs(mat[k][j]) > std::abs(mat[max_row][j]))
                max_row = k;
        }

        // Swap the pivot row with the current row
        if (max_row != i)
            std::swap(mat[i], mat[max_row]);

        // If the pivot element is zero, move to the next column
        if (mat[i][j] == 0)
        {
            j++;
            continue;
        }

        // Divide the pivot row by the pivot element
        T pivot = mat[i][j];
        for (size_t k = j; k < cols; k++)
            mat[i][k] /= pivot;

        // Use the pivot row to eliminate the first column in all other lines
        for (size_t k = 0; k < lines; k++)
        {
            if (k == i)
                continue;

            T factor = mat[k][j];
            for (size_t l = j; l < cols; l++)
                mat[k][l] -= factor * mat[i][l];
        }

        i++;
        j++;
    }

    return mat;
}
