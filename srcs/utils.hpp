/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:14:10 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/13 15:31:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "vector.hpp"
# include <iostream>


template <typename T>
T lerp(const T &a, const T &b, const double &t)
{
    /*
    Linearly interpolates between two points.

    Interpolates between the points a and b by the interpolant t.
    This is most commonly used to find a point some fraction of the way along
    a line between two endpoints
    (e.g. to move an object gradually between those points).
    */

    return (a + (b - a) * t);
}

template <typename T>
double angle_cos(const ft::Vector<T> &u, const ft::Vector<T> &v)
{
    /*
    Cosine of the angle between two vectors
    */

    if (u.size() != v.size())
        throw std::length_error("The two vectors must have the same size.");

    double dot_product = 0;
    double norm_u = 0;
    double norm_v = 0;

    for (size_t i = 0; i < u.size(); i++)
    {
        dot_product = std::fma(u[i], v[i], dot_product);
        norm_u = std::fma(u[i], u[i], norm_u);
        norm_v = std::fma(v[i], v[i], norm_v);
    }

    return (dot_product / (std::sqrt(norm_u) * std::sqrt(norm_v)));
}

template <typename T>
ft::Vector<T> cross_product(const ft::Vector<T> &u, const ft::Vector<T> &v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::length_error("The two vectors must be 3 dimmension vectors.");

    return ft::Vector<T>({
        std::fma(u[1], v[2], -u[2] * v[1]),
        std::fma(u[2], v[0], -u[0] * v[2]),
        std::fma(u[0], v[1], -u[1] * v[0])
    });
}

#endif