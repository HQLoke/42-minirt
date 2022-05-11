/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:09:06 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 17:29:51 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_empty(void)
{
	t_mat	*mat;
	size_t	row;
	size_t	col;
	size_t	i;

	row = 2;
	col = 3;
	mat = ft_mat_empty(row, col);
	if (mat->row != row || mat->col != col)
		printf("ft_mat_empty: Error!\n");
	else
	{
		i = 0;
		while (i < row * col)
		{
			if (eq_double(0, mat->data[i / col][i % col]) == 0)
				printf("ft_mat_empty: Error!\n");
			++i;
		}
		printf("ft_mat_empty: OK\n");
	}
	ft_mat_del(mat);
}

void	test_new(void)
{
	const double	ptr[3] = {1, 2.3, 45.6};
	t_mat			*mat;
	size_t			row;
	size_t			col;
	size_t			i;

	row = 3;
	col = 1;
	mat = ft_mat_new(row, col, ptr);
	if (mat->row != row || mat->col != col)
		printf("ft_mat_new: Error!\n");
	else
	{
		i = 0;
		while (i < row * col)
		{
			if (eq_double(ptr[i], mat->data[i / col][i % col]) == 0)
				printf("ft_mat_new: Error!\n");
			++i;
		}
		printf("ft_mat_new: OK\n");
	}
	ft_mat_del(mat);
}

void	test_copy(void)
{
	const double	ptr[3] = {1, 2.3, 45.6};
	t_mat			*mat;
	t_mat			*cpy;
	size_t			i;

	mat = ft_mat_new(3, 1, ptr);
	cpy = ft_mat_copy(mat);
	if (cpy->row != mat->row || cpy->col != mat->col)
		printf("ft_mat_copy: Error!\n");
	else
	{
		i = -1;
		while (++i < cpy->row * cpy->col)
		{
			if (eq_double(ptr[i], cpy->data[i / cpy->col][i % cpy->col]) == 0)
				printf("ft_mat_copy: Error!\n");
		}
		printf("ft_mat_copy: OK\n");
	}
	ft_mat_del(mat);
	ft_mat_del(cpy);
}

void	test_identity(void)
{
	t_mat	*mat;
	size_t	n;
	size_t	i;

	n = 4;
	mat = ft_mat_identity(n);
	if (mat->row != n || mat->col != n)
		printf("ft_mat_identity: Error!\n");
	else
	{
		i = -1;
		while (++i < n * n)
		{
			if (!((i / n == i % n && eq_double(1, mat->data[i / n][i % n]) == 1)
				|| (i / n != i % n
					&& eq_double(0, mat->data[i / n][i % n]) == 1)))
			{
				printf("ft_mat_identity: Error!\n");
				break ;
			}
		}
		printf("ft_mat_identity: OK\n");
	}
	ft_mat_del(mat);
}

int	main(void)
{
	test_empty();
	test_new();
	test_copy();
	test_identity();
	return (0);
}
