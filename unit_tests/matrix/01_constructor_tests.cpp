/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:54 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 18:37:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <vector>

int m_constructor_test(void)
{
    {
        // Default constructor
        ft::Matrix<int> ft_default;

        // Constructor with row and col
        ft::Matrix<int> ft_row_col(5, 10);

        // Constructor with row, col and value
        ft::Matrix<int> ft_row_col_val(5, 10, 42);

        // Constructor with vector of vector
        std::vector<std::vector<int> > vec(5, std::vector<int>(10, 42));
        ft::Matrix<int> ft_matrix(vec);

        // Copy constructor
        ft::Matrix<int> ft_matrix_copy(ft_matrix);

    }

    return (0);
}
