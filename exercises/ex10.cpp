/*
Exercise 10 : Row Echelon Form
*/

# include <iostream>
# include "vector.hpp"
# include "matrix.hpp"
# include "utils.hpp"


int main()
{

    // Jusqu'à maintenant, on a surtout vu les matrices comme des representations de donnees dans l'espace.
    // Mais on peut aussi les utiliser pour representer des systemes d'equations lineaires.

    // Par exemple, le systeme d'equations suivant :
    // 2x + 3y = 1
    // 4x + 6y = 2

    // Peut etre represente par la matrice suivante :
    // 2 3 | 1
    // 4 6 | 2

    // La forme echelon d'une matrice est une forme de la matrice qui facilite la resolution de systemes d'equations lineaires. Elle est obtenue en appliquant des operations sur les lignes de la matrice pour la transformer en une forme plus simple.

    ft::Matrix<int> m1 = {
        {2, 3, 1},
        {4, 6, 2}
    };

    std::cout << "Matrice d'origine :\n" << m1 << std::endl;
    ft::Matrix<int> m2 = m1.row_echelon();
    std::cout << "Matrice en forme echelon :\n" << m2 << std::endl;

    // Une matrice est en forme échelonnée si elle respecte trois règles :

    // 1. Les lignes constituées uniquement de zéros sont en bas de la matrice.
    // 2. Le premier nombre non nul (appelé pivot) d'une ligne est strictement à droite du pivot de la ligne précédente.
    // 3. Les éléments sous chaque pivot sont nuls.

    // On appelle ça « échelonnée » parce que les pivots forment un escalier qui descend vers la droite.


    // À quoi ça sert ?

    // 1. Résolution de systèmes linéaires
    // La forme échelonnée permet de simplifier un système d’équations pour l'amener à une version plus facile à résoudre, souvent par remontée (back-substitution).

    // 2. Calcul du rang d'une matrice
    // Le nombre de lignes non nulles dans la forme échelonnée te donne le rang de la matrice.

    // 3. Comprendre l’indépendance linéaire
    // Les lignes (ou colonnes) qui correspondent à des pivots représentent des vecteurs linéairement indépendants.


    // Pour resoudre un système d'équations linéaires, on peut utiliser la méthode de substitution arrière (back-substitution) sur la matrice en forme échelonnée.
    // Par exemple, si on a la matrice suivante en forme échelonnée :
    // 1 0 | -1
    // 0 1 | 1
    // On peut résoudre le système d'équations correspondant en commençant par la dernière ligne :
    // y = 1
    // Puis en substituant cette valeur dans la première ligne :
    // x = -1
    // On obtient donc la solution du système d'équations : x = -1, y = 1.

    // 2 * -1 + 3 * 1 = 1
    // 4 * -1 + 6 * 1 = 2

    return (0);
}