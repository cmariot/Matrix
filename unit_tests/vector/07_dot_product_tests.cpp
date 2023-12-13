/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_dot_product_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:42:20 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/13 11:05:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "vector.hpp"
#include <iostream>
#include <cstring>

int v_dot_product_test(void)
{

    {
        ft::Vector<double> v1 = {4., 2.};
        ft::Vector<double> v2 = {2., 1.};

        double ret = v1.dot(v2);
        double expected = 10.;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {0., 0.};
        ft::Vector<double> v2 = {1., 1.};

        double ret = v1.dot(v2);
        double expected = 0.;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {1., 1.};
        ft::Vector<double> v2 = {1., 1.};

        double ret = v1.dot(v2);
        double expected = 2.;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-1., 6.};
        ft::Vector<double> v2 = {3., 2.};

        double ret = v1.dot(v2);
        double expected = 9.;

        if (ret != expected)
            return (-1);
    }

    // Exceptions
    {

        int nb_exceptions = 0;

        // Two vectors of different dimensions
        {
            try
            {
                ft::Vector<double> v1 = {1., 2.};
                ft::Vector<double> v2 = {1., 2., 3.};

                v1.dot(v2);

                return (-1);

            }
            catch(const std::exception& e)
            {
                if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                    return (-1);
                nb_exceptions++;
            }

            if (nb_exceptions != 1)
                return (-1);

        }

    }

    return (0);
}