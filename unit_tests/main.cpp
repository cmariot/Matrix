/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:42:37 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 18:12:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl;

    // LAUNCH MATRIX TESTS
    matrix_launcher();

	std::cout << std::endl;

	// LAUNCH VECTOR TESTS
	vector_launcher();

	return (0);
}
