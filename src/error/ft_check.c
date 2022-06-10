/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:48 by hloke             #+#    #+#             */
/*   Updated: 2022/06/10 15:12:59 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
Check for file format, file extension, and file permission
Return the file descriptor of the scene file if successful
*/
int	ft_check_file(char *scene)
{
	int	i;
	int	fd;

	i = 0;
	while (scene[i] && scene[i] != '.')
		i += 1;
	if (scene[i] == '\0')
		ft_error_exit("File is not in .rt format.");
	if (ft_strcmp(scene + (i + 1), "rt") != 0)
		ft_error_exit("Wrong file extension.");
	fd = open(scene, O_RDONLY, 0);
	if (fd == -1)
		ft_error_exit("File cannot be opened.");
	return (fd);
}

/*
 * First index is -1 because of integer array looping problem.
 * There is no null terminator, have to use 0 as a stopping point.
*/
void	ft_check_info(char *data, int elem_info)
{
	const double	range[][2] = {{-1, -1}, {0, INT_MAX}, {0, 180},
	{0, INT_MAX}, {-1.0, 1.0}, {0.0, 1.0}, {0, 255}, {INT_MIN, INT_MAX}};
	const size_t	size[] = {-1, 1, 1, 1, 3, 1, 3, 3};
	char			**tmp;
	int				i;

	tmp = ft_split(data, ',');
	if (ft_array_size(tmp) != size[elem_info])
		ft_error_exit("Wrong number of values.");
	i = 0;
	while (tmp[i])
	{
		if (ft_atof(tmp[i]) < range[elem_info][0] || ft_atof(tmp[i]) >
			range[elem_info][1])
			ft_error_exit("Value is out of range.");
		i += 1;
	}
	ft_array_del(tmp, free);
}

void	ft_check_line_aux(char **info, const int check[6])
{
	int	i;
	int	size;

	i = -1;
	while (check[++i] != 0)
	{
		if (info[i + 1] == NULL)
			ft_error_exit("Too few inputs");
		else
			ft_check_info(info[i + 1], check[i]);
	}
	size = i;
	while (info[size] != NULL)
		size += 1;
	if (size != (i + 1))
		ft_error_exit("Too many inputs.");
}

/*
 * Split line using space to obtain element information
 * 
 */
void	ft_check_line(char *line)
{
	char		**info;
	const char	*spec[] = {"A", "C", "L", "sp", "pl", "cy"};
	const int	check[][6] = {{ratio, rgb}, {xyz, orient, fov},
	{xyz, ratio, rgb}, {xyz, diameter, rgb}, {xyz, orient, rgb},
	{xyz, orient, diameter, height, rgb}};
	const int	n = sizeof(spec) / sizeof(spec[0]);
	int			i;

	info = ft_split(line, ' ');
	i = -1;
	while (++i < n)
	{
		if (ft_strcmp(info[0], spec[i]) == 0)
		{
			ft_check_line_aux(info, check[i]);
			break ;
		}
	}
	if (i == n)
		ft_error_exit("Invalid identifier.");
	ft_array_del(info, free);
}
