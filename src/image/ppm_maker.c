/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:40:36 by hloke             #+#    #+#             */
/*   Updated: 2022/05/28 22:27:06 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

static int	ft_ppm_header(
	const char *pathname, char *type, size_t row, size_t col)
{
	int	fd;

	fd = open(pathname, O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
	if (fd == -1)
	{
		perror("Cannot create ppm file.");
		return (fd);
	}
	ft_putendl_fd(type, fd);
	ft_putnbr_fd(col, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(row, fd);
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(255, fd);
	ft_putstr_fd("\n", fd);
	return (fd);
}

/* Converts a t_img8 image to a ppm P6 format. */
int	ft_image8_2_ppm6(t_img8 *img, const char *pathname)
{
	int		fd;

	fd = ft_ppm_header(pathname, "P6", img->row, img->col);
	if (fd == -1)
		return (0);
	write(fd, img->data, img->row * img->col * 3);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (1);
}
