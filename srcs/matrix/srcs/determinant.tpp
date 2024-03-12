template <typename T>
T ft::Matrix<T>::determinant() const
{
    if (!is_square())
        throw std::exception(
            "The determinant of a matrix must be on a square one."
        );

    
    return (T());
}
