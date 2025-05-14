/*
Exercise 00 : Add, Subtract and Scale
*/

#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"

void vector_tests()
{
    // Vector operations
    ft::Vector<double> v1 = {1, 2, 3};
    ft::Vector<double> v2 = {4, 5, 6};
    ft::Vector<double> v3 = v1 + v2;
    ft::Vector<double> v4 = v1 - v2;
    ft::Vector<double> v5 = v1 * 2;

    std::cout << "Vector addition:" << std::endl;
    std::cout << v1 << " +\n" << v2 << " =\n" << v3 << std::endl;
    std::cout << "Vector subtraction:" << std::endl;
    std::cout << v1 << " -\n" << v2 << " =\n" << v4 << std::endl;
    std::cout << "Vector scaling:" << std::endl;
    std::cout << v1 << " * 2 =\n" << v5 << std::endl;

    // Vector with different sizes (must throw an exception)
    ft::Vector<double> v6 = {1, 2};
    ft::Vector<double> v7 = {4, 5, 6};
    try {
        ft::Vector<double> v8 = v6 + v7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
    try {
        ft::Vector<double> v9 = v6 - v7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
}

void matrix_tests()
{
    // Matrix operations
    ft::Matrix<double> m1 = {{1, 2}, {3, 4}};
    ft::Matrix<double> m2 = {{5, 6}, {7, 8}};
    ft::Matrix<double> m3 = m1 + m2;
    ft::Matrix<double> m4 = m1 - m2;
    ft::Matrix<double> m5 = m1 * 2;

    std::cout << "Matrix addition:" << std::endl;
    std::cout << m1 << " +\n" << m2 << " =\n" << m3 << std::endl;
    std::cout << "Matrix subtraction:" << std::endl;
    std::cout << m1 << " -\n" << m2 << " =\n" << m4 << std::endl;
    std::cout << "Matrix scaling:" << std::endl;
    std::cout << m1 << " * 2 =\n" << m5 << std::endl;

    // Matrix with different sizes (must throw an exception)
    ft::Matrix<double> m6 = {{1, 2, 3}, {4, 5, 6}};
    ft::Matrix<double> m7 = {{7, 8}, {9, 10}};
    try {
        ft::Matrix<double> m8 = m6 + m7;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // OK
    }
    try {
        ft::Matrix<double> m9 = m6 - m7;
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