/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:16:59 by weng              #+#    #+#             */
/*   Updated: 2022/06/06 01:07:53 by weng             ###   ########.fr       */
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
	t_opt	opt;
	t_obj	*cy;

	opt.colour = colour;
	opt.disruption = 0;
	cy = ft_obj_new(ctr, orient, dim, &opt);
	if (cy == NULL)
		return (NULL);
	cy->type = CYLINDER;
	cy->intersect = ft_obj_intersect;
	cy->coefficient = ft_cylinder_coefficient;
	cy->normal = ft_cylinder_normal;
	return (cy);
}

/* Calculate the coefficient for cylinder and stores in 'coeff'. */
void	ft_cylinder_coefficient(t_obj *cy, t_ray *ray, double *coeff)
{
	coeff[0] = ft_vec_mul_dot(ray->dir, ray->dir) - pow(ray->dir->data[2], 2);
	coeff[1] = 2 * ft_vec_mul_dot(ray->org, ray->dir)
		- 2 * ray->org->data[2] * ray->dir->data[2];
	coeff[2] = ft_vec_mul_dot(ray->org, ray->org)
		- pow(ray->org->data[2], 2) - pow(cy->dimension->data[0], 2) - 1;
}

/* Calculate the normal vector at a point on a cylinder, and store it in
 * the 'normal' vector. If the point given is not on the surface, and
 * error message will be printed.
 * 
 * For this calculation, it the height of the cylinder is not checked, 
 * i.e. the cylinder is assumed to have infinite height.
 * */
t_vec	*ft_cylinder_normal(t_obj *cy, t_ray *ray, t_vec *point, t_vec *norm)
{
	t_vec	*normal;

	(void) ray;
	if (eq_double(
			pow(point->data[0], 2) + pow(point->data[1], 2),
			pow(cy->dimension->data[0], 2)) == 0)
	{
		perror("Point is not on a given cylinder.");
		exit(1);
	}
	normal = ft_vec4_new(point->data[0], point->data[1], 0.0, 0.0);
	ft_vec_normalise(normal);
	ft_vec_swap(norm, normal);
	ft_vec_del(normal);
	norm = ft_correct_normal(norm, ray);
	return (norm);
}
