/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_mat_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:03:44 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 23:36:59 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_scalar(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	size_t			i;
	t_mat			*in;
	t_mat			*out;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_mul_scalar(2, in);
	if (out->row != in->row || out->col != in->col)
		printf("ft_mat_mul_scalar: Error!\n");
	else
	{
		i = -1;
		while (++i < out->row * out->col)
		{
			if (!eq_double(ptr[i] * 2, out->data[i / out->col][i % out->col]))
			{
				printf("ft_mat_mul_scalar: Error!\n");
				break ;
			}
		}
		printf("ft_mat_mul_scalar: OK\n");
	}
	ft_mat_del(in);
	ft_mat_del(out);
}

void	test_elem(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	size_t			i;
	t_mat			*in;
	t_mat			*out;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_mul_elem(in, in);
	if (out->row != in->row || out->col != in->col)
		printf("ft_mat_mul_elem: Error!\n");
	else
	{
		i = -1;
		while (++i < out->row * out->col)
		{
			if (!eq_double(
					ptr[i] * ptr[i], out->data[i / out->col][i % out->col]))
			{
				printf("ft_mat_mul_elem: Error!\n");
				break ;
			}
		}
		printf("ft_mat_mul_elem: OK\n");
	}
	ft_mat_del(in);
	ft_mat_del(out);
}

void	test_vector(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	t_mat			*mat;
	t_vec			*in;
	t_vec			*out;

	mat = ft_mat_new(2, 2, ptr);
	in = ft_vec_new(2, 5.0, 6.0);
	out = ft_mat_mul_vec(mat, in);
	if (out->size != mat->row
		|| eq_double(17, out->data[0]) == 0
		|| eq_double(39, out->data[1]) == 0)
		printf("ft_mat_mul_vec: Error!\n");
	else
		printf("ft_mat_mul_vec: OK\n");
	ft_mat_del(mat);
	ft_vec_del(in);
	ft_vec_del(out);
}

void	test_mul(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {1, 2, 3, 4, 5, 6};
	t_mat			*a;
	t_mat			*b;
	t_mat			*out;

	a = ft_mat_new(2, 2, ptr);
	b = ft_mat_new(2, 3, ptr2);
	out = ft_mat_mul(a, b);
	if (out->row != a->row || out->col != b->col
		|| eq_double(9, out->data[0][0]) == 0
		|| eq_double(12, out->data[0][1]) == 0
		|| eq_double(15, out->data[0][2]) == 0
		|| eq_double(19, out->data[1][0]) == 0
		|| eq_double(26, out->data[1][1]) == 0
		|| eq_double(33, out->data[1][2]) == 0)
		printf("ft_mat_mul: Error!\n");
	else
		printf("ft_mat_mul: OK\n");
	ft_mat_del(a);
	ft_mat_del(b);
	ft_mat_del(out);
}

int	main(void)
{
	test_scalar();
	test_elem();
	test_vector();
	test_mul();
	return (0);
}
