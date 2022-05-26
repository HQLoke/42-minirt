/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:32:53 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 11:05:36 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

void	test_new(void)
{
	t_vec	*vec;

	vec = ft_vec3_new(1, 2.3, 45.6);
	if (vec->size != 3
		|| eq_double(1, vec->data[0]) == 0
		|| eq_double(2.3, vec->data[1]) == 0
		|| eq_double(45.6, vec->data[2]) == 0)
		printf("ft_vec3_new: Error!\n");
	else
		printf("ft_vec3_new: OK\n");
	ft_vec_del(vec);
}

void	test_copy(void)
{
	t_vec	*vec;
	t_vec	*copy;

	vec = ft_vec3_new(1, 2.3, 45.6);
	copy = ft_vec_copy(vec);
	if (eq_vec(vec, copy) == 0)
		printf("ft_vec_copy: Error!\n");
	else
		printf("ft_vec_copy: OK\n");
	ft_vec_del(vec);
	ft_vec_del(copy);
}

void	test_del_many(void)
{
	t_vec	*a;
	t_vec	*b;

	a = ft_vec3_new(1, 2, 3);
	b = ft_vec3_new(4, 5, 6);
	ft_vec_del_many(2, a, b);
	printf("ft_vec_del_many:\n");
}

void	test_swap(void)
{
	t_vec	*a;
	t_vec	*a_copy;
	t_vec	*b;
	t_vec	*b_copy;

	a = ft_vec4_new(1, 2, 3, 4);
	a_copy = ft_vec_copy(a);
	b = ft_vec4_new(5, 6, 7, 8);
	b_copy = ft_vec_copy(b);
	ft_vec_swap(a, b);
	if (eq_vec(a, b_copy) == 0 || eq_vec(b, a_copy) == 0)
		printf("ft_vec_swap: Error!\n");
	else
		printf("ft_vec_swap: OK\n");
	ft_vec_del(a);
	ft_vec_del(a_copy);
	ft_vec_del(b);
	ft_vec_del(b_copy);
}

int	main(void)
{
	test_new();
	test_copy();
	test_del_many();
	test_swap();
	return (0);
}
