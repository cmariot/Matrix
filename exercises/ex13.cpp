/*
Exercise 13 : Rank
*/

# include <iostream>
# include "matrix.hpp"
# include "vector.hpp"

int main()
{

    // Le rang d'une matrice est le nombre de dimensions dans l'output de la transformation linéaire associée à la matrice.
    // En d'autres termes, le rang d'une matrice est le nombre de colonnes linéairement indépendantes dans la matrice.
    // Par exemple, si on a une matrice 2x3 qui effectue une transformation linéaire de R^3 vers R^2, le rang de la matrice est 2.
    // Si on a une matrice 2x3 qui effectue une transformation linéaire de R^3 vers R^2, mais que les colonnes de la matrice sont linéairement dépendantes (alignées sur une même droite), le rang de la matrice est 1.

    // We have some language that’s a bit more specific than just saying zero-determinant. When the output of a transformation is a line, meaning it is one-dimensional, we say the transformation has a rank of 1.

    // When the output of a transformation is a plane, meaning it is two-dimensional, we say the transformation has a rank of 2.

    // And when the output of a transformation is all of space, meaning it is three-dimensional, we say the transformation has a rank of 3.

    ft::Matrix<double> m1 = {
        {1, -2, 4},
        {-2, 4, -8},
        {5, -10, 20}
    };

    std::cout << "Matrix m1: " << std::endl;
    std::cout << m1 << std::endl;
    std::cout << "Rank of m1: " << m1.rank() << "\n" << std::endl;

    ft::Vector<double> v1 = {1, -2, 5};
    ft::Vector<double> v2 = {-2, 4, -10};
    ft::Vector<double> v3 = {4, -8, 20};

    std::cout << "Vector v1: " << std::endl;
    std::cout << v1 << std::endl;
    std::cout << "Vector v2: " << std::endl;
    std::cout << v2 << std::endl;
    std::cout << "Vector v3: " << std::endl;
    std::cout << v3 << std::endl;

    // The rank of a matrix is the number of linearly independent rows or columns in the matrix. In other words, it is the maximum number of linearly independent vectors in the row space or column space of the matrix.

    std::cout << "\nVector v2 * -1/2: " << std::endl;
    std::cout << v2 * -0.5 << std::endl;
    std::cout << "Vector v3 * 1/4: " << std::endl;
    std::cout << v3 * 0.25 << std::endl;

    return (0);
}