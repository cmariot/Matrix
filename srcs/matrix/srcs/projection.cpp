/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/13 20:20:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"
#include <cmath>


ft::Matrix<float>   projection(float fov, float ratio, float near, float far)
{

    /*

        Return the perspective projection matrix.

        - fov : field of view in degrees
        - ratio : screen height / width
        - near : distance between camera and near screen
        - far : distance between camera and far screen

        The perspective projection matrix is used to transform 3D coordinates
        into 2D coordinates. It is used to simulate perspective in a 3D scene.

        The display software expects the input matrix to be in row-major
        order. Its Normalized Device Coordinates are in the ranges [−1, 1]
        for the X and Y axes, and [0, 1] for the Z axis

        http://learnwebgl.brown37.net/08_projections/projections_perspective.html

    */

    (void)ratio;
    (void)far;

    ft::Matrix<float> perspective_projection = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    float top = near * tan((fov * M_PI / 180) / 2);
    float bottom = -top;
    float right = top * ratio;
    float left = -right;

    std::cout << "top : " << top << std::endl;
    std::cout << "bottom : " << bottom << std::endl;
    std::cout << "right : " << right << std::endl;
    std::cout << "left : " << left << std::endl;

    // - Translate the apex of the frustum to the origin.
    // - Perform the perspective calculation.
    // - Scale the 2D (x’,y’) values in the viewing window to a
    //   2 by 2 unit square: (-1,-1) to (+1,+1).
    // - Scale the depth values (z) into a normalized range (-1,+1).
    // - Flip the orientation of the z axis to match the clipping volume’s orientation.

    perspective_projection[0][0] = (2 * near) / (right - left);
    perspective_projection[0][3] = -near * (right + left) / (right - left);
    perspective_projection[1][1] = (2 * near) / (top - bottom);
    perspective_projection[1][3] = -near * (top + bottom) / (top - bottom);
    perspective_projection[2][2] = - (far + near) / (far - near);
    perspective_projection[2][3] = - (2 * far * near) / (near - far);
    perspective_projection[3][2] = -1;
    perspective_projection[3][3] = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j < 3)
                std::cout << perspective_projection[i][j] << ", ";
            else
                std::cout << perspective_projection[i][j] << std::endl;
        }
    }
    return (perspective_projection);
}
