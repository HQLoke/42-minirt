/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:24:23 by weng              #+#    #+#             */
/*   Updated: 2022/06/01 15:58:02 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Create an empty hit object, with it's obj member pointing to NULL. */
t_hit	*ft_hit_new(void)
{
	t_hit	*hit;

	hit = malloc(sizeof(t_hit));
	if (hit == NULL)
		return (NULL);
	hit->obj = NULL;
	hit->point = ft_vec4_new(0, 0, 0, 0);
	hit->norm = ft_vec4_new(0, 0, 0, 0);
	if (hit->point == NULL || hit->norm == NULL)
		return (ft_hit_del(hit));
	else
		return (hit);
}

/* Return the pointer to a *t_hit object that represents the first
 * object that a given 'ray' will hit, or NULL if ray does not intersect
 * any object. */
t_hit	*ft_hit_objs(t_ray *ray, t_list *objs)
{
	double	distance;
	t_obj	*obj;
	t_hit	*hit;

	hit = ft_hit_new();
	hit->distance = INFINITY;
	while (objs != NULL)
	{
		obj = objs->content;
		if (obj->intersect(obj, ray, hit->point, hit->norm) == 1)
		{
			distance = ft_vec_len(ft_vec_sub(hit->point, ray->org));
			if (distance < hit->distance)
			{
				hit->distance = distance;
				hit->obj = obj;
			}
		}
		objs = objs->next;
	}
	if (hit->obj == NULL)
		return (ft_hit_del(hit));
	hit->obj->intersect(hit->obj, ray, hit->point, hit->norm);
	return (hit);
}

/* Deletes a t_hit element. The 'obj' pointer will not be freed, since
 * it is just the address pointing to the actual object in a list,
 * rather than a deep copy. */
t_hit	*ft_hit_del(t_hit *hit)
{
	if (hit == NULL)
		return (NULL);
	ft_vec_del(hit->point);
	ft_vec_del(hit->norm);
	free(hit);
	return (NULL);
}
