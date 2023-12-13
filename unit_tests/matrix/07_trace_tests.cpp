/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_trace_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/13 11:16:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.hpp"


int m_trace_test(void)
{

    {
        ft::Matrix<double> m1 = {
            {1, 0},
            {0, 1}
        };

        double ret = m1.trace();
        double expected = 2;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {2, -5, 0},
            {4, 3, 7},
            {-2, 3, 4}
        };

        double ret = m1.trace();
        double expected = 9;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {-2, -8, 4},
            {1, -23, 4},
            {0, 6, 4}};

        double ret = m1.trace();
        double expected = -21;

        if (ret != expected)
            return (-1);
    }

    return (0);
}