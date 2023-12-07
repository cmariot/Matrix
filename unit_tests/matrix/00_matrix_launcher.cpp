/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:14:43 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/06 18:46:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"

int	matrix_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "MATRIX";

	load_test(&tests, function_name, "Constructor           ", (void *)&m_constructor_test, NULL);
    load_test(&tests, function_name, "Addition              ", (void *)&m_addition_test, "");
    load_test(&tests, function_name, "Substraction          ", (void *)&m_substraction_test, "");
    load_test(&tests, function_name, "Scale                 ", (void *)&m_scale_test, "");

	return (launch_tests(&tests));
}
