/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:03:15 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/05 14:49:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "libunit.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                    VECTOR                                  */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"

int		vector_launcher(void);

int		v_constructor_test(void);


/* ************************************************************************** */
/*                                                                            */
/*                                    MATRIX                                  */
/*                                                                            */
/* ************************************************************************** */


int		matrix_launcher(void);

int		m_constructor_test(void);

#endif