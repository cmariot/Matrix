/*
Exercise 00 : Add, Subtract and Scale

*/

#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"


void vector_tests()
{
    // Vector operations
    ft::Vector v1 = {1, 2, 3};
    ft::Vector v2 = {4, 5, 6};
    ft::Vector v3 = v1 + v2;
    ft::Vector v4 = v1 - v2;
    ft::Vector v5 = v1 * 2;

    std::cout << "Vector addition:" << std::endl;
    std::cout << v1 << " +\n" << v2 << " =\n" << v3 << std::endl;
    std::cout << "Vector subtraction:" << std::endl;
    std::cout << v1 << " -\n" << v2 << " =\n" << v4 << std::endl;
    std::cout << "Vector scaling:" << std::endl;
    std::cout << v1 << " * 2 =\n" << v5 << std::endl;

    // Vector with different sizes (must throw an exception)
    ft::Vector v6 = {1, 2};
    ft::Vector v7 = {4, 5, 6};
    try {
        ft::Vector v8 = v6 + v7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
    try {
        ft::Vector v9 = v6 - v7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
}

void matrix_tests()
{
    // Matrix operations
    ft::Matrix m1 = {{1, 2}, {3, 4}};
    ft::Matrix m2 = {{5, 6}, {7, 8}};
    ft::Matrix m3 = m1 + m2;
    ft::Matrix m4 = m1 - m2;
    ft::Matrix m5 = m1 * 2;

    std::cout << "Matrix addition:" << std::endl;
    std::cout << m1 << " +\n" << m2 << " =\n" << m3 << std::endl;
    std::cout << "Matrix subtraction:" << std::endl;
    std::cout << m1 << " -\n" << m2 << " =\n" << m4 << std::endl;
    std::cout << "Matrix scaling:" << std::endl;
    std::cout << m1 << " * 2 =\n" << m5 << std::endl;

    // Matrix with different sizes (must throw an exception)
    ft::Matrix m6 = {{1, 2, 3}, {4, 5, 6}};
    ft::Matrix m7 = {{7, 8}, {9, 10}};
    try {
        ft::Matrix m8 = m6 + m7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
    try {
        ft::Matrix m9 = m6 - m7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
}


int main()
{
    std::cout << "============================" << std::endl;
    std::cout << "Vector Tests" << std::endl;
    std::cout << "============================" << std::endl;
    vector_tests();
    std::cout << "\n" << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "Matrix Tests" << std::endl;
    std::cout << "============================" << std::endl;
    matrix_tests();
    std::cout << "\n" << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "All tests completed." << std::endl;
    std::cout << "============================" << std::endl;


    return (0);
}