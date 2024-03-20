/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:42:37 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 12:58:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
#include <time.h>

int	main(void)
{

	// LAUNCH VECTOR TESTS
    clock_t start = clock();
	vector_launcher();
    std::cout << "\nElapsed time for vector tests: " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;

    // LAUNCH MATRIX TESTS
    start = clock();
    matrix_launcher();
    std::cout << "\nElapsed time for matrix tests: " << double(clock() - start) / CLOCKS_PER_SEC << "s" << std::endl;

	return (0);
}
