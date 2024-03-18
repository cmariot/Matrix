/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:57:38 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 14:57:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOT_PRODUCT_TPP
# define DOT_PRODUCT_TPP

# include "vector.hpp"

template <typename T>
T ft::Vector<T>::dot(const ft::Vector<T> & rhs) const
{
    if (this->size() != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    typename std::vector<T>::const_iterator it1 = this->_vector.begin();
    typename std::vector<T>::const_iterator it2 = rhs._vector.begin();
    double result = 0.0;

    while (it1 != this->_vector.end())
    {
        result = std::fma(*it1, *it2, result);
        ++it1;
        ++it2;
    }
    return result;
}

#endif