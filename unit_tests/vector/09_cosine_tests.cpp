/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_cosine_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:58:49 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/12 12:06:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "utils.hpp"


int v_cosine_test(void)
{

    {
        ft::Vector<double> v1 = {1., 0.};
        ft::Vector<double> v2 = {1., 0.};

        double ret = angle_cos<double>(v1, v2);
        double expected = 1.0;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {1., 0.};
        ft::Vector<double> v2 = {0., 1.};

        double ret = angle_cos<double>(v1, v2);
        double expected = 0.0;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-1., 1.};
        ft::Vector<double> v2 = {1., -1.};

        double ret = angle_cos<double>(v1, v2);
        double expected = -1.0;

        if ((float)ret != (float)expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {2., 1.};
        ft::Vector<double> v2 = {4., 2.};

        float ret = angle_cos<double>(v1, v2);
        float expected = 1.0;

        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {1., 2., 3.};
        ft::Vector<double> v2 = {4., 5., 6.};

        double ret = angle_cos<double>(v1, v2);
        double expected = 0.974631846;

        if ((float)ret != (float)expected)
            return (-1);
    }

    return (0);
}