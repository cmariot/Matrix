/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:50:26 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 09:56:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
#define MATRIX_HPP

# include <map>
# include <iomanip>
# include <iostream>

# include "vector.hpp"
# include "iterators/matrix_iterators.hpp"
# include "iterators/matrix_const_iterators.hpp"

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
            size_type               get_nb_columns() const;
            size_type               get_nb_lines() const;

            bool                    is_square() const;

            T                       trace() const;

            Matrix                  transpose() const;

            Matrix                  row_echelon() const;

            T                       minor(const size_type & i, const size_type & j) const;
            T                       cofactor(const size_type & i, const size_type & j) const;
            T                       determinant() const;

            size_type               rank() const;

            Matrix                  adjoint() const;
            Matrix                  inverse() const;

            ft::Vector<T> &         operator [] (const size_type & pos);
            const ft::Vector<T> &   operator [] (const size_type & pos) const;

            Matrix &                operator = (const Matrix & rhs);

            bool                    operator == (const Matrix & rhs) const;
            bool                    operator != (const Matrix & rhs) const;

            iterator                begin();
            iterator                end();
            const_iterator          begin() const;
            const_iterator          end() const;


            // Operator << : Display the matrix
            friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
            {

                const_iterator it = matrix.begin();

                os << "[" << std::endl;
                while (it != matrix.end())
                {
                    os << " [" << std::fixed << std::setprecision(2) << std::setw(5) << *it << "]";
                    if (it + 1 != matrix.end())
                        os << ", ";
                    ++it;
                }
                os << std::endl << "]";
                return (os);
            }

        private:

            ft::Vector<ft::Vector<T> > _matrix;

    };

}

ft::Matrix<float> projection(float fov, float ratio, float near, float far);

# include "implementations/constructors.tpp"
# include "implementations/assign.tpp"
# include "implementations/access.tpp"
# include "implementations/compare.tpp"
# include "implementations/size.tpp"
# include "implementations/is_square.tpp"
# include "implementations/addition.tpp"
# include "implementations/subtraction.tpp"
# include "implementations/multiplication.tpp"
# include "implementations/trace.tpp"
# include "implementations/transpose.tpp"
# include "implementations/determinant.tpp"
# include "implementations/rank.tpp"
# include "implementations/inverse.tpp"
# include "implementations/row_echelon.tpp"
# include "implementations/iterators.tpp"

#endif
