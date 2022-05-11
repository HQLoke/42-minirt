/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:20:19 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 23:10:47 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Returns the multiplication of scalar value and a matrix. */
t_mat	*ft_mat_mul_scalar(const double s, const t_mat *A)
{
	t_mat	*mat;
	size_t	i;

	mat = ft_mat_copy(A);
	if (mat == NULL)
		return (NULL);
	i = -1;
	while (++i < A->row * A->col)
		mat->data[i / A->col][i % A->col] *= s;
	return (mat);
}

/* Calculates the element-wise product of a two matrices. */
t_mat	*ft_mat_mul_elem(const t_mat *A, const t_mat *B)
{
	t_mat	*mat;
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
	mat = ft_mat_empty(row, col);
	i = -1;
	while (++i < row * col)
	{
		mat->data[i / col][i % col]
			= A->data[i / col][i % col] * B->data[i / col][i % col];
	}
	return (mat);
}

/* Returns the product of a matrix and a vector */
t_vec	*ft_mat_mul_vec(const t_mat *A, const t_vec *b)
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
	return (vec);
}

/* Returns the product of two matrices, i.e. A x B */
t_mat	*ft_mat_mul(const t_mat *A, const t_mat *B)
{
	t_mat	*mat;
	size_t	i;
	size_t	j;
	double	val;

	if (A->col != B->row)
	{
		perror("ft_mat_mul: column of matrix A must equal to row of matrix B");
		exit(1);
	}
	mat = ft_mat_empty(A->row, B->col);
	i = -1;
	while (++i < A->row * B->col)
	{
		val = 0;
		j = -1;
		while (++j < A->col)
			val += A->data[i / mat->col][j] * B->data[j][i % mat->col];
		mat->data[i / mat->col][i % mat->col] = val;
	}
	return (mat);
}
