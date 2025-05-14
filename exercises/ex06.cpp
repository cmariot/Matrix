/*
Exercise 5 : Cross Product
*/


#include <iostream>
#include "vector.hpp"
#include "utils.hpp"

int main()
{

    // The cross product is a vector operation that takes two vectors in 3D space and produces a third vector that is perpendicular to both of the original vectors.
    // The direction of the resulting vector is determined by the right-hand rule.
    // The norm of the resulting vector is equal to the area of the parallelogram formed by the two original vectors.

    ft::Vector<float> v1 = {0, 0, 1};
    ft::Vector<float> v2 = {1, 0, 0};

    ft::Vector<float> result = cross_product(v1, v2);

    std::cout << "Cross product of v1 and v2:\n" << result << std::endl;

    return (0);
}