/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:26:01 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 11:01:55 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

/* Return a vector of size n.
 *
 * This function should preferably not be called by the user, as it is
 * unsafe (i.e. integer used as input). User should instead call
 * ft_vec2_new, ft_vec3_new or ft_vec4_new instead.
 */
t_vec	*ft_vec_new(size_t n, ...)
{
	t_vec	*vec;
	size_t	i;
	va_list	arg;

	vec = malloc(sizeof(t_vec));
	if (vec == NULL)
		return (NULL);
	vec->size = n;
	vec->data = malloc(sizeof(double) * n);
	if (vec->data == NULL)
	{
		ft_vec_del(vec);
		return (NULL);
	}
	va_start(arg, n);
	i = 0;
	while (i < n)
		vec->data[i++] = va_arg(arg, double);
	va_end(arg);
	return (vec);
}

/* Make a copy of a vector. */
t_vec	*ft_vec_copy(t_vec *vec)
{
	t_vec	*retval;
	size_t	n;

	if (vec == NULL)
		return (NULL);
	n = vec->size;
	retval = ft_vec_new(n);
	ft_memmove(retval->data, vec->data, sizeof(vec->data[0]) * n);
	return (retval);
}

/* Delete a vector from memory. */
void	ft_vec_del(t_vec *vec)
{
	if (vec != NULL)
		free(vec->data);
	free(vec);
}

/* Deletes n vectors from memory. */
void	ft_vec_del_many(size_t n, ...)
{
	va_list	arg;
	t_vec	*vec;

	va_start(arg, n);
	while (n-- > 0)
	{
		vec = va_arg(arg, t_vec *);
		ft_vec_del(vec);
	}
	va_end(arg);
}

/* Swap the content of two vectors */
void	ft_vec_swap(t_vec *a, t_vec *b)
{
	t_vec	temp;

	ft_memmove(&temp, a, sizeof(t_vec));
	ft_memmove(a, b, sizeof(t_vec));
	ft_memmove(b, &temp, sizeof(t_vec));
}
