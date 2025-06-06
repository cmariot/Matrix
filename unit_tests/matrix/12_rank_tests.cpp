/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_rank_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 11:32:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.hpp"


int m_rank_test(void)
{

    {
        ft::Matrix<double> m1 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        if (m1.rank() != 3)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1., 2., 0., 0.},
            {2., 4., 0., 0.},
            {-1., 2., 1., 1.}
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
            {21., 18., 7.}
        };

        if (m1.rank() != 3)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {0, 0},
            {0, 0},
        };

        if (m1.rank() != 0)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 0},
            {0, 1},
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {2, 0},
            {0, 2},
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 1},
            {1, 1},
        };

        if (m1.rank() != 1)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {0, 1},
            {1, 0},
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 2},
            {3, 4},
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {-7, 5},
            {4, 6},
        };

        if (m1.rank() != 2)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };

        if (m1.rank() != 3)
            return (-1);
    }

    return (0);
}