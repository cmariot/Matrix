
// is_square
template <typename T>
bool ft::Matrix<T>::is_square() const
{
    return (_matrix.size() == _matrix[0].size());
}
