/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_linear_combination_tests.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:09:50 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/08 12:37:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <list>


// Timer function with a static, first call launch the chrono, the second call stop and display the time.
void timer(void)
{
    static std::chrono::time_point<std::chrono::system_clock> start, end;
    if (start == std::chrono::time_point<std::chrono::system_clock>()) {
        start = std::chrono::system_clock::now();
    } else {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
        start = std::chrono::time_point<std::chrono::system_clock>();
    }
}


int v_linear_combination_test(void)
{
    {
        ft::Vector<double> e1 = {1, 0, 0};
        ft::Vector<double> e2 = {0, 1, 0};
        ft::Vector<double> e3 = {0, 0, 1};

        std::list<ft::Vector<double> > l1;
        l1.push_back(e1);
        l1.push_back(e2);
        l1.push_back(e3);

        std::list<double> l2;
        l2.push_back(10);
        l2.push_back(-2);
        l2.push_back(0.5);

        ft::Vector<double> first_example = ft::Vector<double>::linear_combination(l1, l2);
        ft::Vector<double> expected = {10, -2, 0.5};

        // std::cout << first_example << std::endl;
        if (first_example != expected)
            return (-1);

        ft::Vector<double> v1 = {1, 2, 3};
        ft::Vector<double> v2 = {0, 10, -100};
        std::list<ft::Vector<double> > l3;
        l3.push_back(v1);
        l3.push_back(v2);

        std::list<double> l4;
        l4.push_back(10);
        l4.push_back(-2);

        ft::Vector<double> second_example = ft::Vector<double>::linear_combination(l3, l4);
        ft::Vector<double> expected2 = {10, 0, 230};

        // std::cout << second_example << std::endl;
        if (second_example != expected2)
            return (-1);

        // std::cout << "Optimized with FMA :" << std::endl;
        // double result = 0.0;

        // timer();
        // for (size_t i = 0; i < 900000000; ++i)
        // {
        //     result = std::fma(42.0, 10.0, result);
        // }
        // std::cout << result << std::endl;
        // timer();

        // std::cout << "Without optimizisation :" << std::endl;
        // result = 0.0;

        // timer();
        // for (size_t i = 0; i < 900000000; ++i)
        // {
        //     result += 42.0 * 10.0;
        // }
        // std::cout << result << std::endl;
        // timer();

    }

    return (0);
}