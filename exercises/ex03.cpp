/*
Exercise 3: Dot Product
*/

#include <iostream>
#include "vector.hpp"


int main()
{

    /*
    Le produit scalaire (ou dot product) mesure à quel point deux vecteurs "pointent dans la même direction".
    Il peut être calculé en multipliant les composantes correspondantes des deux vecteurs et en additionnant les résultats.
    Par exemple, le produit scalaire de a et b est 1 * 0 + 0 * 1 = 0.
    - Si le produit scalaire est égal à 0, cela signifie que les deux vecteurs sont orthogonaux (perpendiculaires).
    - Si le produit scalaire est positif, cela signifie que les deux vecteurs pointent dans la même direction.
    - Si le produit scalaire est négatif, cela signifie que les deux vecteurs pointent dans des directions opposées.
    */

    // Vectors orthogonal to each other
    ft::Vector<double> a = {1, 0}; // length 1 pointing to the right
    ft::Vector<double> b = {0, 1}; // length 1 pointing upwards
    float result = a.dot(b);
    std::cout << "Dot product of orthogonal vectors: " << result << std::endl;

    // Vectors in opposite directions
    ft::Vector<double> c = {-1, 0}; // length 1 pointing to the left
    ft::Vector<double> d = {1, 0}; // length 1 pointing to the right
    float result1 = c.dot(d);
    std::cout << "Dot product of opposite vectors: " << result1 << std::endl;

    // Vectors in the same direction
    ft::Vector<double> e = {1, 0}; // length 1 pointing to the right
    ft::Vector<double> f = {2, 0}; // same
    float result3 = e.dot(f);
    std::cout << "Dot product of same direction vectors: " << result3 << std::endl;

    // Dot product with a vector of different size (must throw an exception)
    try {
        ft::Vector<double> c = {1, 2, 3};
        float result2 = a.dot(c);
        std::cout << "Dot product result: " << result2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}