/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:14:10 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/19 10:09:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "vector.hpp"
# include <iostream>
# include <list>
# include <stdexcept>
# include <limits>


namespace ft
{

    template <typename T>
    ft::Vector<T> linear_combination(const std::list<ft::Vector<T> > &u, const std::list<T> &coeffs)
    {
        /*
        Linear combination of two lists u and coeffs is a vector w defined as:
        w = c1 * u1 + c2 * u2 + ... + cn * un

        Example:

            u = list({1, 0, 0}, {0, 1, 0}, {0, 0, 1})
            coeffs = {10, -2, 0.5}

            result = 10 * u1 + (-2) * u2 + 0.5 * u3
            result = {10, -2, 0.5}

        It's used to get the span of a set of vectors.
        The span of a set of vectors is the set of all possible linear combinations of the vectors.

        */

        if (u.size() != coeffs.size())
            throw std::length_error("Lists are not the same size.");
        else if (u.size() == 0)
            throw std::length_error("Lists are empty.");

        typename std::list<ft::Vector<T>>::const_iterator   it_u = u.begin();
        typename std::list<T>::const_iterator               it_coeff = coeffs.begin();
        ft::Vector<T>                                       result(it_u->size());

        // For each element in u and coeffs
        while (it_u != u.end())
        {

            // Check if all vectors in u have the same size
            if (it_u->size() != result.size())
                throw std::length_error("Vectors are not the same dimension.");

            else if (it_u->size() == 0)
                throw std::length_error("Vectors are empty.");

            typename ft::Vector<T>::const_iterator it_vec = it_u->begin();
            typename ft::Vector<T>::iterator it_res = result.begin();

            // Compute the linear combination
            while (it_res != result.end())
            {
                *it_res += *it_vec * *it_coeff;
                ++it_res;
                ++it_vec;
            }

            // Move to the next element
            ++it_u;
            ++it_coeff;
        }
        return result;
    }
}


template <typename T>
T lerp(const T &a, const T &b, const float &t)
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
float angle_cos(const ft::Vector<T> & u, const ft::Vector<T> & v)
{
    using std::conj;
    using std::sqrt;
    using std::abs;

    if (u.size() != v.size())
        throw std::length_error("The two vectors must have the same size.");
    else if (u.size() == 0)
        throw std::length_error("The two vectors must not be empty.");

    auto dot_product = decltype(conj(u[0]) * v[0])();
    auto norm_u = decltype(abs(u[0]))();
    auto norm_v = decltype(abs(v[0]))();

    for (size_t i = 0; i < u.size(); ++i)
    {
        dot_product += conj(u[i]) * v[i];
        norm_u += abs(u[i]) * abs(u[i]);
        norm_v += abs(v[i]) * abs(v[i]);
    }

    if (norm_u == 0 || norm_v == 0)
        throw std::invalid_argument("The two vectors must not be null.");

    // Retourne la partie réelle du cosinus de l'angle
    return std::real(dot_product / (sqrt(norm_u) * sqrt(norm_v)));
}


template <typename T>
ft::Vector<T> cross_product(const ft::Vector<T> & u, const ft::Vector<T> & v)
{
    if (u.size() != 3 || v.size() != 3)
        throw std::length_error("The two vectors must be 3 dimension vectors.");

    return ft::Vector<T>(
        {
            u[1] * v[2] - u[2] * v[1],
            u[2] * v[0] - u[0] * v[2],
            u[0] * v[1] - u[1] * v[0]
        }
    );
}
#endif