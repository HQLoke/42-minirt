/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:16:59 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 10:44:39 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Return a new cylinder object.
 * @param ctr		4D vector containing the coordinates of the centre
 					of cylinder
 * @param orient	4D vector containning the orientation vector
 * @param dim		2D vector containing the radius and height of cylinder
 * @param colour	3D vector containing the colour of the cylinder
 * */
t_obj	*ft_cylinder_new(t_vec *ctr, t_vec *orient, t_vec *dim, t_vec *colour)
{
	t_obj	*cy;

	cy = malloc(sizeof(t_obj));
	if (cy == NULL)
		return (NULL);
	cy->type = CYLINDER;
	cy->dimension = dim;
	cy->colour = colour;
	orient = ft_vec_normalise(orient);
	cy->to_world = ft_affine_transform(ctr, orient);
	cy->fr_world = ft_mat_affine_inverse(ft_mat_copy(cy->to_world));
	ft_vec_del(ctr);
	ft_vec_del(orient);
	if (cy->to_world == NULL || cy->fr_world == NULL)
	{
		ft_obj_del(cy);
		return (NULL);
	}
	cy->intersect = ft_cylinder_intersect;
	return (cy);
}

/* Calculate the coefficient for cylinder and stores in 'coeff'. */
static void	ft_cylinder_coefficient(t_obj *cy, t_ray *ray, double *coeff)
{
	coeff[0] = ft_vec_mul_dot(ray->dir, ray->dir) - pow(ray->dir->data[2], 2);
	coeff[1] = 2 * ft_vec_mul_dot(ray->org, ray->dir)
		- 2 * ray->org->data[2] * ray->dir->data[2];
	coeff[2] = ft_vec_mul_dot(ray->org, ray->org)
		- pow(ray->org->data[2], 2) - pow(cy->dimension->data[0], 2) - 1;
}

/* Returns 1 if 'ray' intersects a cylinder 'cy', 0 otherwise. If intersection
 * occurs, the intersection point is stored in 'point', and normal
 * vector is stored in 'norm'; otherwise, 'point' and 'norm' are
 * unchanged.
 * @param cy	pointer to a cylinder object.
 * @param ray	ray in world-coordinate.
 * @param point	pointer to store intersection point.
 * @param norm	pointer to store normal vector at intersection point.
 * */
int	ft_cylinder_intersect(t_obj *cy, t_ray *ray, t_vec *point, t_vec *norm)
{
	double	coeff[3];
	double	t;
	double	discri;
	int		retval;

	ray = ft_ray_transform(cy->fr_world, ft_ray_copy(ray));
	ft_cylinder_coefficient(cy, ray, coeff);
	discri = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
	retval = (discri >= 0);
	if (retval == 1)
	{
		t = -(coeff[1] + sqrt(discri)) / (2 * coeff[0]);
		point = ft_ray_calc_point(ray, t, point);
		if (eq_double(t, 0) == 1
			|| fabs(point->data[2]) > cy->dimension->data[1] / 2)
			t = -(coeff[1] - sqrt(discri)) / (2 * coeff[0]);
		point = ft_ray_calc_point(ray, t, point);
		norm = ft_cylinder_normal(cy, point, norm);
		ft_mat_mul_vec(cy->to_world, point);
		ft_mat_mul_vec(cy->to_world, norm);
		retval = (eq_double(t, 0) == 0 && t > 0);
	}
	ft_ray_del(ray);
	return (retval && fabs(point->data[2]) <= cy->dimension->data[1] / 2);
}

/* Calculate the normal vector at a point on a cylinder, and store it in
 * the 'normal' vector. If the point given is not on the surface, and
 * error message will be printed.
 * 
 * For this calculation, it the height of the cylinder is not checked, 
 * i.e. the cylinder is assumed to have infinite height.
 * */
t_vec	*ft_cylinder_normal(t_obj *cy, t_vec *point, t_vec *norm)
{
	t_vec	*normal;

	if (norm->data != NULL)
	{
		free(norm->data);
		norm->data = NULL;
	}
	if (eq_double(
			pow(point->data[0], 2) + pow(point->data[1], 2),
			pow(cy->dimension->data[0], 2)) == 0)
	{
		perror("Point is not on a given cylinder.");
		exit(1);
	}
	normal = ft_vec4_new(point->data[0], point->data[1], 0.0, 0.0);
	ft_memmove(norm, normal, sizeof(t_vec));
	free(normal);
	ft_vec_normalise(norm);
	return (norm);
}
