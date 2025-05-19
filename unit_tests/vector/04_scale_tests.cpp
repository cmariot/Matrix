/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_scale_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:09:50 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/06 13:52:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"


int v_scale_test(void)
{
    {
        // Operator *

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};

        if (v1 * 2 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        // Does not modify the vector
        if (v1 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);
    }

    {
        // Method scale

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};

        if (v1.scl(2) != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        // Modifies the vector v1
        if (v1 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

    }

    {
        // Operator *=

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};

        ft::Vector<double> v2 = v1 *= 2;

        // Modifies the vector v1
        if (v1 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        if (v2 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

    }

    {
        ft::Vector<double> v1 = {0, 0};

        if (v1 * 1 != ft::Vector<double>({0, 0}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {1, 0};

        if (v1 * 1 != ft::Vector<double>({1, 0}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {1, 1};

        if (v1 * 2 != ft::Vector<double>({2, 2}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {21, 21};

        if (v1 * 2 != ft::Vector<double>({42, 42}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {42, 42};

        if (v1 * 0.5 != ft::Vector<double>({21, 21}))
            return (-1);
    }
    
    return (0);
}