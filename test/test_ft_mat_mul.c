/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_mat_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:03:44 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 23:56:45 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_scalar(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {2, 4, 6, 8};
	t_mat			*mat;
	t_mat			*target;

	mat = ft_mat_new(2, 2, ptr);
	mat = ft_mat_mul_scalar(2, mat);
	target = ft_mat_new(2, 2, ptr2);
	if (eq_mat(mat, target) == 0)
		printf("ft_mat_mul_scalar: Error!\n");
	else
		printf("ft_mat_mul_scalar: OK\n");
	ft_mat_del(mat);
	ft_mat_del(target);
}

void	test_elem(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {1, 4, 9, 16};
	t_mat			*mat;
	t_mat			*target;

	mat = ft_mat_new(2, 2, ptr);
	mat = ft_mat_mul_elem(mat, mat);
	target = ft_mat_new(2, 2, ptr2);
	if (eq_mat(mat, target) == 0)
		printf("ft_mat_mul_elem: Error!\n");
	else
		printf("ft_mat_mul_elem: OK\n");
	ft_mat_del(mat);
	ft_mat_del(target);
}

void	test_vector(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	t_mat			*mat;
	t_vec			*vec;
	t_vec			*target;

	mat = ft_mat_new(2, 2, ptr);
	vec = ft_vec_new(2, 5.0, 6.0);
	vec = ft_mat_mul_vec(mat, vec);
	target = ft_vec_new(2, 17.0, 39.0);
	if (eq_vec(vec, target) == 0)
		printf("ft_mat_mul_vec: Error!\n");
	else
		printf("ft_mat_mul_vec: OK\n");
	ft_mat_del(mat);
	ft_vec_del(vec);
	ft_vec_del(target);
}

void	test_mul(void)
{
	const double	ptr[] = {1, 2, 3, 4, 5, 6};
	const double	ptr2[] = {7, 8, 9, 10, 11, 12};
	const double	ptr3[] = {27, 30, 33, 61, 68, 75, 95, 106, 117};
	t_mat			*a;
	t_mat			*b;
	t_mat			*target;

	a = ft_mat_new(3, 2, ptr);
	b = ft_mat_new(2, 3, ptr2);
	a = ft_mat_mul(a, b);
	target = ft_mat_new(3, 3, ptr3);
	if (eq_mat(a, target) == 0)
		printf("ft_mat_mul: Error!\n");
	else
		printf("ft_mat_mul: OK\n");
	ft_mat_del(a);
	ft_mat_del(b);
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
