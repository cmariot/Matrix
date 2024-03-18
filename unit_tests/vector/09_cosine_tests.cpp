/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_cosine_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:58:49 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 17:23:28y cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "utils.hpp"
#include <cstring>

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

    {
        // Orthogonal vectors

        ft::Vector<double> v1 = {1., 0.};
        ft::Vector<double> v2 = {0., 1.};

        double ret = angle_cos<double>(v1, v2);
        double expected = 0.0;

        if (ret != expected)
            return (-1);

        // conversion in degrees
        if (std::acos(ret) * 180 / M_PI != 90)
            return (-1);
    }

    {
        try
        {
            // Angle between 2 vectors of non-numeric type

            ft::Vector<char> v1 = {'a', 'b'};
            ft::Vector<char> v2 = {'b', 'a'};

            angle_cos<char>(v1, v2);
        }
        catch (std::invalid_argument &e)
        {
            if (strcmp(e.what(), "The type T must be a numeric type.") != 0)
                return (-1);
        }

    }

    return (0);
}