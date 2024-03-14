/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/14 10:16:59 by cmariot          ###   ########.fr       */
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

    float fov_radians = fov * M_PI / 180;
    float tan_fov_per_two = tan(fov_radians / 2);
    float near_min_far = near - far;

    float top = near * tan_fov_per_two;                 // t
    float bottom = -top;                                // b
    float right = top * ratio;                          // r
    float left = -right;                                // l

    // f = far
    // n = near

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


    // Projection matrix w/ far/near/left/right/top/bottom

    ft::Matrix<float> projection_matrix(4, 4);

    projection_matrix[0][0] = 2 * near / (right - left);
    projection_matrix[0][1] = 0;
    projection_matrix[0][2] = (right + left) / (right - left);
    projection_matrix[0][3] = 0;

    projection_matrix[1][0] = 0;
    projection_matrix[1][1] = (2 * near) / (top - bottom);
    projection_matrix[1][2] = (top + bottom) / (top - bottom);
    projection_matrix[1][3] = 0;

    projection_matrix[2][0] = 0;
    projection_matrix[2][1] = 0;
    projection_matrix[2][2] = -(far + near) / (far - near);
    projection_matrix[2][3] = (-2 * far * near) / (far - near);

    projection_matrix[3][0] = 0;
    projection_matrix[3][1] = 0;
    projection_matrix[3][2] = -1;
    projection_matrix[3][3] = 0;

    std::cout << projection_matrix << std::endl;


    // Projection matrix w/ fov/aspect/far/near
    ft::Matrix<float> projection_matrix_4(4, 4);

    projection_matrix_4[0][0] = 1 / (ratio * tan_fov_per_two);
    projection_matrix_4[0][1] = 0;
    projection_matrix_4[0][2] = 0;
    projection_matrix_4[0][3] = 0;

    projection_matrix_4[1][0] = 0;
    projection_matrix_4[1][1] = projection_matrix_4[0][0] * ratio;
    projection_matrix_4[1][2] = (top + bottom) / (top - bottom);
    projection_matrix_4[1][3] = 0;

    projection_matrix_4[2][0] = 0;
    projection_matrix_4[2][1] = 0;
    projection_matrix_4[2][2] = (near + far) / near_min_far;
    projection_matrix_4[2][3] = (2 * near * far) / near_min_far;

    projection_matrix_4[3][0] = 0;
    projection_matrix_4[3][1] = 0;
    projection_matrix_4[3][2] = -1;
    projection_matrix_4[3][3] = 0;

    std::cout << projection_matrix_4 << std::endl;

    return (projection_matrix);
}
