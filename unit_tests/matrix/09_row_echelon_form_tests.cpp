/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_row_echelon_form_tests.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 09:39:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int m_row_echelon_test(void)
{

    {
        ft::Matrix<double> m1 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        ft::Matrix<double> expected = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        if (m1.row_echelon() != expected)
            return (-1);

    }

    {
        ft::Matrix<double> m1 = {
            {1, 2},
            {3, 4}
        };

        ft::Matrix<double> expected = {
            {1, 0},
            {0, 1}
        };

        if (m1.row_echelon() != expected)
            return (-1);

    }

    {
        ft::Matrix<double> m1 = {
            {1., 2.},
            {2., 4.},
        };

        ft::Matrix<double> expected = {
            {1.0, 2.0},
            {0.0, 0.0}
        };

        if (m1.row_echelon() != expected)
            return (-1);

    }

    {
        ft::Matrix<double> m1 = {
            {8., 5., -2., 4., 28.},
            {4., 2.5, 20., 4., -4.},
            {8., 5., 1., 4., 17.},
        };

        ft::Matrix<double> expected = {
            {1.0, 0.625, 0.0, 0.0, -12.1667},
            {0.0, 0.0, 1.0, 0.0, -3.66667},
            {0.0, 0.0, 0.0, 1.0, 29.5}};

        if (m1.row_echelon() != expected)
            return (-1);

    }

    {
        ft::Matrix<double> m1 = {
            {1, 1, 1},
            {-2, 4, -2},
            {-1, 0, 1}
        };

        ft::Matrix<double> expected = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        if (m1.row_echelon() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {2, 0, 4, 0},
            {0, 1, 1, 3},
            {1, 1, 3, 3}
        };

        ft::Matrix<double> expected = {
            {1, 0, 2, 0},
            {0, 1, 1, 3},
            {0, 0, 0, 0}
        };

        if (m1.row_echelon() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 1, 2},
            {1, 2, 1},
            {2, 3, 3},
            {3, 3, 3},
        };

        ft::Matrix<double> expected = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
            {0, 0, 0},
        };

        if (m1.row_echelon() != expected)
            return (-1);
    }

    return (0);
}