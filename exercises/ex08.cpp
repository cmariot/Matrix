/*
Exercise 08 : Trace
*/

# include <iostream>
# include "vector.hpp"
# include "matrix.hpp"
# include "utils.hpp"


int main()
{

    // La trace d'une matrice est la somme de ses éléments diagonaux (diagonale principale i, i) d'une matrice carrée.

    ft::Matrix<int> m1 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    std::cout << "Trace de la matrice : " << m1.trace() << std::endl;

    return (0);
}