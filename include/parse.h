/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:59:31 by hloke             #+#    #+#             */
/*   Updated: 2022/06/11 14:32:43 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "element.h"
# include "linalg.h"
# include "libft.h"

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

// ft_parse.c -- parse line and return relevant objects
t_cam	*ft_parse_camera(char **arr);

#endif
