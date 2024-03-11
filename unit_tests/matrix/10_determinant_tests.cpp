/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_determinant_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/11 13:47:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "matrix.hpp"


int m_determinant_test(void)
{
    {
        ft::Matrix<float> m1 = {
            {1., -1.},
            {-1., 1.},
        };

        std::cout << "M1 determinant : " << m1.determinant() << std::endl;

        if (m1.determinant() != 0)
            return (-1);
    }

    {
        ft::Matrix<float> m2 = {
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2},
        };

        std::cout << "M2 determinant : " << m2.determinant() << std::endl;

        if (m2.determinant() != 8)
            return (-1);
    }

    {
        ft::Matrix<float> m3 = {
            {8., 5., -2.},
            {4., 7., 20.},
            {7., 6., 1.},
        };

        std::cout << "M3 determinant : " << m3.determinant() << std::endl;

        if (m3.determinant() != -174)
            return (-1);
    }

    {
        ft::Matrix<float> m4 = {
            {8., 5., -2., 4.},
            {4., 2.5, 20., 4.},
            {8., 5., 1., 4.},
            {28., -4., 17., 1.},
        };

        std::cout << "M4 determinant : " << m4.determinant() << std::endl;

        if (m4.determinant() != 1032)
            return (-1);
    }

    return (-1);
}