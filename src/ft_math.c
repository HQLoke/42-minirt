/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:12 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 13:55:27 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Returns true if two doubles are nearly equal in value, false otherwise. */
int	eq_double(double a, double b)
{
	return (fabs(a - b) <= (DBL_EPSILON * fabs(a + b)));
}

/* Returns true of two matrices are equal, false otherwise. */
int	eq_mat(t_mat *A, t_mat *B)
{
	size_t	i;
	size_t	j;

	if (A->row != B->row || A->col != B->col)
		return (0);
	i = -1;
	while (++i < A->row)
	{
		j = -1;
		while (++j < A->col)
		{
			if (eq_double(A->data[i][j], B->data[i][j]) == 0)
				continue ;
		}
	}
	return (1);
}
