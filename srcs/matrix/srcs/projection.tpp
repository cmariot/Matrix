/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 16:09:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
ft::Matrix<T>   ft::Matrix<T>::projection(float fov, float ratio, float near, float far) const
{
    (void)fov;
    (void)ratio;
    (void)near;
    (void)far;

    ft::Matrix<T> object_to_world = ft::Matrix<T>(4, 4);
    ft::Matrix<T> world_to_camera = ft::Matrix<T>(4, 4);
    ft::Matrix<T> camera_to_screen = ft::Matrix<T>(4, 4);

    return (*this);
}
