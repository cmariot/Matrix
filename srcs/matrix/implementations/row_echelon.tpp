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

#ifndef MATRIX_ROW_ECHELON_TPP
# define MATRIX_ROW_ECHELON_TPP

# include "matrix.hpp"


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

    Matrix result(*this);

    size_t lines = result.get_nb_lines();
    size_t cols = result.get_nb_columns();

    size_t current_line = 0;
    size_t current_col = 0;

    while (current_line < lines && current_col < cols)
    {

        // Find the pivot line index
        size_t pivot_line_index = current_line;
        for (size_t k = current_line + 1; k < lines; k++)
            if (std::abs(result[k][current_col]) > std::abs(result[pivot_line_index][current_col]))
                pivot_line_index = k;

        // Swap the pivot line with the current line if a pivot was found
        if (pivot_line_index != current_line)
            std::swap(result[current_line], result[pivot_line_index]);

        // Divide all the elements of the line by the pivot value
        T pivot_value = result[current_line][current_col];
        if (pivot_value == T())
        {
            current_col++;
            continue;
        }
        for (size_t k = current_col; k < cols; k++)
            result[current_line][k] /= pivot_value;

        // Use the pivot row to eliminate the first column in all other lines
        for (size_t k = 0; k < lines; k++)
        {
            if (k == current_line)
                continue;
            T factor = result[k][current_col];
            for (size_t l = current_col; l < cols; l++)
                result[k][l] -= factor * result[current_line][l];
        }

        current_line++;
        current_col++;
    }

    return result;
}

#endif