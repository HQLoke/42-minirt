/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:50 by hloke             #+#    #+#             */
/*   Updated: 2022/06/02 22:19:10 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "element.h"
# include "image.h"
# include "libft.h"
# include "linalg.h"

/* represents a data when an object is hit by a ray */
typedef struct s_hit
{
	t_obj	*obj;
	t_vec	*point;
	t_vec	*norm;
	t_ray	*ray;
	double	distance;
}	t_hit;

/*
/srcs/error
*/
void	check_ambient(char **info, int line_num, t_list **err);
void	check_camera(char **info, int line_num, t_list **err);
void	check_light(char **info, int line_num, t_list **err);
void	check_sphere(char **info, int line_num, t_list **err);
void	check_plane(char **info, int line_num, t_list **err);
void	check_cylinder(char **info, int line_num, t_list **err);
void	check_rgb(char *val, int line_num, t_list **err);
void	check_vector(char *val, int line_num, t_list **err);
void	check_xyz(char *val, int line_num, t_list **err);
void	error_handler(char *scene);

/*
/srcs/utils
*/
size_t	ft_array_size(const void *array);
double	ft_atof(const char *str);
void	ft_memdel(void *ptr, void (*del)(void *));

// ft_diffuse.c -- ray tracing related functions
int		ft_hit_light(t_light *light, t_ray *ray, t_list *objs);
t_vec	*ft_light_intensity(t_hit *hit, t_light *light, t_list *objs);
t_vec	*ft_sum_intensities(
			t_hit *hit, t_light *ambient, t_list *lights, t_list *objs);
t_vec	*ft_diffuse(t_hit *hit, t_light *ambient, t_list *lights, t_list *objs);

// ft_hit.c -- object-ray interaction related functions
t_hit	*ft_hit_new(t_ray *ray, t_vec *point, t_vec *norm);
t_hit	*ft_hit_objs(t_ray *ray, t_list *objs);
t_hit	*ft_hit_del(t_hit *hit);

// ft_trace.c -- rendering and tracing related function
t_vec	*ft_trace(t_ray *ray, t_light *ambient, t_list *lights, t_list *objs);
t_img	*ft_render(t_cam *cam, t_light *ambient, t_list *lights, t_list *objs);

#endif
