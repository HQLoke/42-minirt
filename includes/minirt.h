/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:50 by hloke             #+#    #+#             */
/*   Updated: 2022/05/11 18:29:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
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
void	check_ambient(char **info, int line_num, t_list **error);
void	check_camera(char **info, int line_num, t_list **error);
void	check_light(char **info, int line_num, t_list **error);
void	check_sphere(char **info, int line_num, t_list **error);
void	check_plane(char **info, int line_num, t_list **error);
void	check_cylinder(char **info, int line_num, t_list **error);
void	error_exit(char *str);
void	multiple_error_exit(t_list **error);
void	error_handler(char *scene);

bool	check_float_range(double value, double min, double max);
size_t	ft_array_size(char **array);
void	ft_memdel(void **ptr);

#endif