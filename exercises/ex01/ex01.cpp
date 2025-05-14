/*
Exercise 01 : Linear Combination
*/

#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include <list>

int main()
{
    ft::Vector i = {1, 0};  // length 1 pointing to the right
    ft::Vector j = {0, 1};  // length 1 pointing upwards

    // The vectors i and j are special unit vectors, they are called the basis vectors of the 2D space.
    // They are used to define the 2D space and any vector in this space can be expressed as a linear combination of i and j.
    // A linear combination of two vectors is a vector that can be expressed as a sum of the two vectors multiplied by scalars.
    // For example, the vector v = [2 ; 3] can be expressed as a linear combination of i and j:
    // v = 2 * i + 3 * j

    std::list<ft::Vector<int>> u = {i, j};  // list of vectors
    std::list<int> v = {2, 3};              // list of scalars

    try {
        ft::Vector result = ft::linear_combination(u, v);
        std::cout << "Linear combination result:\n" << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // The set of all possible vectors you can reach with linear combinations of a given pair of vectors is called the "span" of those two vectors.

    return 0;
}
