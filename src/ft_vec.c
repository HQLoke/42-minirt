/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:26:01 by weng              #+#    #+#             */
/*   Updated: 2022/05/10 17:02:35 by weng             ###   ########.fr       */
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
