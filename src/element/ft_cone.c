/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:46:57 by weng              #+#    #+#             */
/*   Updated: 2022/06/06 01:07:31 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Return a new cone object.
 * @param ctr		4D vector containing the coordinates of the centre
 					of cone
 * @param orient	4D vector containning the orientation vector
 * @param height	height of the cone
 * @param colour	3D vector containing the colour of the cone
 * */
t_obj	*ft_cone_new(t_vec *ctr, t_vec *orient, double height, t_vec *colour)
{
	t_opt	opt;
	t_obj	*cone;
	t_vec	*dim;

	dim = ft_vec2_new(0, height);
	opt.colour = colour;
	opt.disruption = 0;
	cone = ft_obj_new(ctr, orient, dim, &opt);
	if (cone == NULL)
		return (NULL);
	cone->type = CONE;
	cone->intersect = ft_obj_intersect;
	cone->coefficient = ft_cone_coefficient;
	cone->normal = ft_cone_normal;
	return (cone);
}

/* Calculate the coefficient for cone and stores in 'coeff'. */
void	ft_cone_coefficient(t_obj *cone, t_ray *ray, double *coeff)
{
	(void) cone;
	coeff[0] = ft_vec_mul_dot(ray->dir, ray->dir)
		- 2 * pow(ray->dir->data[2], 2);
	coeff[1] = 2 * ft_vec_mul_dot(ray->org, ray->dir)
		- 4 * ray->org->data[2] * ray->dir->data[2];
	coeff[2] = ft_vec_mul_dot(ray->org, ray->org)
		- 2 * pow(ray->org->data[2], 2) - 1;
}

/* Calculate the normal vector at a point on a cone, and store it in
 * the 'normal' vector. If the point given is not on the surface, and
 * error message will be printed.
 * 
 * For this calculation, it the height of the cone is not checked, 
 * i.e. the cone is assumed to have infinite height.
 * 
 * Since it is assumed that the ray will not hit the object if it is
 * coming at the tangent, the ray will never hit the object at the
 * origin.
 * */
t_vec	*ft_cone_normal(t_obj *cone, t_ray *ray, t_vec *point, t_vec *norm)
{
	t_vec	*normal;

	(void) cone;
	if (eq_double(
			pow(point->data[0], 2) + pow(point->data[1], 2),
			pow(point->data[2], 2)) == 0)
	{
		perror("Point is not on a given cone.");
		exit(1);
	}
	normal = ft_vec4_new(point->data[0], point->data[1], -point->data[2], 0.0);
	ft_vec_normalise(normal);
	ft_vec_swap(norm, normal);
	ft_vec_del(normal);
	norm = ft_correct_normal(norm, ray);
	return (norm);
}
