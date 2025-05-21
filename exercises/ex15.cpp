// Test des classes Matrix et Vector avec des nombres complexes
#include <iostream>
#include <complex>
#include <list>
#include "../srcs/matrix/matrix.hpp"
#include "../srcs/vector/vector.hpp"
#include "../srcs/utils.hpp"


/*
Les nombres complexes sont une extension des nombres réels qui permettent de résoudre des équations comme
x^2 + 1 = 0, qui n’ont pas de solution dans les réels.

On peut représenter les nombres complexes dans un plan, appelé plan d’Argand ou plan complexe :

    l’axe horizontal (x) représente la partie réelle
    l’axe vertical (y) représente la partie imaginaire

Ainsi, z=a+bi correspond au point (a,b) dans ce plan.


*/


void vector_complex_tests() {

    using cplx = std::complex<double>;

    // ex00 : Addition, soustraction, scaling
    ft::Vector<cplx> v1 = {cplx(1,2), cplx(3,4), cplx(5,6)};
    ft::Vector<cplx> v2 = {cplx(6,-1), cplx(2,2), cplx(0,1)};
    std::cout << "Addition complexe:\n" << v1 << " +\n" << v2 << " =\n" << (v1+v2) << std::endl;
    std::cout << "Soustraction complexe:\n" << v1 << " -\n" << v2 << " =\n" << (v1-v2) << std::endl;
    std::cout << "Scaling complexe:\n" << v1 << " * 2 =\n" << (v1 * cplx(2,0)) << std::endl;
    // Exception tailles différentes
    try {
        ft::Vector<cplx> v3 = {cplx(1,1), cplx(2,2)};
        auto v4 = v1 + v3;
    } catch (const std::exception &e) {
        std::cerr << "Erreur attendue: " << e.what() << std::endl;
    }

    // ex01 : Linear combination
    std::list<ft::Vector<cplx>> u = { {cplx(1,0),cplx(0,1)}, {cplx(0,1),cplx(1,0)} };
    std::list<cplx> scal = {cplx(2,0), cplx(0,2)};
    try {
        auto res = ft::linear_combination(u, scal);
        std::cout << "Linear combination complexe:\n" << res << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    
    // Interpolation linéaire
    ft::Vector<cplx> a = {cplx(0,0), cplx(0,10)};
    ft::Vector<cplx> b = {cplx(10,0), cplx(0,0)};
    std::cout << "Lerp complexe (0.5):\n" << lerp(a, b, 0.5) << std::endl;
    // Produit scalaire
    ft::Vector<cplx> v5 = {cplx(1,0), cplx(0,1)};
    ft::Vector<cplx> v6 = {cplx(0,1), cplx(1,0)};
    std::cout << "Dot product complexe: " << v5.dot(v6) << std::endl;
    // Normes
    std::cout << "Norme 2 complexe: " << v1.norm() << std::endl;
    std::cout << "Norme 1 complexe: " << v1.norm_1() << std::endl;
    std::cout << "Norme inf complexe: " << v1.norm_inf() << std::endl;
    // Cosine
    try {
        std::cout << "Cosine complexe: " << angle_cos(v5, v6) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erreur cosine: " << e.what() << std::endl;
    }
}

void matrix_complex_tests() {
    using cplx = std::complex<double>;
    // Addition, soustraction, scaling
    ft::Matrix<cplx> m1 = { {cplx(1,2), cplx(3,4)}, {cplx(5,6), cplx(7,8)} };
    ft::Matrix<cplx> m2 = { {cplx(2,0), cplx(0,2)}, {cplx(1,1), cplx(2,2)} };
    std::cout << "Addition matrices complexes:\n" << m1 << " +\n" << m2 << " =\n" << (m1+m2) << std::endl;
    std::cout << "Soustraction matrices complexes:\n" << m1 << " -\n" << m2 << " =\n" << (m1-m2) << std::endl;
    std::cout << "Scaling matrice complexe:\n" << m1 << " * 2 =\n" << (m1 * cplx(2,0)) << std::endl;
    // Exception tailles différentes
    try {
        ft::Matrix<cplx> m3 = { {cplx(1,1)}, {cplx(2,2)} };
        auto m4 = m1 + m3;
    } catch (const std::exception &e) {
        std::cerr << "Erreur attendue: " << e.what() << std::endl;
    }
    // Multiplication matrice/vecteur
    ft::Vector<cplx> v = {cplx(1,0), cplx(0,1)};
    std::cout << "Multiplication matrice/vecteur complexe:\n" << m1 << " *\n" << v << " =\n" << (m1 * v) << std::endl;
    // Multiplication matrice/matrice
    std::cout << "Multiplication matrice/matrice complexe:\n" << m1 << " *\n" << m2 << " =\n" << (m1 * m2) << std::endl;
    // Trace
    std::cout << "Trace matrice complexe: " << m1.trace() << std::endl;
    // Transposée
    std::cout << "Transposée matrice complexe:\n" << m1.transpose() << std::endl;
    // Forme échelonnée
    std::cout << "Forme échelonnée matrice complexe:\n" << m1.row_echelon() << std::endl;
    // Déterminant
    std::cout << "Déterminant matrice complexe: " << m1.determinant() << std::endl;
    // Inverse (si définie)
    try {
        std::cout << "Inverse matrice complexe:\n" << m1.inverse() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erreur inverse: " << e.what() << std::endl;
    }
    // Rang
    std::cout << "Rang matrice complexe: " << m1.rank() << std::endl;
}

int main() {
    std::cout << "============================" << std::endl;
    std::cout << "Vector Complex Tests" << std::endl;
    std::cout << "============================" << std::endl;
    vector_complex_tests();
    std::cout << "\n" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Matrix Complex Tests" << std::endl;
    std::cout << "============================" << std::endl;
    matrix_complex_tests();
    std::cout << "\n" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "All complex tests completed." << std::endl;
    std::cout << "============================" << std::endl;
    return 0;
}