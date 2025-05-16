/*
Exercise 11 : Determinant
*/

# include <iostream>
# include "matrix.hpp"

int main()
{

    // One thing that turns out to be surprisingly useful for understanding a given transformation is to measure exactly how much a given transformation stretches and squishes things. More specifically, to measure the factor by which the area of a given region increases or decreases.

    // This special scaling factor, the factor by which a linear transformation changes areas, is called the “determinant” of that transformation.

    // For example, if we take a square of area 1 and apply a transformation to it that stretches it into a rectangle of area 4, then we can say that the transformation has a determinant of 4. If we take the same square and squish it down into a line of area 0, then the determinant is 0.

    ft::Matrix<double> m1 = {
        {2, 0},
        {0, 2}
    };

    std::cout << "Positive determinant : " << m1.determinant() << std::endl;


    // The determinant of a 2D transformation is 0 if it squishes all of space onto a line, or even onto a single point, since the area of every region would then become 0.
    // https://www.3blue1brown.com/content/lessons/2016/determinant/determinant_0.svg

    ft::Matrix<double> m2 = {
        {1, 2},
        {2, 4}
    };

    std::cout << "Zero determinant: " << m2.determinant() << std::endl;


    // For negative determinants, the transformation flips the orientation of the space. For example, if we take a square and apply a transformation that flips it over, then the determinant will be negative.
    // https://www.3blue1brown.com/lessons/determinant#negative-determinant

    ft::Matrix<double> m3 = {
        {-1, 0},
        {0, 1}
    };

    std::cout << "Negative determinant: " << m3.determinant() << std::endl;

    return (0);
}