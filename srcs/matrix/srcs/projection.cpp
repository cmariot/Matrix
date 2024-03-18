/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/14 15:02:14 by cmariot          ###   ########.fr       */
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

        https://cseweb.ucsd.edu/classes/wi20/cse167-a/lec4.pdf

    */

    float fov_radians = fov * M_PI / 180;
    float tan_fov_per_two = tan(fov_radians / 2);
    float near_min_far = near - far;
    float top = near * tan_fov_per_two;
    float bottom = -top;

    // - Translate the apex of the frustum to the origin.
    // - Perform the perspective calculation.
    // - Scale the 2D (x’,y’) values in the viewing window to a
    //   2 by 2 unit square: (-1,-1) to (+1,+1).
    // - Scale the depth values (z) into a normalized range (-1,+1).
    // - Flip the orientation of the z axis to match the clipping volume’s orientation.

    ft::Matrix<float> projection_matrix(4, 4);

    projection_matrix[0][0] = 1 / (ratio * tan_fov_per_two);
    projection_matrix[1][1] = projection_matrix[0][0] * ratio;
    projection_matrix[1][2] = (top + bottom) / (top - bottom);
    projection_matrix[2][2] = (near + far) / near_min_far;
    projection_matrix[2][3] = (2 * near * far) / near_min_far;
    projection_matrix[3][2] = -1;

    return (projection_matrix.transpose());
}
