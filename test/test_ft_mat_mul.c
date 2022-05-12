/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_mat_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:03:44 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 16:34:14 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_scalar(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {2, 4, 6, 8};
	t_mat			*in;
	t_mat			*out;
	t_mat			*target;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_mul_scalar(2, in);
	target = ft_mat_new(2, 2, ptr2);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_mul_scalar: Error!\n");
	else
		printf("ft_mat_mul_scalar: OK\n");
	ft_mat_del(in);
	ft_mat_del(out);
	ft_mat_del(target);
}

void	test_elem(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {1, 4, 9, 16};
	t_mat			*in;
	t_mat			*out;
	t_mat			*target;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_mul_elem(in, in);
	target = ft_mat_new(2, 2, ptr2);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_mul_elem: Error!\n");
	else
		printf("ft_mat_mul_elem: OK\n");
	ft_mat_del(in);
	ft_mat_del(out);
	ft_mat_del(target);
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
	const double	ptr[] = {1, 2, 3, 4, 5, 6};
	const double	ptr2[] = {7, 8, 9, 10, 11, 12};
	const double	ptr3[] = {27, 30, 33, 61, 68, 75, 95, 106, 117};
	t_mat			*a;
	t_mat			*b;
	t_mat			*out;
	t_mat			*target;

	a = ft_mat_new(3, 2, ptr);
	b = ft_mat_new(2, 3, ptr2);
	out = ft_mat_mul(a, b);
	target = ft_mat_new(3, 3, ptr3);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_mul: Error!\n");
	else
		printf("ft_mat_mul: OK\n");
	ft_mat_del(a);
	ft_mat_del(b);
	ft_mat_del(out);
	ft_mat_del(target);
}

int	main(void)
{
	test_scalar();
	test_elem();
	test_vector();
	test_mul();
	return (0);
}
