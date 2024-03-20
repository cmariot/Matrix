/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:50:26 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/20 10:01:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <iomanip>

#include "vector.hpp"
#include "iterators/matrix_const_iterators.hpp"
#include "iterators/matrix_iterators.hpp"

namespace ft
{

    template <typename T>
    class Matrix
    {

        typedef T                               value_type;
        typedef T &                             reference;
        typedef const T &                       const_reference;
        typedef size_t                          size_type;
        typedef matrix_iterator<T>              iterator;
        typedef matrix_const_iterator<T>        const_iterator;

        public:

            Matrix();
            Matrix(const size_type & rows, const size_type & columns);
            Matrix(const size_type & rows, const size_type & columns, const_reference val);
            Matrix(const std::initializer_list<std::initializer_list<T> > & initList);
            Matrix(const Matrix & copy);
            Matrix(const ft::Vector<T> & copy);
            ~Matrix();

            Matrix                  operator + (const Matrix & rhs) const;
            Matrix &                operator += (const Matrix & rhs);
            Matrix &                add(const Matrix & rhs);

            Matrix                  operator - (const Matrix & rhs) const;
            Matrix &                operator -= (const Matrix & rhs);
            Matrix &                sub(const Matrix & rhs);

            Matrix                  operator * (const_reference rhs) const;
            Matrix &                operator *= (const_reference rhs);
            Matrix &                scl(const_reference rhs);

            Matrix                  operator * (const Matrix & rhs) const;
            Matrix &                operator *= (const Matrix<T> & rhs);
            Matrix &                mul_mat(const Matrix & rhs);

            Vector<T>               operator * (const Vector<T> & rhs) const;
            Matrix &                operator *= (const Vector<T> & rhs);
            Matrix &                mul_vec(const Vector<T> & rhs);

            std::map<bool, size_t>  size() const;
            bool                    is_square() const;

            T                       trace() const;
            Matrix                  transpose() const;
            Matrix                  row_echelon() const;
            T                       determinant() const;
            T                       cofactor(size_type i, size_type j) const;
            T                       minor(size_type i, size_type j) const;
            size_type               rank() const;
            Matrix                  inverse() const;
            Matrix                  adjoint() const;

            ft::Vector<T> &         operator [] (const size_type & pos);
            const ft::Vector<T> &   operator [] (const size_type & pos) const;

            Matrix &                operator = (const Matrix &rhs);

            bool                    operator == (const Matrix &rhs) const;
            bool                    operator != (const Matrix &rhs) const;

            iterator                begin();
            iterator                end();
            const_iterator          begin() const;
            const_iterator          end() const;

            size_type               get_nb_columns() const;
            size_type               get_nb_lines() const;

            // Operator << : Display the matrix
            friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
            {

                os << "[" << std::endl;
                for (size_type i = 0; i < matrix.size()[0]; i++)
                {
                    os << "\t[";
                    for (size_type j = 0; j < matrix.size()[1]; j++)
                    {
                        os << std::fixed << std::setprecision(2) << std::setw(5);
                        os << matrix._matrix[i][j];
                        if (j < matrix.size()[1] - 1)
                            os << ", ";
                    }
                    os << "]";
                    if (i < matrix.size()[0] - 1)
                        os << ", " << std::endl;
                }
                os << std::endl
                   << "]";
                return (os);
            }

        private:

            ft::Vector<ft::Vector<T> > _matrix;

    };

}

ft::Matrix<float> projection(float fov, float ratio, float near, float far);

#include "implementations/constructors.tpp"
#include "implementations/assign.tpp"
#include "implementations/access.tpp"
#include "implementations/compare.tpp"
#include "implementations/size.tpp"
#include "implementations/is_square.tpp"
#include "implementations/addition.tpp"
#include "implementations/subtraction.tpp"
#include "implementations/multiplication.tpp"
#include "implementations/trace.tpp"
#include "implementations/transpose.tpp"
#include "implementations/determinant.tpp"
#include "implementations/rank.tpp"
#include "implementations/inverse.tpp"
#include "implementations/row_echelon.tpp"
#include "implementations/iterators.tpp"

#endif
