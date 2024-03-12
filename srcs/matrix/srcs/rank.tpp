template <typename T>
ft::Matrix<T>::size_type ft::Matrix<T>::rank() const
{
    Matrix<T> row_echelon_form = row_echelon();

    size_type rank_value = 0;

    for (size_type i = 0; i < row_echelon_form.size(); i++)
    {
        bool full_zero = true;

        for (size_type j = 0; j < row_echelon_form[i].size(); j++)
        {
            if (row_echelon_form[i][j] != 0)
            {
                full_zero = false;
                break;
            }
        }
        if (full_zero == true)
            ++rank_value;
    }
    return rank_value;
}
