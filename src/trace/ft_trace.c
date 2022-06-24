/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:29:53 by weng              #+#    #+#             */
/*   Updated: 2022/06/24 11:07:10 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Trace a ray to determine and return the colour of a particular pixel.
 * If a ray hits an object, it will return the colour of diffused
 * lighting. Otherwise, it will return the ambient lighting. */
t_vec	*ft_trace(t_ray *ray, t_light *ambient, t_list *lights, t_list *objs)
{
	t_hit	*hit;
	t_vec	*vec;

	hit = ft_hit_objs(ray, objs);
	if (hit == NULL)
	{
		if (ambient != NULL)
			return (ambient->intense(ambient, NULL));
		else
			return (ft_vec3_new(0, 0, 0));
	}
	vec = ft_limit_colour(hit, ambient, lights, objs);
	ft_hit_del(hit);
	return (vec);
}

static t_arg	*ft_arg_new(t_scene *scene, t_img *image, int k)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (arg == NULL)
		ft_perror("ft_arg_new", 0);
	arg->scene = scene;
	arg->image = image;
	arg->k = k;
	return (arg);
}

static void	ft_arg_del(t_arg *arg)
{
	free(arg);
}

/* Render scene onto image 'img' */
void	*ft_render_aux(void *arg_)
{
	t_arg	*arg;
	t_ray	*ray;
	t_vec	*colour;
	int		reso_x;
	int		i;

	arg = arg_;
	reso_x = arg->scene->cam->reso_x;
	i = arg->k;
	while (i < reso_x * arg->scene->cam->reso_y)
	{
		ray = ft_camera_ray(arg->scene->cam, i % reso_x, i / reso_x);
		colour = ft_trace(ray,
				arg->scene->ambient, arg->scene->lights, arg->scene->objs);
		ft_image_set(arg->image, i / reso_x, i % reso_x, colour);
		ft_ray_del(ray);
		ft_vec_del(colour);
		i += PROCESSOR_COUNT;
	}
	return (NULL);
}

/* Render a scene by looping through all the */
t_img	*ft_render(t_cam *cam, t_light *ambient, t_list *lights, t_list *objs)
{
	t_img		*img;
	t_scene		scene;
	t_arg		*arg[PROCESSOR_COUNT];
	pthread_t	thread[PROCESSOR_COUNT];
	int			i;

	img = ft_image_new(cam->reso_y, cam->reso_x);
	scene.cam = cam;
	scene.ambient = ambient;
	scene.lights = lights;
	scene.objs = objs;
	i = -1;
	while (++i < PROCESSOR_COUNT)
	{
		arg[i] = ft_arg_new(&scene, img, i);
		if (pthread_create(&thread[i], NULL, ft_render_aux, arg[i]) != 0)
			ft_perror("Can't create tread", 0);
	}
	while (i-- > 0)
	{
		if (pthread_join(thread[i], NULL) != 0)
			ft_perror("Can't join tread", 0);
		ft_arg_del(arg[i]);
	}
	return (img);
}
