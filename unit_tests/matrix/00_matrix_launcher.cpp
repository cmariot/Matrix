/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_matrix_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:14:43 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 14:48:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tests.hpp"

int	matrix_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "MATRIX";

	load_test(&tests, function_name, "Constructor", (void *)&m_constructor_test, "");

	return (launch_tests(&tests));
}
