/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_linear_interpolation_tests.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:09:50 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 10:16:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "vector.hpp"
// #include "matrix.hpp"
#include <iostream>

int v_linear_interpolation_test(void)
{

    // Test 1 : double with 0
    {
        double ret = lerp<double>(0., 1., 0.);
        double expected = 0.0;

        if (ret != expected)
            return (-1);
    }


    // Test 2 : double with 1
    {
        double ret = lerp<double>(0., 1., 1.);
        double expected = 1.0;

        if (ret != expected)
            return (-1);
    }

    // Test 3 : double with 0.5
    {
        double ret = lerp<double>(0., 1., 0.5);
        double expected = 0.5;

        if (ret != expected)
            return (-1);
    }

    // Test 4 : Linear interpolation of a Vector
    {
        ft::Vector<double> ret = lerp(ft::Vector<double>({2., 1.}), ft::Vector<double>({4., 2.}), 0.3);
        ft::Vector<double> expected = ft::Vector<double>({2.6, 1.3});

        if (ret != expected)
            return (-1);
    }

    // // Test 5 : Linear interpolation of a Matrix
    // {
    //     ft::Matrix<double> ret = lerp(
    //         ft::Matrix<double>({{2., 1.}, {3., 4.}}),
    //         ft::Matrix<double>({{20., 10.}, {30., 40.}}),
    //         0.3);
    //     ft::Matrix<double> expected = ft::Matrix<double>({{11., 5.5}, {16.5, 22.}});

    //     if (ret != expected)
    //         return (-1);
    // }

    return (0);
}