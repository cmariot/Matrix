/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:41 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/26 10:22:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "matrix.hpp"
# include <vector>
# include <initializer_list>

namespace ft
{

    template <typename T>
    class Matrix;

    template <typename T>
    class Vector
    {

        /*
        Vectors are ordered lists of objects that can be accessed by their index.
        */

        public:

            typedef T                           value_type;
            typedef T &                         reference;
            typedef const T &                   const_reference;
            typedef size_t                      size_type;
            typedef std::vector<value_type>     std_vec;

            Vector();
            Vector(const size_type & size);
            Vector(const size_type & size, const_reference val);
            Vector(const std::initializer_list<T> & initList);
            Vector(const Vector & copy);
            Vector(const Matrix<T> & copy);

            ~Vector();

            size_type        size() const;
            void             resize (size_type n);
            void             clear();

            Vector           operator + (const Vector & rhs) const;
            Vector &         operator += (const Vector & rhs);
            Vector &         add(const Vector & rhs);

            Vector           operator - (const Vector & rhs) const;
            Vector &         operator -= (const Vector & rhs);
            Vector &         sub(const Vector &rhs);

            Vector           operator * (const_reference scalar) const;
            Vector &         operator *= (const_reference scalar);
            Vector &         scl(const_reference scalar);

            float            dot(const Vector<T> & rhs) const;

            float            norm() const;
            float            norm_1() const;
            float            norm_inf() const;

            inline T &       operator [] (const size_type & pos);
            inline const T & operator [] (const size_type & pos) const;

            Vector &         operator = (const Vector & rhs);

            bool             operator == (const Vector & rhs) const;
            bool             operator != (const Vector & rhs) const;

            // Operator << : Display the vector
            friend std::ostream & operator << (std::ostream & os, const Vector & vector)
            {
                const_iterator it = vector.begin();
                const int cell_width = 10;
                size_t cols = vector.size();

                if (cols == 0)
                    return os << "Empty Vector";


                os << std::setprecision(2) << std::fixed;
                auto print_separator = [&]() {
                    os << "  +";
                    for (size_t j = 0; j < cols; ++j)
                        os << std::string(cell_width, '-') << "+";
                    os << "\n";
                };

                print_separator();
                os << "  |";
                for (size_t j = 0; j < cols; ++j)
                {
                    os << std::setw(cell_width) << *it << "|";
                    ++it;
                }
                os << "\n";
                print_separator();

                return os;
            }

            typedef typename std_vec::iterator                   iterator;
            typedef typename std_vec::const_iterator             const_iterator;
            typedef typename std_vec ::reverse_iterator          reverse_iterator;
            typedef typename std_vec::const_reverse_iterator     const_reverse_iterator;

            iterator                begin();
            iterator                end();
            const_iterator          begin() const;
            const_iterator          end() const;
            reverse_iterator        rbegin();
            reverse_iterator        rend();
            const_reverse_iterator  rbegin() const;
            const_reverse_iterator  rend() const;

        private:

            std::vector<T>  _vector;

    };

}

# include "implementations/constructors.tpp"
# include "implementations/size.tpp"
# include "implementations/addition.tpp"
# include "implementations/subtraction.tpp"
# include "implementations/scale.tpp"
# include "implementations/dot_product.tpp"
# include "implementations/norm.tpp"
# include "implementations/access.tpp"
# include "implementations/assign.tpp"
# include "implementations/compare.tpp"
# include "implementations/iterators.tpp"

#endif
