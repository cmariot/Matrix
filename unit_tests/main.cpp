/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:42:37 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/12 19:41:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>

int	main(void)
{

	// LAUNCH VECTOR TESTS
	vector_launcher();

    // LAUNCH MATRIX TESTS
    matrix_launcher();


	return (0);
}
