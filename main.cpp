#include <iostream>
#include "matrix.hpp"
#include "vector.hpp"


void print_matrix() {
    ft::Matrix<int> m1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "Matrix m1:" << std::endl;
    std::cout << m1 << std::endl;
}

void print_vector() {
    ft::Vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << "Vector v1:" << std::endl;
    std::cout << v1 << std::endl;
}

void vector_addition() {
    ft::Vector<int> v1 = {1, 2, 3};
    ft::Vector<int> v2 = {4, 5, 6};
    ft::Vector<int> v3 = v1 + v2;
    std::cout << v1 << std::endl;
    std::cout << "+" << std::endl;
    std::cout << v2 << std::endl;
    std::cout << "=" << std::endl;
    std::cout<< v3 << std::endl;
}

void vector_subtraction() {
    ft::Vector<int> v1 = {7, 8, 9};
    ft::Vector<int> v2 = {4, 5, 6};
    ft::Vector<int> v3 = v1 - v2;
    std::cout << v1 << std::endl;
    std::cout << "-" << std::endl;
    std::cout << v2 << std::endl;
    std::cout << "=" << std::endl;
    std::cout<< v3 << std::endl;
}

void vector_scaling() {
    ft::Vector<int> v1 = {1, 2, 3};
    int scalar = 2;
    ft::Vector<int> v2 = v1 * scalar;
    std::cout << v1 << std::endl;
    std::cout << "*" << std::endl;
    std::cout << scalar << std::endl;
    std::cout << "=" << std::endl;
    std::cout<< v2 << std::endl;
}

int main() {
    // print_matrix();
    // print_vector();
    // vector_addition();
    // vector_subtraction();
    vector_scaling();
    return (0);
}
