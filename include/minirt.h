/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:50 by hloke             #+#    #+#             */
/*   Updated: 2022/05/23 10:50:00 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "element.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

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
size_t	ft_array_size(char **array);
double	ft_atof(const char *str);
long	ft_atol(const char *s);
void	ft_memdel(void **ptr);

#endif