/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:34:22 by hloke             #+#    #+#             */
/*   Updated: 2022/05/25 11:13:52 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Prints Error followed by \n first. 
Then prints an explicit error message that shows where the error happened.
Exit failure at last.
*/
static void	error_exit(char *str)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit (EXIT_FAILURE);
}

/*
Prints Error followed by \n first.
Then go through the linked list. 
For each error message, attach the line number where the error occured and print.
Doesn't have to free linked list because did not use malloc for error message.
Exit failure at last.
*/
static void	multiple_error_exit(t_list **error)
{
	t_list	*tmp;
	char	*num;

	write(STDERR_FILENO, "Error\n", 6);
	tmp = *error;
	while (tmp != NULL)
	{
		num = ft_itoa(tmp->type);
		write(STDERR_FILENO, "Line ", 5);
		write(STDERR_FILENO, num, ft_strlen(num));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, tmp->content, ft_strlen(tmp->content));
		write(STDERR_FILENO, "\n", 1);
		free (num);
		tmp = tmp->next;
	}
	exit (EXIT_FAILURE);
}

/*
Check for file format, file extension, and file permission
Return the file descriptor of the scene file if successful
*/
static int	check_file(char *scene)
{
	int	i;
	int	fd;

	i = 0;
	while (scene[i] && scene[i] != '.')
		i += 1;
	if (scene[i] == '\0')
		error_exit("File is not in .rt format");
	if (ft_strcmp(scene + (i + 1), "rt") != 0)
		error_exit("Wrong file extension");
	fd = open(scene, O_RDONLY, 0);
	if (fd == -1)
		error_exit("File cannot be opened");
	return (fd);
}

/*
Check line one-by-one. Split line using space to obtain element information
*/
static void	check_line(char *line, int line_num, t_list **error)
{
	char		**info;
	const char	*spec[] = {"A", "L", "C", "pl", "sp", "cy"};
	static void	(*func[])(char **, int, t_list **) = {
		&check_ambient, &check_light, &check_camera, &check_plane,
		&check_sphere, &check_cylinder
	};
	const int	n = sizeof(spec) / sizeof(spec[0]);
	int			i;

	info = ft_split(line, ' ');
	i = -1;
	while (++i < n)
	{
		if (ft_strcmp(info[0], spec[i]) == 0)
		{
			func[i](info, line_num, error);
			break ;
		}
	}
	if (i == n)
		ft_lstadd_back(error, ft_lstnew("Invalid type identifier", line_num));
	ft_memdel(info, free);
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
void	error_handler(char *scene)
{
	int		fd;
	int		line_num;
	char	*line;
	t_list	*error;

	fd = check_file(scene);
	line_num = 1;
	line = get_next_line(fd);
	error = NULL;
	while (line != NULL)
	{
		check_line(line, line_num, &error);
		line_num += 1;
		free (line);
		line = get_next_line(fd);
	}
	if (error != NULL)
		multiple_error_exit(&error);
}
