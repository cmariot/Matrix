/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_complex_tests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:46:31 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 17:15:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <complex>

int m_complex_test(void)
{

    // Constructors
    {

        std::complex<double> c1(1.0, 2.0);
        std::complex<double> c2(3.0, 4.0);
        std::complex<double> c3(5.0, 6.0);
        std::complex<double> c4(7.0, 8.0);

        ft::Matrix<std::complex<double>> ft_default;
        ft::Matrix<std::complex<double>> ft_size(2, 2);
        ft::Matrix<std::complex<double>> ft_size_value(2, 2, c1);
        ft::Matrix<std::complex<double>> ft_init_list = {
            {c1, c2},
            {c3, c4}
        };

        // std::cout << "ft_default: " << ft_default << std::endl;
        // std::cout << "ft_size: " << ft_size << std::endl;
        // std::cout << "ft_size_value: " << ft_size_value << std::endl;
        // std::cout << "ft_init_list: " << ft_init_list << std::endl;

    }

    // Add
    {

    }


    return (-1);
}