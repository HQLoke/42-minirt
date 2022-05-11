/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_vec_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:48:22 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 10:08:34 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_add(void)
{
	t_vec	*a;
	t_vec	*b;
	t_vec	*vec;

	a = ft_vec3_new(1, 2, 3);
	b = ft_vec3_new(4, 5, 6);
	vec = ft_vec_add(a, b);
	if (vec->size != 3
		|| eq_double(5, vec->data[0]) == 0
		|| eq_double(7, vec->data[1]) == 0
		|| eq_double(9, vec->data[2]) == 0)
		printf("ft_vec_add: Error!\n");
	else
		printf("ft_vec_add: OK\n");
	ft_vec_del(a);
	ft_vec_del(b);
	ft_vec_del(vec);
}

void	test_sub(void)
{
	t_vec	*a;
	t_vec	*b;
	t_vec	*vec;

	a = ft_vec3_new(1, 2, 3);
	b = ft_vec3_new(6, 5, 4);
	vec = ft_vec_sub(a, b);
	if (vec->size != 3
		|| eq_double(-5, vec->data[0]) == 0
		|| eq_double(-3, vec->data[1]) == 0
		|| eq_double(-1, vec->data[2]) == 0)
		printf("ft_vec_sub: Error!\n");
	else
		printf("ft_vec_sub: OK\n");
	ft_vec_del(a);
	ft_vec_del(b);
	ft_vec_del(vec);
}

void	test_len(void)
{
	t_vec	*a;
	double	val;

	a = ft_vec3_new(3, 4, 12);
	val = ft_vec_len(a);
	if (eq_double(13, val) == 0)
		printf("ft_vec_len: Error!\n");
	else
		printf("ft_vec_len: OK\n");
	ft_vec_del(a);
}

void	test_angle(void)
{
	t_vec	*a;
	t_vec	*b;
	double	val;

	a = ft_vec3_new(1, 0, 0);
	b = ft_vec3_new(1, 1, 0);
	val = ft_vec_angle(a, b);
	if (eq_double(M_PI / 4, val) == 0)
		printf("ft_vec_angle: Error!\n");
	else
		printf("ft_vec_angle: OK\n");
	ft_vec_del(a);
	ft_vec_del(b);
}

int	main(void)
{
	test_add();
	test_sub();
	test_len();
	test_angle();
	return (0);
}
