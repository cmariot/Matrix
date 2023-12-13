/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_cross_product_tests.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:16:53 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/12 16:11:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "utils.hpp"


int v_cross_product_test(void)
{

    {
        ft::Vector<double> v1 = {0., 0., 1.0};
        ft::Vector<double> v2 = {1.0, 0., 0.};

        ft::Vector<double> ret = cross_product<double>(v1, v2);
        ft::Vector<double> expected = {0.0, 1., 0.};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {1., 2., 3.0};
        ft::Vector<double> v2 = {4.0, 5., 6.};

        ft::Vector<double> ret = cross_product<double>(v1, v2);
        ft::Vector<double> expected = {-3.0, 6., -3.};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {4., 2., -3.0};
        ft::Vector<double> v2 = {-2.0, -5., 16.};

        ft::Vector<double> ret = cross_product<double>(v1, v2);
        ft::Vector<double> expected = {17.0, -58., -16.};

        if (ret != expected)
            return (-1);
    }

    return (0);
}