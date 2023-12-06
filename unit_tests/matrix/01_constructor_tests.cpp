/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:54 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/06 13:52:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


int m_constructor_test(void)
{
    {
        // Default constructor
        ft::Matrix<int> ft_default;

        std::cout << ft_default << std::endl;

        // {{}}
    }

    {
        // Constructor with size
        ft::Matrix<int> ft_size(5, 5);

        std::cout << ft_size << std::endl;

        // {{0, 0, 0, 0, 0},
        //  {0, 0, 0, 0, 0},
        //  {0, 0, 0, 0, 0},
        //  {0, 0, 0, 0, 0},
        //  {0, 0, 0, 0, 0}}

    }

    {
        // Constructor with size and value
        ft::Matrix<int> ft_size_value(5, 5, 42);

        std::cout << ft_size_value << std::endl;

        // {{42, 42, 42, 42, 42},
        //  {42, 42, 42, 42, 42},
        //  {42, 42, 42, 42, 42},
        //  {42, 42, 42, 42, 42},
        //  {42, 42, 42, 42, 42}}
    }

    {
        // Constructor with initializer list
        ft::Matrix<int> ft_init_list = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        std::cout << ft_init_list << std::endl;

        // {{1, 2, 3},
        //  {4, 5, 6},
        //  {7, 8, 9}}

    }

    {
        // Copy constructor
        ft::Matrix<int> ft_copy = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Matrix<int> ft_copy2(ft_copy);

        std::cout << ft_copy2 << std::endl;

        try
        {
            ft::Vector<int> ft_copy3 = {};
            ft::Matrix<int> ft_copy4(ft_copy3);

            std::cout << ft_copy4 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    {
        // Copy constructor with vector
        ft::Vector<int> ft_copy = {1, 2, 3, 4, 5};
        ft::Matrix<int> ft_copy2(ft_copy);

        std::cout << ft_copy2 << std::endl;
    }

    return (0);
}
