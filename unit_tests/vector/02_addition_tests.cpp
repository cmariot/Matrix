/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_addition_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:13 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 11:12:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <cstring>


int v_addition_test(void)
{
    {
        // Operator +

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        if (v1 + v2 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        // Does not modify the vector
        if (v1 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);

        // Does not modify the second vector
        if (v2 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);
    }

    {
        // Method add

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        if (v1.add(v2) != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        // Modifies the vector
        if (v1 != ft::Vector<double>({2, 4, 6, 8, 10}))
            return (-1);

        // Does not modify the second vector
        if (v2 != ft::Vector<double>({1, 2, 3, 4, 5}))
            return (-1);
    }

    {
        // Operator +=

        ft::Vector<double> v1 = {1, 2, 3, 4, 5};
        ft::Vector<double> v2 = {1, 2, 3, 4, 5};

        v1 += v2;

        // Modifies the vector v1
        if (v1 != ft::Vector<double>({2, 4, 6, 8, 10}))
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
            v1 + v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1.add(v2);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 += v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 = v1 + v2;
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        try
        {
            v1 = v1.add(v2);
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

    {
        ft::Vector<double> v1 = {0, 0};
        ft::Vector<double> v2 = {0, 0};

        if (v1 + v2 != ft::Vector<double>({0, 0}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {1, 0};
        ft::Vector<double> v2 = {0, 1};

        if (v1 + v2 != ft::Vector<double>({1, 1}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {1, 1};
        ft::Vector<double> v2 = {1, 1};

        if (v1 + v2 != ft::Vector<double>({2, 2}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {21, 21};
        ft::Vector<double> v2 = {21, 21};

        if (v1 + v2 != ft::Vector<double>({42, 42}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {-21, 21};
        ft::Vector<double> v2 = {21, -21};

        if (v1 + v2 != ft::Vector<double>({0, 0}))
            return (-1);
    }
    {
        ft::Vector<double> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        ft::Vector<double> v2 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

        if (v1 + v2 != ft::Vector<double>({9, 9, 9, 9, 9, 9, 9, 9, 9, 9}))
            return (-1);
    }

    return (0);
}