/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:53:35 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:50:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSIGN_TPP
# define ASSIGN_TPP

# include "vector.hpp"

// Operator = : Assign content
template <typename T>
ft::Vector<T> & ft::Vector<T>::operator = (const Vector &rhs)
{
    _vector = std::vector<T>(rhs._vector);
    return *this;
}

template <typename T>
ft::Vector<T> & ft::Vector<T>::operator = (Vector &rhs)
{
    _vector = std::vector<T>(rhs._vector);
    return *this;
}

#endif