/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:59:31 by hloke             #+#    #+#             */
/*   Updated: 2022/06/09 15:24:18 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

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

// ft_error.c
void	ft_error(char *scene);
void	ft_error_exit(char *str);

// ft_check.c
int		ft_check_file(char *scene);
void	ft_check_info(char *data, int elem_info);
void	ft_check_line(char *line);

#endif