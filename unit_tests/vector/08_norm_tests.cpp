/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_norm_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:57:55 by cmariot           #+#    #+#             */
/*   Updated: 2024/04/16 12:22:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>
#include <complex>

int v_norm_test(void)
{

    {
        ft::Vector<float> v1 = {0., 0., 0.};

        if (v1.norm_1() != 0.)
            return (-1);

        if (v1.norm() != 0.)
            return (-1);

        if (v1.norm_inf() != 0.)
            return (-1);
    }

    {
        ft::Vector<float> v1 = {1, 2., 3.};

        if (v1.norm_1() != 6.)
            return (-1);

        if ((float)v1.norm() != (float)3.74165738)
            return (-1);

        if (v1.norm_inf() != 3.)
            return (-1);
    }

    {
        ft::Vector<float> v1 = {-1, -2};

        if (v1.norm_1() != 3.)
            return (-1);

        if ((float)v1.norm() != (float)2.236067977)
            return (-1);

        if (v1.norm_inf() != 2.)
            return (-1);
    }

    {
        ft::Vector<float> v1 = {-2, 2};

        if (v1.norm_1() != 4.)
            return (-1);
    }

    {

        // Vector of complex number
        ft::Vector<std::complex<float>> v1 = {std::complex<float>(1, 1), std::complex<float>(1, 1)};

        std::cout << "v1 = " << v1 << std::endl;
        std::cout << "v1.norm_1() = " << v1.norm_1() << std::endl;
        std::cout << "v1.norm() = " << v1.norm() << std::endl;
        std::cout << "v1.norm_inf() = " << v1.norm_inf() << std::endl;
    }

    return (0);
}