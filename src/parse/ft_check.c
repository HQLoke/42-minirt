/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:48 by hloke             #+#    #+#             */
/*   Updated: 2022/06/11 11:11:11 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

/* Parse one line of scene input file into an array, with 'c' as
 * delimiter. Continuous delimiter means some inputs are parsed as empty
 * string. The output from this function must eventually be freed. */
char	**ft_split_scene(const char *line, char c)
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
		ptr = ft_strchr(line, c);
		if (ptr != NULL)
			arr[i] = ft_substr(line, 0, ptr - line);
		else
			arr[i] = ft_strdup(line);
		line = ptr + (ptr != NULL);
		++i;
	}
	return (arr);
}
