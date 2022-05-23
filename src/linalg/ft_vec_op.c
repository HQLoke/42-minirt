/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 00:14:12 by weng              #+#    #+#             */
/*   Updated: 2022/05/13 14:15:58 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

/* Return the sum of two vectors, and assign the result to the vector a,
 * i.e. a = a + b */
t_vec	*ft_vec_add(t_vec *a, t_vec *b)
{
	size_t	n;

	if (a->size != b->size)
	{
		perror("ft_vec_add: input vectors must have the same size.");
		exit(1);
	}
	n = a->size;
	while (n-- > 0)
		a->data[n] += b->data[n];
	return (a);
}

/* Return the result of vector subtraction, and assugn the result to the
 * vector a, i.e. a = a - b */
t_vec	*ft_vec_sub(t_vec *a, t_vec *b)
{
	size_t	n;

	if (a->size != b->size)
	{
		perror("ft_vec_add: input vectors must have the same size.");
		exit(1);
	}
	n = a->size;
	while (n-- > 0)
		a->data[n] -= b->data[n];
	return (a);
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

/* Normalise an input vector in-place */
t_vec	*ft_vec_normalise(t_vec *a)
{
	double	len;

	len = ft_vec_len(a);
	if (eq_double(0, len) == 1)
	{
		perror("Cannot normalise vector of length 0.");
		exit(1);
	}
	return (ft_vec_mul_scalar(a, 1 / len));
}
