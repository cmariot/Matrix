/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:14:43 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 16:57:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"

int	matrix_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "MATRIX";

	load_test(&tests, function_name, "Constructor           ", (void *)&m_constructor_test, NULL);
    load_test(&tests, function_name, "Addition              ", (void *)&m_addition_test, "");
    load_test(&tests, function_name, "Subtraction           ", (void *)&m_subtraction_test, "");
    load_test(&tests, function_name, "Scale                 ", (void *)&m_scale_test, "");
    load_test(&tests, function_name, "Linear interpolation  ", (void *)&m_linear_interpolation_test, "");
    load_test(&tests, function_name, "Multiplication        ", (void *)&m_multiplication_test, "");
    load_test(&tests, function_name, "Trace                 ", (void *)&m_trace_test, "");
    load_test(&tests, function_name, "Transpose             ", (void *)&m_transpose_test, "");
    load_test(&tests, function_name, "Row echelon           ", (void *)&m_row_echelon_test, "");
    load_test(&tests, function_name, "Determinant           ", (void *)&m_determinant_test, "");
    load_test(&tests, function_name, "Inverse               ", (void *)&m_inverse_test, "");
    load_test(&tests, function_name, "Rank                  ", (void *)&m_rank_test, "");
    load_test(&tests, function_name, "Projection            ", (void *)&m_projection_test, "");

    return (launch_tests(&tests));
}
