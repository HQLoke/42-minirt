/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:26:26 by weng              #+#    #+#             */
/*   Updated: 2022/05/10 23:24:18 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Calculates the multiplication of a vector and a scalar. */
t_vec	*ft_vec_mul_scalar(t_vec *a, double f)
{
	size_t	n;
	t_vec	*vec;

	n = a->size;
	vec = ft_vec_new(n);
	while (n-- > 0)
		vec->data[n] = a->data[n] * f;
	return (vec);
}

/* Calculates the element-wise product of a two vectors. */
t_vec	*ft_vec_mul_elem(t_vec *a, t_vec *b)
{
	size_t	n;
	t_vec	*vec;

	if (a->size != b->size)
	{
		perror("ft_vec_mul_elem: input vectors must have the same size.");
		exit(1);
	}
	n = a->size;
	vec = ft_vec_new(n);
	while (n-- > 0)
		vec->data[n] = a->data[n] * b->data[n];
	return (vec);
}

/* Calculates the dot product of 2 vectors */
double	ft_vec_mul_dot(t_vec *a, t_vec *b)
{
	size_t	i;
	double	retval;

	if (a->size != b->size)
	{
		perror("ft_vec_mul_dot: input vectors must have the same size.");
		exit(1);
	}
	retval = 0;
	i = 0;
	while (i < a->size)
	{
		retval += (a->data[i] * b->data[i]);
		i++;
	}
	return (retval);
}

/* Calculates the cross product of a two size 3 vectors. */
t_vec	*ft_vec_mul_cross(t_vec *a, t_vec *b)
{
	double	*v_a;
	double	*v_b;

	if (a->size != 3 || b->size != 3)
	{
		perror("ft_vec_mul_cross: input vectors must be of size 3.");
		exit(1);
	}
	v_a = a->data;
	v_b = b->data;
	return (ft_vec3_new(
			v_a[1] * v_b[2] - v_a[2] * v_b[1],
			v_a[2] * v_b[0] - v_a[0] * v_b[2],
			v_a[0] * v_b[1] - v_a[1] * v_b[0]));
}

/* Calculates the triple product of three size 3 vectors. */
double	ft_vec_mul_triple(t_vec *a, t_vec *b, t_vec *c)
{
	t_vec	*temp;
	double	retval;

	if (a->size != 3 || b->size != 3 || c->size != 3)
	{
		perror("ft_vec_mul_triple: input vectors must be of size 3.");
		exit(1);
	}
	temp = ft_vec_mul_cross(b, c);
	retval = ft_vec_mul_dot(a, temp);
	ft_vec_del(temp);
	return (retval);
}
