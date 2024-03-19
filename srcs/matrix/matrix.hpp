/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:37 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/13 11:58:29y cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <map>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include "../vector/vector.hpp"
#include <iomanip>

namespace ft
{

    template <typename T>
    class Vector;

    template <typename T>
    class Matrix
    {

        typedef T                               value_type;
        typedef T &                             reference;
        typedef const T &                       const_reference;
        typedef size_t                          size_type;


        public:

            Matrix();
            Matrix(size_type rows, size_type columns);
            Matrix(size_type rows, size_type columns, const_reference val);
            Matrix(std::initializer_list<std::initializer_list<T> > initList);
            Matrix(const Matrix &copy);
            Matrix(const ft::Vector<T> &copy);
            ~Matrix();

            std::map<bool, size_t>  size() const;
            bool                    is_square() const;

            Matrix                  operator + (const Matrix &rhs) const;
            Matrix &                operator += (const Matrix &rhs);
            Matrix &                add(const Matrix &rhs);

            Matrix                  operator - (const Matrix &rhs) const;
            Matrix &                operator -= (const Matrix &rhs);
            Matrix &                sub(const Matrix &rhs);

            Matrix                  operator * (const_reference rhs) const;
            Matrix                  operator * (const Matrix &rhs) const;
            Vector<T>               operator * (const Vector<T> &rhs) const;
            Matrix &                operator *= (const_reference rhs);
            Matrix &                operator *= (const Matrix<T> &rhs);
            Matrix &                operator *= (const Vector<T> &rhs);
            Matrix &                scl(const_reference rhs);
            Matrix &                mul_mat(const Matrix &rhs);
            Matrix &                mul_vec(const Vector<T> &rhs);

            T                       trace() const;
            Matrix                  transpose() const;

            Matrix                  row_echelon() const;

            T                       determinant() const;

            T                       cofactor(size_type i, size_type j) const;
            T                       minor(size_type i, size_type j) const;

            size_type               rank() const;

            Matrix                  inverse() const;

            Matrix                  adjoint() const;

            ft::Vector<T> &         operator [] (size_type pos);
            const ft::Vector<T> &  operator [] (size_type pos) const;

            Matrix &                operator = (const Matrix &rhs);

            bool                    operator == (const Matrix &rhs) const;
            bool                    operator != (const Matrix &rhs) const;

            // Operator << : Display the matrix
            friend std::ostream &   operator << (std::ostream &os, const Matrix &matrix)
            {

                os << "[" << std::endl;
                for (size_type i = 0; i < matrix.size()[0] ; i++)
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
                os << std::endl << "]";
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


#endif
