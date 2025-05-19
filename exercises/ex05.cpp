/*
Exercise 5 : Cosine
*/


#include <iostream>
#include "vector.hpp"
#include "utils.hpp"

int main()
{

    // In the previous exercises, we saw the dot product of two vectors and the norm.
    // The dot product is a measure of how similar the directions of the two vectors are.
    // Another way to mesure the dot product is to use the cosine of the angle between the two vectors.

    // dot product = ||u|| * ||v|| * cos(theta)
    // where ||u|| and ||v|| are the norms of the vectors u and v, and theta is the angle between the two vectors.

    // To find the angle theta based on the dot product, we can rearrange the equation:
    // cos(theta) = dot product / (||u|| * ||v||)

    ft::Vector<float> v1 = {0, -1};  // length 1 pointing to the right
    ft::Vector<float> v2 = {0, 1};  // length 1 pointing upwards

    try {
        double cosine = angle_cos(v1, v2);
        std::cout << "Cosine of the angle between v1 and v2: " << cosine << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // The cosine of the angle between two vectors is a measure of how similar the directions of the two vectors are.
    // If the cosine is 1, the vectors are pointing in the same direction and are perfectly aligned.
    // If the cosine is -1, the vectors are pointing in opposite directions and are perfectly aligned.
    // If the cosine is 0, the vectors are perpendicular to each other.
    // If the cosine is between 0 and 1, the vectors are pointing in the same general direction, but not exactly the same.

    return (0);
}