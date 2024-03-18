/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:03:15 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/18 16:57:42 by cmariot          ###   ########.fr       */
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

int	vector_launcher(void);
int	v_constructor_test(void);
int v_addition_test(void);
int v_subtraction_test(void);
int v_scale_test(void);
int v_linear_combination_test(void);
int v_linear_interpolation_test(void);
int v_dot_product_test(void);
int v_norm_test(void);
int v_cosine_test(void);
int v_cross_product_test(void);


/* ************************************************************************** */
/*                                                                            */
/*                                    MATRIX                                  */
/*                                                                            */
/* ************************************************************************** */


int	matrix_launcher(void);
int	m_constructor_test(void);
int m_addition_test(void);
int m_subtraction_test(void);
int m_scale_test(void);
int m_linear_interpolation_test(void);
int m_multiplication_test(void);
int m_trace_test(void);
int m_transpose_test(void);
int m_row_echelon_test(void);
int m_determinant_test(void);
int m_inverse_test(void);
int m_rank_test(void);
int m_projection_test(void);



#endif
