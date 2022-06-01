/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:06:13 by weng              #+#    #+#             */
/*   Updated: 2022/06/01 16:39:19 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Return 1 if a ray hits a light, or 0 if its an object instead. */
int	ft_hit_light(t_light *light, t_ray *ray, t_list *objs)
{
	t_hit	*hit;
	t_vec	*vec;
	double	d_obj;
	double	d_light;

	vec = ft_vec_sub(ft_vec_copy(light->centre), ray->org);
	d_light = ft_vec_len(vec);
	ft_vec_del(vec);
	d_obj = INFINITY;
	hit = ft_hit_objs(ray, objs);
	if (hit != NULL)
		d_obj = hit->distance;
	ft_hit_del(hit);
	return (d_light < d_obj);
}

/* Return the intensity of one light, given a point and normal at
 * intersection, if a ray starting at the intersection point could hit
 * the light. Otherwise, return NULL. */
t_vec	*ft_light_intensity(t_hit *hit, t_light *light, t_list *objs)
{
	t_ray	*ray;
	double	factor;
	t_vec	*intensity;

	if (light->type == AMBIENT)
		return (light->intense(light, NULL));
	ray = ft_ray_new(ft_vec_copy(hit->point),
			ft_vec_sub(ft_vec_copy(light->centre), hit->point));
	factor = ft_vec_mul_dot(hit->norm, ray->dir);
	intensity = NULL;
	if (ft_hit_light(light, ray, objs) == 1 && factor > 0)
	{
		intensity = light->intense(light, ray);
		intensity = ft_vec_mul_scalar(intensity, factor);
	}
	ft_ray_del(ray);
	return (intensity);
}

/* Return the total intensity at a point, given multiple light and objects. */
t_vec	*ft_sum_intensities(
	t_hit *hit, t_light *ambient, t_list *lights, t_list *objs)
{
	t_vec	*vec;
	t_vec	*intensity;
	t_light	*light;

	if (ambient != NULL)
		vec = ft_light_intensity(hit, ambient, objs);
	else
		vec = ft_vec3_new(0, 0, 0);
	while (lights != NULL)
	{
		light = lights->content;
		intensity = ft_light_intensity(hit, light, objs);
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
t_vec	*ft_diffuse(t_hit *hit, t_light	*ambient, t_list *lights, t_list *objs)
{
	t_vec	*intensity;
	size_t	i;

	intensity = ft_sum_intensities(hit, ambient, lights, objs);
	intensity = ft_vec_mul_elem(intensity, hit->obj->colour);
	i = -1;
	while (++i < intensity->size)
	{
		if (intensity->data[i] > 1)
			intensity->data[i] = 1;
	}
	return (intensity);
}
