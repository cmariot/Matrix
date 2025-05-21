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

template <typename T>
T ft::Vector<T>::dot(const ft::Vector<T> &rhs) const
{
    if (this->size() != rhs.size())
        throw std::length_error("Vectors are not the same size.");

    const_iterator it1 = this->begin();
    const_iterator it2 = rhs.begin();
    T result = T();

    while (it1 != this->end())
    {
        result += (*it1) * (*it2);
        ++it1;
        ++it2;
    }
    return result;
}

#endif