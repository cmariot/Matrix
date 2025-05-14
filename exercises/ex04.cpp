/*
Exercise 4 : Norm
*/


#include <iostream>
#include "vector.hpp"
#include "utils.hpp"

int main()
{
    ft::Vector<float> v1 = {4, 6};

    // Norm 1, also called Manhattan norm or taxicab norm
    // It's named this way because it is the distance a taxi would have to drive in a grid-like street pattern to get from one point to another.
    // For example, if you want to go from (0, 0) to (4, 6), the taxi would have to drive 4 blocks east and 6 blocks north, for a total of 10 blocks.
    std::cout << "Norm 1: " << v1.norm_1() << std::endl;

    // Norm 2, euclidian norm
    // It's the length of the vector in the Euclidean space.
    // For example, if you want to go from (0, 0) to (4, 6), the length of the vector is the distance between the two points, which is 7.2111.
    // This is the same as the length of the hypotenuse of a right triangle with legs of length 4 and 6.
    // A^2 + B^2 = C^2
    // C = sqrt(A^2 + B^2)
    // In this case, C = sqrt(4^2 + 6^2) = sqrt(16 + 36) = sqrt(52) = 7.2111
    std::cout << "Norm 2: " << v1.norm() << std::endl;

    // Norm Infinity
    // It's the maximum absolute value of the elements of the vector.
    // For example, if you want to go from (0, 0) to (4, 6), the maximum absolute value of the elements is 6.
    std::cout << "Norm Infinity: " << v1.norm_inf() << std::endl;

    return (0);
}