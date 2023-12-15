/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_row_echelon_form_tests.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/15 11:54:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int m_row_echelon_test(void)
{

    {
        ft::Matrix<double> m1 = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};

        ft::Matrix<double> expected = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}};

        if (m1.row_echelon() != expected)
            return (-1);
    }

    {
        ft::Matrix<double> m1 = {
            {1, 2},
            {3, 4}};

        ft::Matrix<double> expected = {
            {1, 0},
            {0, 1}};

        std::cout << "m1 = " << m1 << std::endl;
        std::cout << "m1.row_echelon() = " << m1.row_echelon() << std::endl;

        if (m1.row_echelon() != expected)
            return (-1);
    }

    return (0);
}