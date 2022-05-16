/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:27 by weng              #+#    #+#             */
/*   Updated: 2022/05/16 22:13:40 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Create a new ray with a given 'origin' and 'direction'. The direction
 * vector is normalised. */
t_ray	*ft_ray_new(t_vec *origin, t_vec *direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (ray != NULL)
	{
		ray->origin = origin;
		ray->direction = ft_vec_normalise(direction);
	}
	return (ray);
}

/* Delete a given ray. */
void	ft_ray_del(t_ray *ray)
{
	if (ray == NULL)
		return ;
	ft_vec_del(ray->origin);
	ft_vec_del(ray->direction);
	free(ray);
}

/* Returns a copy of a ray from memory. */
t_ray	*ft_ray_copy(t_ray *ray)
{
	t_ray	*copy;

	copy = ft_ray_new(ft_vec_copy(ray->origin), ft_vec_copy(ray->direction));
	return (copy);
}

/* Transform a ray in place, given a transformation matrix */
t_ray	*ft_ray_transform(t_mat *A, t_ray *ray)
{
	ray->origin = ft_mat_mul_vec(A, ray->origin);
	ray->direction = ft_mat_mul_vec(A, ray->direction);
	return (ray);
}

/* Calculates the coordinate of point along a ray, and assign the result
 * to the vector pointed by 'point'. */
t_vec	*ft_ray_calc_point(t_ray *ray, double t, t_vec *point)
{
	t_vec	*vec;

	vec = ft_vec_copy(ray->direction);
	vec = ft_vec_mul_scalar(vec, t);
	vec = ft_vec_add(vec, ray->origin);
	ft_memmove(point, vec, sizeof(t_vec));
	free(vec);
	return (point);
}
