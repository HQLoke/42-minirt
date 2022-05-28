/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:40:36 by hloke             #+#    #+#             */
/*   Updated: 2022/05/28 18:38:08 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ppm_maker(t_img8 *img)
{
	size_t	r;
	size_t	c;
	int		fd;
	char	*tmp;

	fd = open("./file1.ppm", O_CREAT | O_WRONLY, 0);
	if (fd == -1)
		perror("cannot create file.");
	write(fd, "P6\n", 3);
	tmp = ft_itoa(img->row);
	write(fd, tmp, ft_strlen(tmp));
	free (tmp);
	tmp = ft_itoa(img->col);
	write(fd, tmp, ft_strlen(tmp));
	free (tmp);
	r = -1;
	while (++r < img->row)
	{
		c = -1;
		while (++c < img->col)
		{
			write(fd, img->data[(r * img->row * img->col) + (c * 3 + 0)], 1);
			write(fd, img->data[(r * img->row * img->col) + (c * 3 + 1)], 1);
			write(fd, img->data[(r * img->row * img->col) + (c * 3 + 2)], 1);
		}
		printf("\n");
	}
	close(fd);
}
