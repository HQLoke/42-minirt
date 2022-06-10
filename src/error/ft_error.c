/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:34:22 by hloke             #+#    #+#             */
/*   Updated: 2022/06/09 15:08:50 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Prints Error followed by \n first. 
Then prints an explicit error message that shows where the error happened.
Exit failure at last.
*/
void	ft_error_exit(char *str)
{
	write(STDERR_FILENO, "Error: \n", 7);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit (EXIT_FAILURE);
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
