/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:14 by cmariot           #+#    #+#             */
/*   Updated: 2024/03/12 11:42:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename ft::Matrix<T>::size_type ft::Matrix<T>::rank() const
{
    Matrix<T> row_echelon_form = row_echelon();

    size_type rank_value = 0;

    for (size_type i = 0; i < row_echelon_form.size()[0]; i++)
    {
        bool full_zero = true;

        for (size_type j = 0; j < row_echelon_form.size()[1]; j++)
        {
            if (row_echelon_form[i][j] != 0)
            {
                full_zero = false;
                break;
            }
        }
        if (full_zero == false)
            ++rank_value;
    }

    return rank_value;
}
