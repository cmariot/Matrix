/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:42:37 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 20:35:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
#include <time.h>

int	main(void)
{

    // start a timer
    clock_t start = clock();

	// LAUNCH VECTOR TESTS
	vector_launcher();

    // stop the timer
    clock_t end = clock();

    // calculate the elapsed time
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "\nElapsed time for vector tests: " << elapsed_time << "s" << std::endl;

    // LAUNCH MATRIX TESTS
    matrix_launcher();


	return (0);
}
