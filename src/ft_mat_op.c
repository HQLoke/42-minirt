/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:49:02 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 22:17:09 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return the result of matrix A + B */
t_mat	*ft_mat_add(t_mat *A, t_mat *B)
{
	size_t	i;
	t_mat	*mat;

	if (A->row != B->row || A->col != B->col)
	{
		perror("ft_mat_add: size of matrix A must equal size of matrix B");
		exit(1);
	}
	mat = ft_mat_empty(A->row, A->col);
	i = -1;
	while (++i < A->row * A->col)
	{
		mat->data[i / A->col][i % A->col]
			= A->data[i / A->col][i % A->col] + B->data[i / A->col][i % A->col];
	}
	return (mat);
}

/* Return the result of matrix A - B */
t_mat	*ft_mat_sub(t_mat *A, t_mat *B)
{
	size_t	i;
	t_mat	*mat;

	if (A->row != B->row || A->col != B->col)
	{
		perror("ft_mat_add: size of matrix A must equal size of matrix B");
		exit(1);
	}
	mat = ft_mat_empty(A->row, A->col);
	i = -1;
	while (++i < A->row * A->col)
	{
		mat->data[i / A->col][i % A->col]
			= A->data[i / A->col][i % A->col] - B->data[i / A->col][i % A->col];
	}
	return (mat);
}

/* Return the transpose of matrix A */
t_mat	*ft_mat_transpose(t_mat *A)
{
	t_mat	*mat;
	size_t	i;
	size_t	row;
	size_t	col;

	mat = ft_mat_empty(A->col, A->row);
	i = -1;
	while (++i < A->row * A->col)
	{
		row = i / A->col;
		col = i % A->col;
		mat->data[col][row] = A->data[row][col];
	}
	return (mat);
}

/* Return the inverse of an affine transformation matrix.
 *
 * Since rotation matrices are orthogonal, A is in the form
 * A = [ M  b ]
 *     [ 0  1 ]
 * where M is an orthogonal matrix, and M^-1 = M^T.
 * 
 * inv(A) = [ inv(M)  -inv(M) * b ]
 *          [   0          1      ]
 */
t_mat	*ft_mat_affine_inverse(t_mat *A)
{
	t_mat	*inv_a;
	t_vec	*b;
	t_vec	*vec;
	size_t	i;

	inv_a = ft_mat_transpose(A);
	b = ft_vec_new(4, -A->data[0][3], -A->data[1][3], -A->data[2][3], 0.0);
	vec = ft_mat_mul_vec(inv_a, b);
	i = -1;
	while (++i < 3)
	{
		inv_a->data[3][i] = 0;
		inv_a->data[i][3] = vec->data[i];
	}
	ft_vec_del(b);
	ft_vec_del(vec);
	return (inv_a);
}
