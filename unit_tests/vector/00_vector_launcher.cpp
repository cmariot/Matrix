/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_vector_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 15:06:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	vector_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "VECTOR";

	load_test(&tests, function_name, "Constructor           ", (void *)&v_constructor_test, NULL);
	load_test(&tests, function_name, "Addition              ", (void *)&v_addition_test, "");
    load_test(&tests, function_name, "Substraction          ", (void *)&v_substraction_test, "");
    load_test(&tests, function_name, "Scale                 ", (void *)&v_scale_test, "");
    load_test(&tests, function_name, "Linear combination    ", (void *)&v_linear_combination_test, "");
    load_test(&tests, function_name, "Linear interpolation  ", (void *)&v_linear_interpolation_test, "");
    load_test(&tests, function_name, "Dot product           ", (void *)&v_dot_product_test, "");
    load_test(&tests, function_name, "Norm                  ", (void *)&v_norm_test, "");

	return (launch_tests(&tests));
}
