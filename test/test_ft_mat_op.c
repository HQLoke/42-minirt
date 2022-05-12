/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_mat_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:59:52 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 13:51:57 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_add(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	const double	ptr2[] = {2, 4, 6, 8};
	t_mat			*in;
	t_mat			*out;
	t_mat			*target;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_add(in, in);
	target = ft_mat_new(2, 2, ptr2);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_add: Error!\n");
	else
		printf("ft_mat_add: OK\n");
	ft_mat_del(in);
	ft_mat_del(out);
	ft_mat_del(target);
}

void	test_sub(void)
{
	const double	ptr[] = {1, 2, 3, 4};
	t_mat			*in;
	t_mat			*out;
	t_mat			*target;

	in = ft_mat_new(2, 2, ptr);
	out = ft_mat_sub(in, in);
	target = ft_mat_empty(2, 2);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_sub: Error!\n");
	else
		printf("ft_mat_sub: OK\n");
	ft_mat_del(in);
	ft_mat_del(out);
	ft_mat_del(target);
}

void	test_transpose(void)
{
	const double	ptr[] = {1, 2, 3, 4, 5, 6};
	const double	ptr2[] = {1, 4, 2, 5, 3, 6};
	t_mat			*in;
	t_mat			*out;
	t_mat			*target;

	in = ft_mat_new(2, 3, ptr);
	out = ft_mat_transpose(in);
	target = ft_mat_new(3, 2, ptr2);
	if (eq_mat(out, target) == 0)
		printf("ft_mat_transpose: Error!\n");
	else
		printf("ft_mat_transpose: OK\n");
	ft_mat_del(in);
	ft_mat_del(out);
	ft_mat_del(target);
}

void	test_affine_inverse(void)
{
	t_mat	*x = ft_affine_rotate_x(0.1);
	t_mat	*y = ft_affine_rotate_y(0.2);
	t_mat	*t = ft_affine_translate(1, 2, 3);
	t_mat	*transform1 = ft_mat_mul(x, y);
	t_mat	*transform2 = ft_mat_mul(transform1, t);
	t_mat	*inv = ft_mat_affine_inverse(transform2);
	t_mat	*out = ft_mat_mul(transform2, inv);
	t_mat	*target = ft_mat_identity(4);

	if (eq_mat(out, target) == 0)
		printf("ft_mat_affine_inverse: Error!\n");
	else
		printf("ft_mat_affine_inverse: OK\n");
	ft_mat_del(x);
	ft_mat_del(y);
	ft_mat_del(t);
	ft_mat_del(transform1);
	ft_mat_del(transform2);
	ft_mat_del(inv);
	ft_mat_del(out);
	ft_mat_del(target);
}

int	main(void)
{
	test_add();
	test_sub();
	test_transpose();
	test_affine_inverse();
	return (0);
}
