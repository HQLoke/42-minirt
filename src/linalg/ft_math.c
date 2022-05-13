/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:12 by weng              #+#    #+#             */
/*   Updated: 2022/05/13 14:15:58 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

/* Returns true if two doubles are nearly equal in value, false otherwise. */
int	eq_double(double a, double b)
{
	double	lhs;

	lhs = fabs(a - b);
	return (lhs <= (DBL_EPSILON * fabs(a + b)) || lhs <= DBL_EPSILON);
}

/* Returns true if two matrices are equal, false otherwise. */
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
				return (0);
		}
	}
	return (1);
}

/* Returns true if two vectors are equal, false otherwise. */
int	eq_vec(t_vec *a, t_vec *b)
{
	size_t	i;

	if (a->size != b->size)
		return (0);
	i = -1;
	while (++i < a->size)
	{
		if (eq_double(a->data[i], b->data[i]) == 0)
			return (0);
	}
	return (1);
}
