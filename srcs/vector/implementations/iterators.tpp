/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:34:53 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 18:36:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include "vector.hpp"

template <typename T>
typename ft::Vector<T>::iterator ft::Vector<T>::begin()
{
    return _vector.begin();
}

template <typename T>
typename ft::Vector<T>::iterator ft::Vector<T>::end()
{
    return _vector.end();
}

template <typename T>
typename ft::Vector<T>::const_iterator ft::Vector<T>::begin() const
{
    return _vector.begin();
}

template <typename T>
typename ft::Vector<T>::const_iterator ft::Vector<T>::end() const
{
    return _vector.end();
}

template <typename T>
typename ft::Vector<T>::reverse_iterator ft::Vector<T>::rbegin()
{
    return _vector.rbegin();
}

template <typename T>
typename ft::Vector<T>::reverse_iterator ft::Vector<T>::rend()
{
    return _vector.rend();
}

template <typename T>
typename ft::Vector<T>::const_reverse_iterator ft::Vector<T>::rbegin() const
{
    return _vector.rbegin();
}

template <typename T>
typename ft::Vector<T>::const_reverse_iterator ft::Vector<T>::rend() const
{
    return _vector.rend();
}

#endif