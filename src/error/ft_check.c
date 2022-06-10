/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:48 by hloke             #+#    #+#             */
/*   Updated: 2022/06/10 17:27:42 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/* Open a scene file that ends with .rt, and return the file descriptor. */
int	ft_open_scene(const char *scene)
{
	char	*ptr;
	int		fd;

	ptr = ft_strrchr(scene, '.');
	if (ptr == NULL || ft_strcmp(ptr, ".rt") != 0)
	{
		errno = EINVAL;
		ft_perror("Invalid input file format");
	}
	fd = open(scene, O_RDONLY, 0);
	if (fd == -1)
		ft_perror("Scene file cannot be opened");
	return (fd);
}

/* Parse one line of scene input file into an array, with tab as
 * delimiter. Continuous tabs means some inputs are parsed as empty
 * string. The output from this function must eventually be freed. */
char	**ft_split_scene(const char *line)
{
	char			**arr;
	char			*ptr;
	const size_t	max_arg = 7;
	size_t			i;

	arr = ft_calloc(sizeof(char *), max_arg + 1);
	if (arr == NULL)
		ft_perror("ft_split_scene cannot allocate memory.");
	i = 0;
	while (line && *line != '\0')
	{
		if (i == max_arg)
		{
			errno = ERANGE;
			ft_perror("Line in scene file is too long");
		}
		ptr = ft_strchr(line, '\t');
		if (ptr != NULL)
			arr[i] = ft_substr(line, 0, ptr - line);
		else
			arr[i] = ft_strdup(line);
		line = ptr + (ptr != NULL);
		++i;
	}
	return (arr);
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
		ft_perror("Wrong number of values.");
	i = 0;
	while (tmp[i])
	{
		if (ft_atof(tmp[i]) < range[elem_info][0] || ft_atof(tmp[i]) >
			range[elem_info][1])
			ft_perror("Value is out of range.");
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
			ft_perror("Too few inputs");
		else
			ft_check_info(info[i + 1], check[i]);
	}
	size = i;
	while (info[size] != NULL)
		size += 1;
	if (size != (i + 1))
		ft_perror("Too many inputs.");
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
		ft_perror("Invalid identifier.");
	ft_array_del(info, free);
}
