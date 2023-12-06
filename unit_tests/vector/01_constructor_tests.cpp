/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/06 13:52:34 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"


int v_constructor_test(void)
{
    // Default constructor
    {
        ft::Vector<double> default_vector;

        std::cout << default_vector << std::endl;
    }

    // Constructor with size
    {
        ft::Vector<double> size_vector(5);

        std::cout << size_vector << std::endl;
    }

    // Constructor with size and value
    {
        ft::Vector<double> size_value_vector(5, 42.);

        std::cout << size_value_vector << std::endl;
    }

    // Constructor with initializer list
    {
        ft::Vector<double> init_list_vector = {1, 2, 3, 4, 5};

        std::cout << init_list_vector << std::endl;
    }

    // Copy constructor
    {
        ft::Vector<double> copy_vector = {1, 2, 3, 4, 5};
        ft::Vector<double> copy_vector2(copy_vector);

        std::cout << copy_vector2 << std::endl;
    }

    // Copy constructor with matrix
    {
        ft::Matrix<double> copy_matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        ft::Vector<double> copy_vector(copy_matrix);

        std::cout << copy_vector << std::endl;
    }

    return (0);
}
