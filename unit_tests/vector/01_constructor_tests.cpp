/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 16:51:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int v_constructor_test(void)
{
    // Default constructor
    {
        ft::Vector<int> ft_default;

        if (ft_default.size() != std::make_pair<u_int64_t, u_int64_t>(0, 0))
            return (-1);
    }

    return (0);
}
