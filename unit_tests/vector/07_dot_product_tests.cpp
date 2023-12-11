/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_dot_product_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:42:20 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 14:51:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "vector.hpp"
#include <iostream>

int v_dot_product_test(void)
{
    {
        ft::Vector<double> v1 = ft::Vector<double>({0., 0.});
        ft::Vector<double> v2 = ft::Vector<double>({1., 1.});

        double ret = v1.dot(v2);
        double expected = 0.;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = ft::Vector<double>({1., 1.});
        ft::Vector<double> v2 = ft::Vector<double>({1., 1.});

        double ret = v1.dot(v2);
        double expected = 2.;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = ft::Vector<double>({-1., 6.});
        ft::Vector<double> v2 = ft::Vector<double>({3., 2.});

        double ret = v1.dot(v2);
        double expected = 9.;

        if (ret != expected)
            return (-1);
    }

    return (0);
}