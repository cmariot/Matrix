/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_norm_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:57:55 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/12 12:09:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "vector.hpp"


int v_norm_test(void)
{

    {
        ft::Vector<double> v1 = {0., 0., 0.};

        if (v1.norm_1() != 0.)
            return (-1);

        if (v1.norm() != 0.)
            return (-1);

        if (v1.norm_inf() != 0.)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {1, 2., 3.};

        if (v1.norm_1() != 6.)
            return (-1);

        if ((float)v1.norm() != (float)3.74165738)
            return (-1);

        if (v1.norm_inf() != 3.)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-1, -2};

        if (v1.norm_1() != 3.)
            return (-1);

        if ((float)v1.norm() != (float)2.236067977)
            return (-1);

        if (v1.norm_inf() != 2.)
            return (-1);
    }

    return (0);
}