/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:38 by cmariot           #+#    #+#             */
/*   Updated: 2024/06/05 18:20:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_PRODUCT_TPP
#define DOT_PRODUCT_TPP

#include "vector.hpp"
#include <cmath>
#include <complex>     // Required for std::complex, std::conj, std::real
#include <type_traits> // Required for std::is_same, std::enable_if

// Helper functions for ft::Vector<T>::dot, using SFINAE
namespace ft {
namespace internal {

    // SFINAE Helper for non-complex types
    template <typename T_param>
    typename std::enable_if<!std::is_same<T_param, std::complex<double>>::value, double>::type
    dot_product_sum_element_dispatch(const T_param& v1_elem, const T_param& v2_elem) {
        return static_cast<double>(v1_elem * v2_elem);
    }

    // SFINAE Helper for std::complex<double> types
    template <typename T_param>
    typename std::enable_if<std::is_same<T_param, std::complex<double>>::value, double>::type
    dot_product_sum_element_dispatch(const T_param& v1_elem, const T_param& v2_elem) {
        return std::real(std::conj(v1_elem) * v2_elem);
    }

} // namespace internal
} // namespace ft

// Definition of ft::Vector<T>::dot
template <typename T>
float ft::Vector<T>::dot(const ft::Vector<T> &rhs) const
{
    if (this->size() != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    const_iterator it1 = this->begin();
    const_iterator it2 = rhs.begin();
    double result = 0.0;

    while (it1 != this->end()) {
        // Dispatch to the correct SFINAE-enabled helper
        result += ft::internal::dot_product_sum_element_dispatch(*it1, *it2);
        ++it1;
        ++it2;
    }
    return static_cast<float>(result);
}

#endif // DOT_PRODUCT_TPP