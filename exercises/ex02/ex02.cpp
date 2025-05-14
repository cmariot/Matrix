/*
Exercise 01 : Linear Interpolation
*/

#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include <list>


int main()
{
    ft::Vector<double> a = {0, 0};
    ft::Vector<double> b = {0, 10};

    // L'interpolation linéaire est un concept qui consiste à approximer une valeur intermédiaire entre deux points connus par une droite (c’est-à-dire une fonction affine).

    try {
        ft::Vector<double> result = lerp(a, b, 0.5);
        // The result should be the midpoint between a and b, which is (0, 5)
        std::cout << "Linear interpolation result:\n" << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
