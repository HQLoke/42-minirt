/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:59:41 by weng              #+#    #+#             */
/*   Updated: 2022/05/18 15:33:19 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Return a new plane object.
 * @param point		4D vector containing the coordinates of a point on the plane
 * @param norm		4D vector containing the normal of the plane
 * @param colour	3D vector containing the colour of the plane
 * */
t_obj	*ft_plane_new(t_vec *point, t_vec *norm, t_vec *colour)
{
	t_obj	*plane;

	plane = malloc(sizeof(t_obj));
	if (plane == NULL)
		return (NULL);
	plane->type = PLANE;
	norm->data[3] = -ft_vec_mul_dot(norm, point);
	plane->dimension = norm;
	plane->colour = colour;
	plane->to_world = NULL;
	plane->fr_world = NULL;
	ft_vec_del(point);
	plane->intersect = ft_plane_intersect;
	return (plane);
}

/* Returns 1 if 'ray' intersects a 'plane', 0 otherwise. If intersection
 * occurs, the intersection point is stored in 'point', and normal
 * vector is stored in 'norm'; otherwise, 'point' and 'norm' are
 * unchanged.
 * @param object	pointer to a plane object.
 * @param ray		ray in world-coordinate.
 * @param point		pointer to store intersection point.
 * @param norm		pointer to store normal vector at intersection point.
 * */
int	ft_plane_intersect(t_obj *plane, t_ray *ray, t_vec *point, t_vec *norm)
{
	double	denominator;
	double	t;
	int		retval;

	denominator = ft_vec_mul_dot(plane->dimension, ray->dir);
	retval = (denominator != 0);
	if (retval == 1)
	{
		t = -ft_vec_mul_dot(plane->dimension, ray->org) / denominator;
		retval = (eq_double(t, 0) == 0 && t > 0);
		if (retval == 1)
		{
			point = ft_ray_calc_point(ray, t, point);
			norm = ft_plane_normal(plane, point, norm);
		}
	}
	return (retval);
}

/* Calculate the normal vector of a plane. */
t_vec	*ft_plane_normal(t_obj *plane, t_vec *point, t_vec *norm)
{
	t_vec	*normal;

	if (norm->data != NULL)
	{
		free(norm->data);
		norm->data = NULL;
	}
	(void) point;
	normal = ft_vec_copy(plane->dimension);
	normal->data[3] = 0.0;
	ft_memmove(norm, normal, sizeof(t_vec));
	free(normal);
	ft_vec_normalise(norm);
	return (norm);
}
