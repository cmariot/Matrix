/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:03:15 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/11 13:42:59 by cmariot          ###   ########.fr       */
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

int     v_addition_test(void);
int     v_substraction_test(void);
int     v_scale_test(void);
int     v_linear_combination_test(void);
int     v_linear_interpolation_test(void);
int     v_dot_product_test(void);


/* ************************************************************************** */
/*                                                                            */
/*                                    MATRIX                                  */
/*                                                                            */
/* ************************************************************************** */


int		matrix_launcher(void);

int		m_constructor_test(void);

int     m_addition_test(void);
int     m_substraction_test(void);
int     m_scale_test(void);
int     m_linear_interpolation_test(void);


#endif
