/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:53:28 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 10:55:16 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Return a new sphere object.
 * @param centre	4D vector containing the coordinates of the centre of sphere
 * @param dimension	1D vector containing the radius of the sphere
 * @param colour	3D vector containing the colour of the sphere
 * */
t_obj	*ft_sphere_new(t_vec *centre, t_vec *dimension, t_vec *colour)
{
	t_obj	*sphere;

	sphere = malloc(sizeof(t_obj));
	if (sphere == NULL)
		return (NULL);
	sphere->type = SPHERE;
	sphere->dimension = dimension;
	sphere->colour = colour;
	sphere->to_world = ft_affine_translate(
			centre->data[0], centre->data[1], centre->data[2]);
	sphere->fr_world = ft_affine_translate(
			-centre->data[0], -centre->data[1], -centre->data[2]);
	ft_vec_del(centre);
	if (sphere->to_world == NULL || sphere->fr_world == NULL)
	{
		ft_obj_del(sphere);
		return (NULL);
	}
	sphere->intersect = ft_sphere_intersect;
	return (sphere);
}

/* Delete a sphere object. */
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

/* Calculate the coefficient for sphere and stores in 'coeff'. */
static void	ft_sphere_coefficient(t_obj *sphere, t_ray *ray, double *coeff)
{
	coeff[0] = ft_vec_mul_dot(ray->dir, ray->dir);
	coeff[1] = 2 * ft_vec_mul_dot(ray->org, ray->dir);
	coeff[2] = ft_vec_mul_dot(ray->org, ray->org)
		- pow(sphere->dimension->data[0], 2) - 1;
}

/* Returns 1 if 'ray' intersects a 'sphere', 0 otherwise. If intersection
 * occurs, the intersection point is stored in 'point', and normal
 * vector is stored in 'norm'; otherwise, 'point' and 'norm' are
 * unchanged.
 * @param object	pointer to a sphere object.
 * @param ray		ray in world-coordinate.
 * @param point		pointer to store intersection point.
 * @param norm		pointer to store normal vector at intersection point.
 * */
int	ft_sphere_intersect(t_obj *sphere, t_ray *ray, t_vec *point, t_vec *norm)
{
	double	coeff[3];
	double	t;
	double	discri;
	int		retval;

	ray = ft_ray_transform(sphere->fr_world, ft_ray_copy(ray));
	ft_sphere_coefficient(sphere, ray, coeff);
	discri = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
	retval = (discri >= 0);
	if (retval == 1)
	{
		t = -(coeff[1] + sqrt(discri)) / (2 * coeff[0]);
		if (eq_double(t, 0) == 1)
			t = -(coeff[1] - sqrt(discri)) / (2 * coeff[0]);
		retval = (eq_double(t, 0) == 0 && t > 0);
		if (retval == 1)
		{
			point = ft_ray_calc_point(ray, t, point);
			norm = ft_sphere_normal(sphere, point, norm);
			ft_mat_mul_vec(sphere->to_world, point);
			ft_mat_mul_vec(sphere->to_world, norm);
		}
	}
	ft_ray_del(ray);
	return (retval);
}

/* Calculate the normal vector at a point on a sphere, and store it in
 * the 'normal' vector. If the point given is not on the surface, and
 * error message will be printed. */
t_vec	*ft_sphere_normal(t_obj *sphere, t_vec *point, t_vec *norm)
{
	t_vec	*normal;

	if (norm->data != NULL)
	{
		free(norm->data);
		norm->data = NULL;
	}
	if (eq_double(
			ft_vec_mul_dot(point, point),
			pow(sphere->dimension->data[0], 2) + 1) == 0)
	{
		perror("Point is not on a given sphere.");
		exit(1);
	}
	normal = ft_vec4_new(0, 0, 0, 1);
	normal = ft_vec_sub(normal, point);
	normal = ft_vec_mul_scalar(normal, -1);
	ft_memmove(norm, normal, sizeof(t_vec));
	free(normal);
	ft_vec_normalise(norm);
	return (norm);
}
