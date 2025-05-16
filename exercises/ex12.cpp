/*
Exercise 12 : Inverse
*/

# include <iostream>
# include "matrix.hpp"

int main()
{
    // On a vu que les matrices sont des compositions de transformations linéaires.
    // Si on veut annuler une transformation linéaire, il faut appliquer la transformation inverse.
    // Par exemple, si on a une matrice qui effectue une rotation de 90 degrés dans le sens des aiguilles d'une montre, la matrice inverse effectuera une rotation de 90 degrés dans le sens inverse des aiguilles d'une montre.

    ft::Matrix<double> m1 = {
        {1, 1},
        {0, 1}
    };

    std::cout << "Matrix m1: " << std::endl;
    std::cout << m1 << std::endl;

    std::cout << "Inverse of m1: " << std::endl;
    std::cout << m1.inverse() << std::endl;

    // Une matrice qui ne modifie pas l'espace est la matrice identité.
    // Une matrice identité est une matrice carrée qui a des 1 sur la diagonale principale et des 0 ailleurs.
    // Par exemple, la matrice identité 2x2 est:
    // 1 0
    // 0 1
    // L'inverse de la matrice identité est elle-même.

    return (0);
}