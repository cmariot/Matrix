/*
Exercise 14 : Projection
*/

#include "matrix.hpp"
#include <fstream>
#include <string>
#include <unistd.h>


void save_matrix(const ft::Matrix<float> &matrix, const std::string &filename)
{
    std::ofstream file("matrix_display/proj", std::ios::trunc);
    if (file.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j < 3)
                    file << matrix[i][j] << ", ";
                else
                    file << matrix[i][j] << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}


int main(void)
{

    // Dans les moteurs de rendu, une matrice de projection permet de transformer des coordonnées 3D en coordonnées d’écran 2D.
    //     Projection en perspective :
    //         Utilisée pour les rendus réalistes.
    //         Les objets lointains paraissent plus petits.

    // Exemple de matrice de projection en perspective (OpenGL simplifié) :
    // projection_matrix = {
    //  { 1/(aspect_ratio*tan(fov/2)), 0, 0, 0 },
    //  { 0, 1/tan(fov/2), 0, 0 },
    //  { 0, 0, -(far+near)/(far-near), -2*far*near/(far-near) },
    //  { 0, 0, -1, 0 }
    // }

    const int fov = 80;
    const float aspect_ratio = 16.0 / 16.0;
    const float near = 0.01;
    const float far = 15.0;

    ft::Matrix<float> perspective_projection = projection(
        fov, aspect_ratio, near, far
    );

    // Save the matrix in a file called 'proj'
    save_matrix(perspective_projection, "proj");

    // You can use the file to launch the display program
    // make && ./executables/ex14 && cd matrix_display && ./display

    return (0);
}