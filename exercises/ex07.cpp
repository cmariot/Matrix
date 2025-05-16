/*
Exercise 07 : Linear map, Matrix multiplication
*/

# include <iostream>
# include "vector.hpp"
# include "matrix.hpp"
# include "utils.hpp"

/*
On passe sur des operations sur les matrices.
Les matrices sont des tableaux de nombres, qui peuvent etre de n'importe quel type (int, float, double, etc).
Dans cet exercice, on va faire une multiplication de matrice par un vecteur (retourne un vecteur) et une multiplication de matrice par une matrice (retourne une matrice).
*/

int main()
{

    // Pour comprendre les multiplications matrices/vecteurs on va aborder le concept de transformation lineaire et sa relation avec les matrices.
    // The focus will simply be on what these linear transformations look like in the case of two dimensions, and how they relate to the idea of matrix-vector multiplication.

    // A linear transformation is a function that takes a vector as input and produces another vector as output, such that the following two properties hold:
    // 1. Additivity: T(u + v) = T(u) + T(v)
    // 2. Homogeneity: T(c * v) = c * T(v)
    // where u and v are vectors, c is a scalar, and T is the linear transformation.

    // In the 2D space, a linear transformation can be represented by a 2x2 matrix. The matrix is applied to the vector by multiplying the matrix by the vector.
    // The resulting space will always have parallel lines, and the angles between the lines will be preserved.

    // La matrice de transformation represente a quelles coordonnees i et j de la matrice d'origine correspondent les coordonnees i et j de la matrice de destination.
    // | a b |
    // | c d |
    // a et c sont les coordonnees du vecteur unitaire i, et b et d sont les coordonnees du vecteur unitaire j.
    // Si on a un vecteur x, y, le vecteur de destination sera :
    // | a * x + b * y |
    // | c * x + d * y |

    // Imaginons une matrice de transformation 2x2 qui effectue une rotation de 90 degrés dans le sens des aiguilles d'une montre. La matrice de transformation serait :
    // | 0  -1 |
    // | 1  0 |
    // Cette matrice de transformation prend un vecteur (x, y) et le transforme en (y, -x). Par exemple, si on applique cette matrice à un vecteur (1, 0), on obtient le vecteur (0, -1).

    // https://3b1b-posts.us-east-1.linodeobjects.com/content/lessons/2016/linear-transformations/figures/examples/RotationQuestion1.mp4#t=0.001

    ft::Vector<float> input_vector = {2, 3};
    ft::Matrix<float> transformation_matrix = {
        {0, -1},
        {1, 0}
    };

    ft::Vector<float> result_vector = transformation_matrix.mul_vec(input_vector);

    std::cout << "Result of the transformation:\n" << result_vector << std::endl;


    // La mutliplication de matrices va nous permettre de faire des transformations successives.
    // Par exemple, si on a une matrice de transformation qui effectue une rotation de 90 degrés dans le sens des aiguilles d'une montre, et une autre matrice de transformation qui effectue une mise à l'échelle de 2x, on peut les multiplier pour obtenir une nouvelle matrice de transformation qui effectue les deux transformations en même temps.
    // La matrice de mise à l'échelle M1 serait :
    // | 2 0 |
    // | 0 2 |
    // La matrice de rotation M2 serait :
    // | 0  -1 |
    // | 1  0 |

    // On dit qu'on fait une composition de transformations lorsqu'on applique une transformation après l'autre.

    ft::Matrix<float> scaling_matrix = {
        {2, 0},
        {0, 2}
    };
    ft::Matrix<float> rotation_matrix = {
        {0, -1},
        {1, 0}
    };
    ft::Matrix<float> result_matrix = scaling_matrix.mul_mat(rotation_matrix);
    std::cout << "Result of the composition:\n" << result_matrix << std::endl;

    // La matrice de transformation M3 serait :
    // | 0  -2 |
    // | 2  0 |

    // Si on applique cette matrice à un vecteur (1, 0), on obtient le vecteur (0, -2). Il s'agit d'une rotation de 90 degrés dans le sens des aiguilles d'une montre, suivie d'une mise à l'échelle de 2x.

    // Ce qu'il faut retemnir c'est que faire une multiplication de matrices c'est faire une composition de transformations. (une transformation après l'autre).

    return (0);
}