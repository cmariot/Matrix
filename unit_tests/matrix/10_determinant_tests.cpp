/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_determinant_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 13:52:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.hpp"


int m_determinant_test(void)
{
    {
        ft::Matrix<float> m1 = {
            {1., -1.},
            {-1., 1.},
        };

        if (m1.determinant() != 0)
            return (-1);
    }

    {
        ft::Matrix<float> m2 = {
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2},
        };

        if (m2.determinant() != 8)
            return (-1);
    }

    {
        ft::Matrix<float> m3 = {
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
        };

        if (m3.determinant() != -174)
            return (-1);
    }

    {
        ft::Matrix<double> m4 = {
            {8., 5., -2., 4.},
            {4., 2.5, 20., 4.},
            {8., 5., 1., 4.},
            {28., -4., 17., 1.},
        };

        if (m4.determinant() != 1032)
            return (-1);

    }

    {
        ft::Matrix<float> m1 = {
            {0, 0},
            {0, 0},
        };

        if (m1.determinant() != 0)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {1, 0},
            {0, 1},
        };

        if (m1.determinant() != 1)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {2, 0},
            {0, 2},
        };

        if (m1.determinant() != 4)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {1, 1},
            {1, 1},
        };

        if (m1.determinant() != 0)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {0, 1},
            {1, 0},
        };

        if (m1.determinant() != -1)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {1, 2},
            {3, 4},
        };

        if (m1.determinant() != -2)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {-7, 5},
            {4, 6},
        };

        if (m1.determinant() != -62)
            return (-1);
    }

    {
        ft::Matrix<float> m1 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        if (m1.determinant() != 1)
            return (-1);
    }

    return (0);
}