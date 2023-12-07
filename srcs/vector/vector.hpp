/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:41 by cmariot           #+#    #+#             */
/*   Updated: 2023/12/07 15:21:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../matrix/matrix.hpp"
#include <vector>
#include <list>
#include <initializer_list>


namespace ft
{

    template <typename T>
    class Vector
    {

        /*
        Vectors are ordered lists of objects that can be accessed by their index.
        */

        typedef T               value_type;
        typedef T &             reference;
        typedef const T &       const_reference;
        typedef size_t          size_type;


        public:

            Vector();
            Vector(size_type size);
            Vector(size_type size, const_reference val);
            Vector(std::initializer_list<T> initList);
            Vector(const Vector &copy);
            Vector(const Matrix<T> &copy);

            ~Vector();

            size_type size() const;

            // Addition : Add two vectors
            Vector operator+(const Vector &rhs) const
            {
                Vector result(*this);

                if (result.size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < result.size(); i++)
                    result[i] += rhs[i];
                return result;
            }

            // Operator += : Add two vectors
            Vector &operator+=(const Vector &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] += rhs[i];
                return *this;
            }

            // add : Add two vectors
            Vector &add(const Vector &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] += rhs[i];
                return *this;
            }

            // Substraction : Substract two vectors
            Vector operator-(const Vector &rhs) const
            {
                Vector result(*this);

                if (result.size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < result.size(); i++)
                    result[i] -= rhs[i];
                return result;
            }

            // Operator -= : Substract two vectors
            Vector &operator-=(const Vector &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] -= rhs[i];
                return *this;
            }

            // Substract : Substract two vectors
            Vector &sub(const Vector &rhs)
            {
                if (this->size() != rhs.size())
                    throw std::length_error("Vectors are not the same size.");
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] -= rhs[i];
                return *this;
            }

            // Operator * : Scale a vector by a scalar
            Vector operator*(const_reference rhs) const
            {
                Vector result(*this);

                for (size_type i = 0; i < result.size(); i++)
                    result[i] *= rhs;
                return result;
            }

            // Operator *= : Scale a vector
            Vector operator*=(const_reference rhs)
            {
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] *= rhs;
                return *this;
            }

            // Scale : Scale a vector
            Vector &scl(const_reference rhs)
            {
                for (size_type i = 0; i < this->size(); i++)
                    (*this)[i] *= rhs;
                return *this;
            }

            // Linear combination : Linear combination of two vectors
            static Vector linear_combination(std::list<Vector<double> > u, std::list<double> v)
            {
                /*
                Linear combination of a list of vectors and a list of scalars.
                Use std::fma()

                Lets imagine we have a vector {1.0, 1.0}, we can perform a
                linear interpolation with [2.0, 4.0] by multiplying the vector by the coefficients.

                -> {2.0, 4.0}

                Now if we have more than 1 vectors, we need to addition the vector values.
                Let's add a vector {2.0, 2.0} and coefficients [2.0, 1.0]

                -> {2.0, 4.0} + {4.0, 2.0}
                -> {6.0, 6.0}

                1st : scale vector by the coefficients
                2nd : addition of the scaled vectors
                */

                if (u.size() != v.size())
                    throw std::length_error("Lists are not the same size.");

                // Linear combination
                ft::Vector<double> result(u.size());

                while (u.size() > 0)
                {
                    result += u.front().scl(v.front());
                    std::cout << "Step " << result << std::endl;
                    u.pop_front();
                    v.pop_front();
                }

                return (result);
            }

            // Operator << : Display the vector
            friend std::ostream &operator<<(std::ostream &os, const Vector &vector)
            {
                os << "[";
                for (size_type i = 0; i < vector._vector.size(); i++)
                {
                    os << vector._vector[i];
                    if (i < vector._vector.size() - 1)
                        os << ", ";
                }
                os << "]";
                return os;
            }

            // Operator [] : Access element
            reference operator[](size_type pos)
            {
                return _vector[pos];
            }

            const_reference operator[](size_type pos) const
            {
                return _vector[pos];
            }

            // Operator = : Assign content
            Vector &operator=(const Vector &rhs)
            {
                _vector = rhs._vector;
                return *this;
            }

            Vector &operator=(Vector &rhs)
            {
                _vector = rhs._vector;
                return *this;
            }

            // Operator == : Compare content
            bool operator==(const Vector &rhs) const
            {
                if (_vector.size() != rhs._vector.size())
                    return false;
                for (size_type i = 0; i < _vector.size(); i++)
                    if (_vector[i] != rhs._vector[i])
                        return false;
                return true;
            }

            // Operator != : Compare content
            bool operator!=(const Vector &rhs) const
            {
                return !(*this == rhs);
            }

        private:

            std::vector<T> _vector;

    };


}

// Constructor : Default
template <typename T>
ft::Vector<T>::Vector()
{
    _vector = std::vector<T>();
}

// Constructor : Size
template <typename T>
ft::Vector<T>::Vector(size_type size)
{
    _vector = std::vector<T>(size);
}

// Constructor : Size and value
template <typename T>
ft::Vector<T>::Vector(size_type size, const_reference val)
{
    _vector = std::vector<T>(size, val);
}

// Constructor : Copy
template <typename T>
ft::Vector<T>::Vector(const Vector &copy)
{
    _vector = copy._vector;
}

// Constructor : Copy from Matrix
template <typename T>
ft::Vector<T>::Vector(const Matrix<T> &copy)
{
    for (size_type i = 0; i < copy.size()[0]; i++)
        for (size_type j = 0; j < copy.size()[1]; j++)
            _vector.push_back(copy[i][j]);
}

// Constructor : Initializer list
template <typename T>
ft::Vector<T>::Vector(std::initializer_list<T> initList)
{
    _vector = std::vector<T>(initList);
}

// Destructor
template <typename T>
ft::Vector<T>::~Vector()
{
    _vector.clear();
}


// Size
template <typename T>
typename ft::Vector<T>::size_type ft::Vector<T>::size() const
{
    return _vector.size();
}


#endif
