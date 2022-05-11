/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:14:12 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 09:51:06 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return the result of vectors a + b */
t_vec	*ft_vec_add(t_vec *a, t_vec *b)
{
	size_t	n;
	t_vec	*vec;

	if (a->size != b->size)
	{
		perror("ft_vec_add: input vectors must have the same size.");
		exit(1);
	}
	n = a->size;
	vec = ft_vec_new(n);
	while (n-- > 0)
		vec->data[n] = a->data[n] + b->data[n];
	return (vec);
}

/* Return the result of vectors a - b */
t_vec	*ft_vec_sub(t_vec *a, t_vec *b)
{
	size_t	n;
	t_vec	*vec;

	if (a->size != b->size)
	{
		perror("ft_vec_add: input vectors must have the same size.");
		exit(1);
	}
	n = a->size;
	vec = ft_vec_new(n);
	while (n-- > 0)
		vec->data[n] = a->data[n] - b->data[n];
	return (vec);
}

/* Return the length of a vector */
double	ft_vec_len(t_vec *a)
{
	return (sqrt(ft_vec_mul_dot(a, a)));
}

/* Return the angle between two vectors an radians */
double	ft_vec_angle(t_vec *a, t_vec *b)
{
	return (acos(ft_vec_mul_dot(a, b) / ft_vec_len(a) / ft_vec_len(b)));
}
