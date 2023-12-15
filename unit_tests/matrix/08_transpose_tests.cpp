/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_transpose_tests.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/14 16:23:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include "tests.hpp"
#include <cstring>


int m_transpose_test(void)
{

    // Transposition of a 1x1 matrix
    {
        ft::Matrix<double> m1 = {
            {1}
        };

        ft::Matrix<double> expected = {
            {1}
        };

        if (m1.transpose() != expected)
            return (-1);
    }

    // Transposition of a 2x2 matrix
    {
        ft::Matrix<double> m1 = {
            {1, 2},
            {3, 4}
        };

        ft::Matrix<double> expected = {
            {1, 3},
            {2, 4}
        };

        if (m1.transpose() != expected)
            return (-1);
    }

    // Transposition of a 3x3 matrix
    {
        ft::Matrix<double> m1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        ft::Matrix<double> expected = {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9}
        };

        if (m1.transpose() != expected)
            return (-1);
    }

    // Exceptions :
    {

        int nb_exceptions = 0;

        // Non square matrix
        {
            try
            {
                ft::Matrix<double> m1 = {
                    {1, 2, 3},
                    {4, 5, 6}
                };
                m1.transpose();
                return (-1);
            }
            catch(const std::exception& e)
            {
                if (strcmp(e.what(), "The matrix must be square.") != 0)
                    return (-1);
                ++nb_exceptions;
            }
        }

        // Non square matrix
        {
            try
            {
                ft::Matrix<double> m1 = {
                    {1, 2},
                    {4, 5},
                    {7, 8}
                };
                m1.transpose();
                return (-1);
            }
            catch(const std::exception& e)
            {
                if (strcmp(e.what(), "The matrix must be square.") != 0)
                    return (-1);
                ++nb_exceptions;
            }
        }

        // Empty matrix
        {
            try
            {
                ft::Matrix<double> m1;
                m1.transpose();
                return (-1);
            }
            catch(const std::exception& e)
            {
                if (strcmp(e.what(), "The matrix must be square.") != 0)
                    return (-1);
                ++nb_exceptions;
            }
        }

        if (nb_exceptions != 3)
            return (-1);

    }
    return (0);
}