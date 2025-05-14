/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:56 by cmariot           #+#    #+#             */
/*   Updated: 2024/04/16 12:47:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_TPP
#define NORM_TPP

#include "vector.hpp"
#include <complex>

// Norms always return real numbers, even for complex-valued vectors.

template <typename T>
float ft::Vector<T>::norm() const
{
    /*
    Euclidean norm is the square root of the sum of the squares of the elements.

    pythagoras : a^2 + b^2 = c^2
    -> c = sqrt(a^2 + b^2)
    */

    float result = 0;
    const_iterator it = this->begin();

    while (it != this->end())
    {
        result += std::pow(*it, 2);
        ++it;
    }
    return std::pow(result, 0.5);
}

template <typename T>
float ft::Vector<T>::norm_1() const
{
    /*
    The 1-norm is simply the sum of the absolute values of the columns.
    */

    float result = 0;
    const_iterator it = this->begin();

    while (it != this->end())
    {
        result += std::max(-*it, *it);
        ++it;
    }
    return result;
}

template <typename T>
float ft::Vector<T>::norm_inf() const
{
    /*
    Infinity norm is the maximum absolute value of the elements.
    */

    float result = 0;
    const_iterator it = this->begin();

    while (it != this->end())
    {
        result = std::max(result, std::max(-*it, *it));
        ++it;
    }
    return result;
}

#endif