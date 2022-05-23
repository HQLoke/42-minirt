/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:20:19 by weng              #+#    #+#             */
/*   Updated: 2022/05/13 14:15:58 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

/* Returns the multiplication of scalar value and a matrix, and assign
 * the result to the matrix A, i.e. A = sA */
t_mat	*ft_mat_mul_scalar(double s, t_mat *A)
{
	size_t	i;

	i = -1;
	while (++i < A->row * A->col)
		A->data[i / A->col][i % A->col] *= s;
	return (A);
}

/* Calculates the element-wise product of a two matrices, and assign the
 * result to the matrix A, i.e. A = A ∘ B. */
t_mat	*ft_mat_mul_elem(t_mat *A, const t_mat *B)
{
	size_t	row;
	size_t	col;
	size_t	i;

	row = A->row;
	col = A->col;
	if (row != B->row || col != B->col)
	{
		perror("ft_mat_mul_elem: input matrices must have the same size.");
		exit(1);
	}
	i = -1;
	while (++i < row * col)
		A->data[i / col][i % col] *= B->data[i / col][i % col];
	return (A);
}

/* Returns the product of a matrix and a vector, and assign the result
 * to the vector b, i.e. b = A ⨯ b */
t_vec	*ft_mat_mul_vec(const t_mat *A, t_vec *b)
{
	t_vec	*vec;
	size_t	i;
	size_t	j;
	double	val;

	if (A->col != b->size)
	{
		perror("ft_mat_mul_vec: A->col != b->size");
		exit(1);
	}
	vec = ft_vec_new(A->row);
	i = -1;
	while (++i < A->row)
	{
		val = 0;
		j = -1;
		while (++j < A->col)
			val += A->data[i][j] * b->data[j];
		vec->data[i] = val;
	}
	ft_memmove(b->data, vec->data, sizeof(b->data[0]) * b->size);
	ft_vec_del(vec);
	return (b);
}

/* Returns the product of two matrices, and assign the result to matrix
 * A, i.e. A = A x B */
t_mat	*ft_mat_mul(t_mat *A, const t_mat *B)
{
	t_mat	*mat;
	t_mat	copy;
	size_t	i;
	size_t	j;

	if (A->col != B->row)
	{
		perror("ft_mat_mul: column of matrix A must equal to row of matrix B");
		exit(1);
	}
	mat = ft_mat_empty(A->row, B->col);
	i = -1;
	while (++i < A->row * B->col)
	{
		j = -1;
		while (++j < A->col)
			mat->data[i / mat->col][i % mat->col]
				+= A->data[i / mat->col][j] * B->data[j][i % mat->col];
	}
	ft_memmove(&copy, A, sizeof(t_mat));
	ft_memmove(A, mat, sizeof(t_mat));
	ft_memmove(mat, &copy, sizeof(t_mat));
	ft_mat_del(mat);
	return (A);
}
