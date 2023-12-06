/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_scale_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:09:50 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/06 13:52:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"


int m_scale_test(void)
{
    {
        // Operator *

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        if (m1 * 2 != ft::Matrix<double>({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}))
            return (1);

        // Does not modify the matrix
        if (m1 != ft::Matrix<double>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9} }))
            return (2);
    }

    {
        // Method scale

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        if (m1.scl(2) != ft::Matrix<double>({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}))
            return (3);

        // Modifies the vector v1
        if (m1 != ft::Matrix<double>({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}))
            return (4);
    }

    {
        // Operator *=

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<double> m2 = m1 *= 2;

        // Modifies the matrix m1
        if (m1 != ft::Matrix<double>({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}))
            return (5);

        if (m2 != ft::Matrix<double>({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}}))
            return (6);

    }

    return (0);
}