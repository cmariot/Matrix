// v = [ 2 ; 3 ]
// w = [ -3 ; 2]

// a * v + b * w = [ 7 ; 4 ]
// a * [ 2 ; 3 ] + b * [ -3 ; 2] = [ 7 ; 4 ]

// 1/
// a = 1
// b = -2

// a * v + b * w = [ 7 ; 4 ]
// [ 2 ; 3 ] + [ 6 ; -4] KO

// 2/
// a = -1
// b = 2
// a * v + b * w = [ 7 ; 4 ]
// [ -2 ; -3 ] + [ 6 ; -4] = [ 4 ; -7] KO

// 3/
// a = 2
// b = -1
// a * v + b * w = [ 7 ; 4 ]
// [ 4 ; 6 ] + [ 3 ; -2] = [ 7 ; 4] OK



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
    // Linear combination
    ft::Vector v1 = {1, 0};
    ft::Vector v2 = {0, 1};
    std::list<ft::Vector<int>> u = {v1, v2};
    std::list<int> v = {10, -2};

    try {
        ft::Vector result = ft::linear_combination(u, v);
        std::cout << "Linear combination result:\n" << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
