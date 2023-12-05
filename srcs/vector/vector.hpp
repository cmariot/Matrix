/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:41 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 18:11:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../matrix/matrix.hpp"
#include <vector>

namespace ft
{

    template <typename T>
    class Vector : public ft::Matrix<T>
    {

    };


}

#endif
