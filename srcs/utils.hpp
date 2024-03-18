/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:14:10 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 19:08:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "vector.hpp"
# include <iostream>
# include <list>
# include <cmath>
# include <stdexcept>
# include <limits>


namespace ft
{


    template <typename T>
    ft::Vector<T> linear_combination(const std::list<ft::Vector<T> > &u, const std::list<T> &v)
    {
        /*
        Linear combination of two lists u and v is a vector w defined as:
        w = v1 * u1 + v2 * u2 + ... + vn * un

        Example:

            u = list({1, 0, 0}, {0, 1, 0}, {0, 0, 1})
            v = {10, -2, 0.5}

            w = 10 * u1 + (-2) * u2 + 0.5 * u3
            w = {10, -2, 0.5}

        It's used to get the span of a set of vectors.
        The span of a set of vectors is the set of all possible linear combinations of the vectors.

        */

        if (u.size() != v.size())
            throw std::length_error("Lists are not the same size.");
        else if (u.size() == 0)
            throw std::length_error("Lists are empty.");

        typename std::list<ft::Vector<T>>::const_iterator   it_u = u.begin();
        typename std::list<T>::const_iterator               it_v = v.begin();
        ft::Vector<T>                                       result(it_u->size());

        // For each element in u and v
        while (it_u != u.end())
        {

            // Check if all vectors in u have the same size
            if (it_u->size() != result.size())
                throw std::length_error("Vectors are not the same dimension.");

            else if (it_u->size() == 0)
                throw std::length_error("Vectors are empty.");

            // Compute the linear combination
            for (typename ft::Vector<T>::size_type i = 0; i < result.size(); i++)
                result[i] = std::fma((*it_u)[i], *it_v, result[i]);

            // Move to the next element
            ++it_u;
            ++it_v;
        }
        return result;
    }
}


template <typename T>
T lerp(const T &a, const T &b, const double &t)
{
    /*
    Linearly interpolates between two points.

    Interpolates between the points a and b by the interpolar t.
    This is most commonly used to find a point some fraction of the way along
    a line between two endpoints
    (e.g. to move an object gradually between those points).
    */

    return (a + (b - a) * t);
}


template <typename T>
ft::Vector<T> cross_product(const ft::Vector<T> & u, const ft::Vector<T> & v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::length_error("The two vectors must be 3 dimension vectors.");

    return ft::Vector<T>(
        {
            std::fma(u[1], v[2], -u[2] * v[1]),
            std::fma(u[2], v[0], -u[0] * v[2]),
            std::fma(u[0], v[1], -u[1] * v[0])
        }
    );
}


template <typename T>
double angle_cos(const ft::Vector<T> & u, const ft::Vector<T> & v)
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


#endif