/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:56 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:55:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_TPP
# define NORM_TPP

# include "vector.hpp"

template <typename T>
T ft::Vector<T>::norm() const
{
    /*
    Euclidean norm is the square root of the sum of the squares of the elements.

    pythagoras : a^2 + b^2 = c^2
    -> c = sqrt(a^2 + b^2)
    */

    const_iterator it = this->begin();
    double result = 0.0;

    while (it != this->end())
    {
        result = std::fma(*it, *it, result);
        ++it;
    }
    return std::pow(result, 0.5);
}

template <typename T>
T ft::Vector<T>::norm_1() const
{
    /*
    The 1-norm is simply the sum of the absolute values of the columns.
    */

    const_iterator it = this->begin();
    double result = 0.0;

    while (it != this->end())
    {
        result += std::max(-*it, *it);
        ++it;
    }
    return result;
}

template <typename T>
T ft::Vector<T>::norm_inf() const
{
    /*
    Infinity norm is the maximum absolute value of the elements.
    */

    const_iterator it = this->begin();
    double result = 0.0;

    while (it != this->end())
    {
        result = std::max(result, std::max(-*it, *it));
        ++it;
    }
    return result;
}

#endif