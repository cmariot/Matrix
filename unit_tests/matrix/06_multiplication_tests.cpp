/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_multiplication_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/13 09:53:34 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int m_multiplication_test(void)
{

    {
        ft::Matrix<double> m1 = {{1, 0}, {0, 1}};
        ft::Vector<double> v1 = {4, 2};

        ft::Vector<double> ret = m1.mul_vec(v1);
        ft::Vector<double> expected = {4, 2};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{2, 0}, {0, 2}};
        ft::Vector<double> v1 = {4, 2};

        ft::Vector<double> ret = m1.mul_vec(v1);
        ft::Vector<double> expected = {8, 4};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{2, -2}, {-2, 2}};
        ft::Vector<double> v1 = {4, 2};

        ft::Vector<double> ret = m1.mul_vec(v1);
        ft::Vector<double> expected = {4, -4};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{1, 0}, {0, 1}};
        ft::Matrix<double> m2 = {{1, 0}, {0, 1}};

        ft::Matrix<double> ret = m1.mul_mat(m2);

        ft::Matrix<double> expected = {{1, 0}, {0, 1}};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{1, 0}, {0, 1}};
        ft::Matrix<double> m2 = {{2, 1}, {4, 2}};

        ft::Matrix<double> ret = m1.mul_mat(m2);

        ft::Matrix<double> expected = {{2, 1}, {4, 2}};

        if (ret != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {{3, -5}, {6, 8}};
        ft::Matrix<double> m2 = {{2, 1}, {4, 2}};

        ft::Matrix<double> ret = m1.mul_mat(m2);

        ft::Matrix<double> expected = {{-14, -7}, {44, 22}};

        if (ret != expected)
            return (-1);
    }

    return (0);
}