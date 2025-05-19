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

    const int fov = 70;
    const float aspect_ratio = 16.0 / 9.0;
    const float near = 0.000001;
    const float far = 50.0;

    ft::Matrix<float> perspective_projection = projection(
        fov, aspect_ratio, near, far
    );

    // Save the matrix in a file called 'proj'
    save_matrix(perspective_projection, "proj");

    // You can use the file to launch the display program
    // make && ./executables/ex14 && cd matrix_display && ./display

    return (0);
}