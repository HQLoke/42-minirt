/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:26:01 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 10:23:02 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return a vector of size n. This function should preferably not be
 * called by the user, as it is unsafe (i.e. integer used as input).
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
t_vec	*ft_vec_copy(t_vec	*vec)
{
	t_vec	*retval;
	size_t	n;

	if (vec == NULL)
		return (NULL);
	n = vec->size;
	retval = ft_vec_new(n);
	while (n-- > 0)
		retval->data[n] = vec->data[n];
	return (retval);
}

/* Return a vector of size 3 */
t_vec	*ft_vec3_new(double x, double y, double z)
{
	return (ft_vec_new(3, x, y, z));
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
