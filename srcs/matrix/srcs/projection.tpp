/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/13 10:09:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.hpp"

template <typename T>
ft::Matrix<T>   ft::Matrix<T>::projection(float fov, float ratio, float near, float far) const
{

    /*

       Return a projection matrix that will be used to transform an image
       depending on the new parameters

    */

    (void)fov;
    (void)ratio;
    (void)near;
    (void)far;

    ft::Matrix<T> object_to_world = ft::Matrix<T>(4, 4);
    ft::Matrix<T> world_to_camera = ft::Matrix<T>(4, 4);
    ft::Matrix<T> camera_to_screen = ft::Matrix<T>(4, 4);

    // Fov vertical/horizontal
    // Ratio : screen height / width
    // Near : distance between camera / near screen
    // Far : distance between camera / far screen

    // Steps (?) :
    // - Remapping z'
    // - Camera fov

    float m22_coeff = -(far) / (far - near);
    float m23_coeff = m22_coeff * near;

    camera_to_screen[0][0] = 1;
    camera_to_screen[1][1] = 1;
    camera_to_screen[2][2] = m22_coeff;
    camera_to_screen[2][3] = m23_coeff;
    camera_to_screen[3][2] = -1;

    std::cout << camera_to_screen << std::endl;

    return (camera_to_screen);
}
