/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:59:31 by hloke             #+#    #+#             */
/*   Updated: 2022/06/11 01:01:31 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "linalg.h"
# include "libft.h"

typedef struct s_vec	t_vec;	// forward declaration

typedef enum e_elem
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cylinder,
	cone
}	t_elem;

/*
 * diameter range: {0, INT_MAX}       size: 1
 * fov      range: {0, 180}           size: 1
 * height   range: {0, INT_MAX}       size: 1
 * orient   range: {-1, 1}            size: 3
 * ratio    range: {0, 1}             size: 1
 * rgb      range: {0, 255}           size: 3
 * xyz      range: {INT_MIN, INT_MAX} size: 3
 */
enum e_elem_info
{
	diameter = 1,
	fov,
	height,
	orient,
	ratio,
	rgb,
	xyz
};

// ft_array.c -- NULL terminated array related functions
size_t	ft_array_size(const void *array);
void	ft_array_del(void *ptr, void (*del)(void *));

// ft_check.c
int		ft_open_scene(const char *scene);
char	**ft_split_scene(const char *line, char c);

// ft_double.c
double	ft_atof(const char *str);
int		ft_isdouble(const char *s);
int		ft_check_double(double d, double min, double max);
t_vec	*ft_parse_vector(const char *s, size_t size, double min, double max);

// ft_error.c
void	ft_perror(const char *s);
void	ft_error(char *scene);

#endif
