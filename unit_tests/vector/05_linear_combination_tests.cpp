/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_linear_combination_tests.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:09:50 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 13:21:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "tests.hpp"
#include <list>
#include <cstring>

// #include <chrono>


// // Timer function with a static, first call launch the chrono, the second call stop and display the time.
// void timer(void)
// {
//     static std::chrono::time_point<std::chrono::system_clock> start, end;
//     if (start == std::chrono::time_point<std::chrono::system_clock>()) {
//         start = std::chrono::system_clock::now();
//     } else {
//         end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end-start;
//         std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
//         start = std::chrono::time_point<std::chrono::system_clock>();
//     }
// }


int v_linear_combination_test(void)
{


    {
        ft::Vector<double> v1 = {3, 4};
        ft::Vector<double> v2 = {5, -3};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double> >({v1, v2}),
            std::list<double>({0.5, 0.5})
        );

        ft::Vector<double> expected = {4, 0.5};

        if (ret != expected)
            return (-1);
    }


    {
        ft::Vector<double> e1 = {1, 0, 0};
        ft::Vector<double> e2 = {0, 1, 0};
        ft::Vector<double> e3 = {0, 0, 1};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({e1, e2, e3}),
            std::list<double>({10, -2, 0.5}));

        ft::Vector<double> expected = {10, -2, 0.5};

        if (ret != expected)
            return (-1);
    }


    {
        ft::Vector<double> e1 = {1, 2, 3};
        ft::Vector<double> e2 = {0, 10, -100};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({e1, e2}),
            std::list<double>({10, -2}));

        ft::Vector<double> expected = {10, 0, 230};

        if (ret != expected)
            return (-1);
    }


    // Exceptions :
    {

        int nb_exception = 0;

        // The vectors and the scalars lists must have the same size.
        try
        {
            ft::Vector<double> e1 = {1, 2, 3};
            ft::Vector<double> e2 = {0, 10, -100};

            ft::Vector<double> ret = ft::linear_combination<double>(
                std::list<ft::Vector<double>>({e1, e2}),
                std::list<double>({10, -2.0, 0.5}));
            return (-1);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Lists are not the same size.") != 0)
                return (-1);
            nb_exception++;
        }

        // All the vectors in the list must be of the same dimension.
        try
        {
            ft::Vector<double> e1 = {1, 2, 3};
            ft::Vector<double> e2 = {0, 10};

            ft::Vector<double> ret = ft::linear_combination<double>(
                std::list<ft::Vector<double>>({e1, e2}),
                std::list<double>({10, -2}));
            return (-1);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are not the same dimension.") != 0)
                return (-1);
            nb_exception++;
        }

        // Empty vectors.
        try
        {
            ft::Vector<double> e1 = {};
            ft::Vector<double> e2 = {};

            ft::Vector<double> ret = ft::linear_combination<double>(
                std::list<ft::Vector<double>>({e1, e2}),
                std::list<double>({10, -2}));
            return (-1);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Vectors are empty.") != 0)
                return (-1);
            nb_exception++;
        }

        // Empty lists.
        try
        {
            ft::Vector<double> ret = ft::linear_combination<double>(
                std::list<ft::Vector<double>>({}),
                std::list<double>({}));
            return (-1);
        }
        catch (std::exception &e)
        {
            if (strcmp(e.what(), "Lists are empty.") != 0)
                return (-1);
            nb_exception++;
        }

        if (nb_exception != 4)
            return (-1);

    }

    {

        ft::Vector<double> v1 = {-42, 42};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({v1}),
            std::list<double>({-1.0})
        );

        ft::Vector<double> expected = {42, -42};
        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-42};
        ft::Vector<double> v2 = {-42};
        ft::Vector<double> v3 = {-42};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({v1, v2, v3}),
            std::list<double>({-1.0, 1.0, 0.0})
        );

        ft::Vector<double> expected = {0.0};
        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-42, 42};
        ft::Vector<double> v2 = {1, 3};
        ft::Vector<double> v3 = {10, 20};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({v1, v2, v3}),
            std::list<double>({1, -10, -1})
        );

        ft::Vector<double> expected = {-62, -8};
        if (ret != expected)
            return (-1);
    }

    {
        ft::Vector<double> v1 = {-42, 100, -69.5};
        ft::Vector<double> v2 = {1, 3, 5};

        ft::Vector<double> ret = ft::linear_combination<double>(
            std::list<ft::Vector<double>>({v1, v2}),
            std::list<double>({1, -10})
        );

        ft::Vector<double> expected = {-52, 70, -119.5};
        if (ret != expected)
            return (-1);
    }


    return (0);
}