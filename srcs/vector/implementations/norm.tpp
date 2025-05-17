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
#include <cmath>

// Norms always return real numbers, even for complex-valued vectors.

// Helper for norm: get squared modulus for complex, square for real
namespace ft {
    template<typename T>
    float squared_modulus(const T& x) { return x * x; }
    template<typename T>
    float abs_value(const T& x) { return std::abs(x); }
    template<typename T>
    float abs_value(const std::complex<T>& x) { return std::abs(x); }
    template<typename T>
    float squared_modulus(const std::complex<T>& x) { return std::norm(x); }
}

// Euclidean norm
template <typename T>
float ft::Vector<T>::norm() const
{
    float result = 0;
    const_iterator it = this->begin();
    while (it != this->end())
    {
        result += ft::squared_modulus(*it);
        ++it;
    }
    return std::sqrt(result);
}

// 1-norm
template <typename T>
float ft::Vector<T>::norm_1() const
{
    float result = 0;
    const_iterator it = this->begin();
    while (it != this->end())
    {
        result += ft::abs_value(*it);
        ++it;
    }
    return result;
}

// Infinity norm
template <typename T>
float ft::Vector<T>::norm_inf() const
{
    float result = 0;
    const_iterator it = this->begin();
    while (it != this->end())
    {
        float absval = ft::abs_value(*it);
        if (absval > result)
            result = absval;
        ++it;
    }
    return result;
}

#endif