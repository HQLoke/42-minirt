/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:34:22 by hloke             #+#    #+#             */
/*   Updated: 2022/06/10 15:40:38 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/* Print error and exit the program with error code 1. */
void	ft_perror(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/*
List of errors to check in order:
1: File format
2: File extension
3: File permission
4: Identifier
5: Number of coordinates
6: Value range
7: Number of capital elements cannot exceed 1
*/
void	ft_error(char *scene)
{
	int		fd;
	char	*line;

	fd = ft_check_file(scene);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_check_line(line);
		free (line);
		line = get_next_line(fd);
	}
}
