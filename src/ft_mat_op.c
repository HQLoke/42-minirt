/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:49:02 by weng              #+#    #+#             */
/*   Updated: 2022/05/13 00:54:22 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return the result of matrix A + B and assign the result to matrix A,
 * i.e. A = A + B */
t_mat	*ft_mat_add(t_mat *A, const t_mat *B)
{
	size_t	i;

	if (A->row != B->row || A->col != B->col)
	{
		perror("ft_mat_add: size of matrix A must equal size of matrix B");
		exit(1);
	}
	i = -1;
	while (++i < A->row * A->col)
		A->data[i / A->col][i % A->col] += B->data[i / A->col][i % A->col];
	return (A);
}

/* Return the result of matrix A - B and assign the result to matrix A,
 * i.e. A = A - B */
t_mat	*ft_mat_sub(t_mat *A, const t_mat *B)
{
	size_t	i;

	if (A->row != B->row || A->col != B->col)
	{
		perror("ft_mat_add: size of matrix A must equal size of matrix B");
		exit(1);
	}
	i = -1;
	while (++i < A->row * A->col)
		A->data[i / A->col][i % A->col] -= B->data[i / A->col][i % A->col];
	return (A);
}

/* Transpose of matrix A in-place. */
t_mat	*ft_mat_transpose(t_mat *A)
{
	t_mat	*mat;
	t_mat	copy;
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
	ft_memmove(&copy, A, sizeof(t_mat));
	ft_memmove(A, mat, sizeof(t_mat));
	ft_memmove(mat, &copy, sizeof(t_mat));
	ft_mat_del(mat);
	return (A);
}

/* Transform an affine transformation matrix to its inverse
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
	t_mat	copy;
	t_vec	*b;
	size_t	i;

	inv_a = ft_mat_copy(A);
	inv_a = ft_mat_transpose(inv_a);
	b = ft_vec_new(4, -A->data[0][3], -A->data[1][3], -A->data[2][3], 0.0);
	b = ft_mat_mul_vec(inv_a, b);
	i = -1;
	while (++i < 3)
	{
		inv_a->data[3][i] = 0;
		inv_a->data[i][3] = b->data[i];
	}
	ft_memmove(&copy, A, sizeof(t_mat));
	ft_memmove(A, inv_a, sizeof(t_mat));
	ft_memmove(inv_a, &copy, sizeof(t_mat));
	ft_mat_del(inv_a);
	ft_vec_del(b);
	return (A);
}
