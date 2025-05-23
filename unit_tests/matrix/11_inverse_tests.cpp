/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_inverse_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 14:10:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"


int m_inverse_test(void)
{
    {
        ft::Matrix<double> m = {
            { 1.0, 0.0, 0.0 },
            { 0.0, 1.0, 0.0 },
            { 0.0, 0.0, 1.0 }
        };

        ft::Matrix<double> expected = {
            { 1.0, 0.0, 0.0 },
            { 0.0, 1.0, 0.0 },
            { 0.0, 0.0, 1.0 }
        };

        if (m.inverse() != expected)
            return (-1);
    }


    {
        ft::Matrix<double> m = {
            { 2.0, 0.0, 0.0 },
            { 0.0, 2.0, 0.0 },
            { 0.0, 0.0, 2.0 }
        };

        ft::Matrix<double> expected1 = {
            { 0.5, 0.0, 0.0 },
            { 0.0, 0.5, 0.0 },
            { 0.0, 0.0, 0.5 }
        };

        if (m.inverse() != expected1)
            return (-1);
    }


    {
        ft::Matrix<double> m = {
            { 8.0, 5.0, -2.0 },
            { 4.0, 7.0, 20.0 },
            { 7.0, 6.0, 1.0 }
        };

        ft::Matrix<double> expected2 = {
            { 0.649425287, 0.097701149, -0.655172414 },
            { -0.781609195, -0.126436782, 0.965517241 },
            { 0.143678161, 0.074712644, -0.206896552 }
        };

        if (m.inverse() != expected2)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 1.0, 0.0 },
            { 0.0, 1.0 },
        };

        ft::Matrix<double> expected = {
            { 1.0, 0.0 },
            { 0.0, 1.0 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 2.0, 0.0 },
            { 0.0, 2.0 },
        };

        ft::Matrix<double> expected = {
            { 0.5, 0.0 },
            { 0.0, 0.5 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 0.5, 0.0 },
            { 0.0, 0.5 },
        };

        ft::Matrix<double> expected = {
            { 2, 0.0 },
            { 0.0, 2 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 0, 1.0 },
            { 1.0, 0 },
        };

        ft::Matrix<double> expected = {
            { 0, 1 },
            { 1, 0 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 1, 2 },
            { 3, 4 },
        };

        ft::Matrix<double> expected = {
            { -2, 1 },
            { 1.5, -0.5 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m = {
            { 1, 0, 0 },
            { 0, 1, 0 },
            { 0, 0, 1 },
        };

        ft::Matrix<double> expected = {
            { 1, 0, 0 },
            { 0, 1, 0 },
            { 0, 0, 1 },
        };

        if (m.inverse() != expected)
            return (-1);
    }

    return (0);
}