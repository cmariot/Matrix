/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_subtraction_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:13 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 16:57:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
# include <cstring>


int m_subtraction_test(void)
{
    {
        // Operator -

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<double> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        if (m1 - m2 != ft::Matrix<double>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}))
            return (-1);

        // Does not modify the matrix
        if (m1 != ft::Matrix<double>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
            return (-1);

        // Does not modify the second vector
        if (m2 != ft::Matrix<double>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
            return (-1);
    }

    {
        // Method sub

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<double> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        if (m1.sub(m2) != ft::Matrix<double>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}))
            return (-1);

        // Modifies the matrix m1
        if (m1 != ft::Matrix<double>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}))
            return (-1);

        // Does not modify the second vector
        if (m2 != ft::Matrix<double>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
            return (-1);
    }

    {
        // Operator -=

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<double> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        m1 -= m2;

        // Modifies the matrix v1
        if (m1 != ft::Matrix<double>({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}))
            return (-1);

        // Does not modify the second matrix
        if (m2 != ft::Matrix<double>({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
            return (-1);
    }

    {
        // Exceptions : The 2 matrix must have the same size.

        ft::Matrix<double> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<double> m2 = {{1, 2, 3}, {4, 5, 6}};
        int nb_exception = 0;

        try
        {
            m1 - m2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Matrices are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            m1.sub(m2);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Matrices are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            m1 -= m2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Matrices are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            m1 = m1 - m2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Matrices are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            m1 = m1.sub(m2);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Matrices are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        if (nb_exception != 5)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{0, 0}, {0, 0}};
        ft::Matrix<double> m2 = {{0, 0}, {0, 0}};

        if (m1 - m2 != ft::Matrix<double>({{0, 0}, {0, 0}}))
            return (-1);
    }
    {
        ft::Matrix<double> m1 = {{1, 0}, {0, 1}};
        ft::Matrix<double> m2 = {{0, 0}, {0, 0}};

        if (m1 - m2 != ft::Matrix<double>({{1, 0}, {0, 1}}))
            return (-1);
    }
    {
        ft::Matrix<double> m1 = {{1, 1}, {1, 1}};
        ft::Matrix<double> m2 = {{1, 1}, {1, 1}};

        if (m1 - m2 != ft::Matrix<double>({{0, 0}, {0, 0}}))
            return (-1);
    }
    {
        ft::Matrix<double> m1 = {{21, 21}, {21, 21}};
        ft::Matrix<double> m2 = {{21, 21}, {21, 21}};

        if (m1 - m2 != ft::Matrix<double>({{0, 0}, {0, 0}}))
            return (-1);
    }

    return (0);
}