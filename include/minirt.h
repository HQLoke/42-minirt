/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:50 by hloke             #+#    #+#             */
/*   Updated: 2022/06/24 02:01:24 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef PROCESSOR_COUNT
#  define PROCESSOR_COUNT 1
# endif

# include <pthread.h>

# include "element.h"
# include "image.h"
# include "libft.h"
# include "linalg.h"
# include "parse.h"
# include "display.h"

/* represents a data when an object is hit by a ray */
typedef struct s_hit
{
	t_obj	*obj;
	t_vec	*point;
	t_vec	*norm;
	t_ray	*ray;
	double	distance;
}	t_hit;

/* represents all the objects in a scene */
typedef struct s_scene
{
	t_cam	*cam;
	t_light	*ambient;
	t_list	*lights;
	t_list	*objs;
}	t_scene;

/* argument to be passed to thread */
typedef struct s_arg
{
	t_scene	*scene;
	t_img	*image;
	int		k;
}	t_arg;

// ft_diffuse.c -- ray tracing related functions
int		ft_hit_light(t_light *light, t_ray *ray, t_list *objs);
t_vec	*ft_light_intensity(t_hit *hit, t_light *light, t_list *objs);
t_vec	*ft_phong_reflection(
			t_hit *hit, t_light *ambient, t_list *lights, t_list *objs);
t_vec	*ft_limit_colour(
			t_hit *hit, t_light *ambient, t_list *lights, t_list *objs);

// ft_hit.c -- object-ray interaction related functions
t_hit	*ft_hit_new(t_ray *ray, t_vec *point, t_vec *norm);
t_hit	*ft_hit_objs(t_ray *ray, t_list *objs);
t_hit	*ft_hit_del(t_hit *hit);

// ft_trace.c -- rendering and tracing related function
t_vec	*ft_trace(t_ray *ray, t_light *ambient, t_list *lights, t_list *objs);
t_img	*ft_render(t_cam *cam, t_light *ambient, t_list *lights, t_list *objs);

#endif
