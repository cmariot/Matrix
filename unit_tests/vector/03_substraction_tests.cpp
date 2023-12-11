/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_substraction_tests.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:13 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 11:12:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cstring>


int v_substraction_test(void)
{
    {
        // Operator -

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        if (v1 - v2 != ft::Vector<double>({0, 0, 0, 0, 0}))
            return (-1);

        // Does not modify the vector
        if (v1 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);

        // Does not modify the second vector
        if (v2 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);
    }

    {
        // Method sub

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        if (v1.sub(v2) != ft::Vector<double>({0, 0, 0, 0, 0}))
            return (-1);

        // Modifies the vector
        if (v1 != ft::Vector<double>({0, 0, 0, 0, 0}))
            return (-1);

        // Does not modify the second vector
        if (v2 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);
    }

    {
        // Operator -=

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        v1 -= v2;

        // Modifies the vector v1
        if (v1 != ft::Vector<double>({0, 0, 0, 0, 0}))
            return (-1);

        // Does not modify the second vector
        if (v2 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);

    }

    {
        // Exceptions : The 2 vectors must have the same size.

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3};
        int nb_exception = 0;

        try
        {
            v1 - v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1.sub(v2);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 -= v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 = v1 - v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 = v1.sub(v2);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        if (nb_exception != 5)
            return (-1);

    }

    return (0);
}