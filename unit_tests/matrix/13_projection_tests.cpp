/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_projection_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:52 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/14 15:02:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <fstream>
#include <string>
#include <unistd.h>


int m_projection_test(void)
{

    {
        ft::Matrix<float> perspective_projection = projection(80., 16/9, 0.00001, 50);

        // Save the matrix in a file called 'proj'

        std::ofstream file("matrix_display/proj", std::ios::trunc);
        if (file.is_open())
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (j < 3)
                        file << perspective_projection[i][j] << ", ";
                    else
                        file << perspective_projection[i][j] << std::endl;
                }
            }
            file.close();
        }

    }

    return (0);
}