/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_vector_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 14:48:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	vector_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "VECTOR";

	load_test(&tests, function_name, "Constructor", (void *)&v_constructor_test, "");

	return (launch_tests(&tests));
}