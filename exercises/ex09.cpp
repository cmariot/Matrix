/*
Exercise 09 : Transpose
*/

# include <iostream>
# include "vector.hpp"
# include "matrix.hpp"
# include "utils.hpp"


int main()
{

    // La transposition d'une matrice est l'opération qui consiste à échanger ses lignes et ses colonnes.

    ft::Matrix<int> m1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "Matrice d'origine :\n" << m1 << std::endl;
    ft::Matrix<int> m2 = m1.transpose();
    std::cout << "Matrice transposée :\n" << m2 << std::endl;

    return (0);
}