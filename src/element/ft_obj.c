/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:40:38 by weng              #+#    #+#             */
/*   Updated: 2022/05/22 23:05:10 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Return a new 2nd order object.
 * @param ctr		4D vector containing the coordinates of the centre of object
 * @param orient	4D vector containning the orientation vector
 * @param dim		2D vector containing the radius and height of object
 * @param colour	3D vector containing the colour of the object
 * */
t_obj	*ft_obj_new(t_vec *ctr, t_vec *orient, t_vec *dim, t_vec *colour)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	obj->dimension = dim;
	obj->colour = colour;
	orient = ft_vec_normalise(orient);
	obj->to_world = ft_affine_transform(ctr, orient);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
	ft_vec_del(ctr);
	ft_vec_del(orient);
	if (obj->to_world == NULL || obj->fr_world == NULL)
	{
		ft_obj_del(obj);
		return (NULL);
	}
	return (obj);
}

/* Delete an object. */
void	ft_obj_del(t_obj *obj)
{
	if (obj == NULL)
		return ;
	ft_vec_del(obj->dimension);
	ft_vec_del(obj->colour);
	ft_mat_del(obj->to_world);
	ft_mat_del(obj->fr_world);
	free(obj);
}

/* Returns 1 if 'ray' intersects an object 'obj', 0 otherwise. If
 * intersection occurs, the intersection point is stored in 'point', and
 * normal vector is stored in 'norm'; otherwise, 'point' and 'norm' are
 * unchanged.
 * @param obj	pointer to an object.
 * @param ray	ray in world-coordinate.
 * @param point	pointer to store intersection point.
 * @param norm	pointer to store normal vector at intersection point.
 * */
int	ft_obj_intersect(t_obj *obj, t_ray *ray, t_vec *point, t_vec *norm)
{
	double	coeff[3];
	double	t;
	double	discri;
	int		retval;

	ray = ft_ray_transform(obj->fr_world, ft_ray_copy(ray));
	obj->coefficient(obj, ray, coeff);
	discri = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
	retval = (discri >= 0);
	if (retval == 1)
	{
		t = -(coeff[1] + sqrt(discri)) / (2 * coeff[0]);
		point = ft_ray_calc_point(ray, t, point);
		if (eq_double(t, 0) == 1
			|| t <= 0
			|| fabs(point->data[2]) > obj->dimension->data[1] / 2)
			t = -(coeff[1] - sqrt(discri)) / (2 * coeff[0]);
		point = ft_ray_calc_point(ray, t, point);
		norm = obj->normal(obj, ray, point, norm);
		ft_mat_mul_vec(obj->to_world, point);
		ft_mat_mul_vec(obj->to_world, norm);
		retval = (eq_double(t, 0) == 0 && t > 0);
	}
	ft_ray_del(ray);
	return (retval && fabs(point->data[2]) <= obj->dimension->data[1] / 2);
}

/* Correct the direction of the normal vector from the surface based on
 * the direction of the ray. Returns the corrected normal.
 *
 * The dot product of the ray direction vector and normal should be less
 * than or equal to 0. Else, the normal should be reversed.
 */
t_vec	*ft_correct_normal(t_vec *norm, t_ray *ray)
{
	double	dot;

	dot = ft_vec_mul_dot(norm, ray->dir);
	if (dot > 0)
		norm = ft_vec_mul_scalar(norm, -1);
	return (norm);
}
