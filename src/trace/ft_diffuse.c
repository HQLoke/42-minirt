/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:06:13 by weng              #+#    #+#             */
/*   Updated: 2022/05/30 14:38:47 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return the first object that a given 'ray' will hit, or NULL if ray
 * does not intersect any object. If an intersection occours, the 'point'
 * and 'norm' will be updated to the point of intersection and normal to
 * the surface at point of intersection. */
t_obj	*ft_hit_objs(t_ray *ray, t_list *objs, t_vec *point, t_vec *norm)
{
	double	distance_min;
	double	distance;
	t_obj	*obj_min;
	t_obj	*obj;

	distance_min = INFINITY;
	obj_min = NULL;
	while (objs != NULL)
	{
		obj = objs->content;
		if (obj->intersect(obj, ray, point, norm) == 1)
		{
			distance = ft_vec_len(ft_vec_sub(point, ray->org));
			if (distance < distance_min)
			{
				distance_min = distance;
				obj_min = objs->content;
			}
		}
		objs = objs->next;
	}
	if (obj_min != NULL)
		obj_min->intersect(obj_min, ray, point, norm);
	return (obj_min);
}

/* Return 1 if a ray hits a light, or 0 if its an object instead. */
int	ft_hit_light(t_light *light, t_ray *ray, t_list *objs)
{
	t_vec	point;
	t_vec	norm;
	t_vec	*vec;
	double	d_obj;
	double	d_light;

	point.data = NULL;
	norm.data = NULL;
	vec = ft_vec_sub(ft_vec_copy(light->centre), ray->org);
	d_light = ft_vec_len(vec);
	ft_vec_del(vec);
	d_obj = INFINITY;
	if (ft_hit_objs(ray, objs, &point, &norm) != NULL)
	{
		vec = ft_vec_sub(ft_vec_copy(&point), ray->org);
		d_obj = ft_vec_len(vec);
		ft_vec_del(vec);
	}
	free(point.data);
	free(norm.data);
	return (d_light < d_obj);
}

/* Return the intensity of one light, given a point and normal at
 * intersection, if a ray starting at the intersection point could hit
 * the light. Otherwise, return NULL. */
t_vec	*ft_light_intensity(
	t_light *light, t_list *objs, t_vec *point, t_vec *norm)
{
	t_ray	*ray;
	double	factor;
	t_vec	*intensity;

	if (light->type == AMBIENT)
		return (light->intense(light, NULL));
	ray = ft_ray_new(ft_vec_copy(point),
			ft_vec_sub(ft_vec_copy(light->centre), point));
	factor = ft_vec_mul_dot(norm, ray->dir);
	intensity = NULL;
	if (ft_hit_light(light, ray, objs) == 1 && factor > 0)
	{
		intensity = light->intense(light, ray);
		intensity = ft_vec_mul_scalar(intensity, factor);
	}
	ft_ray_del(ray);
	return (intensity);
}

/* Return the total intensity at a point, given multiple light and
 * objects. The first light source must be the ambient light source. */
t_vec	*ft_sum_intensities(
	t_list	*lights, t_list *objs, t_vec *point, t_vec *norm)
{
	t_vec	*vec;
	t_vec	*intensity;
	t_light	*light;

	light = lights->content;
	if (light->type != AMBIENT)
	{
		perror("The first light source must be an ambient light source.\n");
		return (NULL);
	}
	vec = ft_light_intensity(light, objs, point, norm);
	lights = lights->next;
	while (lights != NULL)
	{
		light = lights->content;
		intensity = ft_light_intensity(light, objs, point, norm);
		if (intensity != NULL)
		{
			vec = ft_vec_add(vec, intensity);
			ft_vec_del(intensity);
		}
		lights = lights->next;
	}
	return (vec);
}

/* Return the diffuse component of the lighting formula. None of the
 * light component can have an intensity value more than 1. */
t_vec	*ft_diffuse(t_hit *hit, t_list *objs, t_list *lights)
{
	t_vec	*intensity;
	size_t	i;

	intensity = ft_sum_intensities(lights, objs, hit->point, hit->norm);
	intensity = ft_vec_mul_elem(intensity, hit->obj->colour);
	i = -1;
	while (++i < intensity->size)
	{
		if (intensity->data[i] > 1)
			intensity->data[i] = 1;
	}
	return (intensity);
}
