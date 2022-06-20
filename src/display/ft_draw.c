/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:25:04 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 14:56:04 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/*
 * Colour vector contains rgb value in range (0, 1).
 * Bit shifting is required to create integer value from color hex code
 */
static int	ft_convert_rgb(t_vec *color)
{
	int	rgb[3];

	rgb[0] = color->data[0] * 255.9999;
	rgb[1] = color->data[1] * 255.9999;
	rgb[2] = color->data[2] * 255.9999;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

/* Draw a pixel to an image. */
static void	ft_pixel_draw(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (image == NULL
		|| x < 0 || y < 0 || x > image->width || y > image->height)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*((unsigned int *) dst) = color;
}

void	ft_draw_image(t_mlx *mlx)
{
	size_t	i;
	size_t	j;
	int		color;
	t_vec	*vec;

	if (mlx->img8 == NULL)
		ft_perror("ft_draw_image: Image8 file is not found.");
	i = -1;
	while (++i < mlx->img8->row)
	{
		j = -1;
		while (++j < mlx->img8->col)
		{
			vec = ft_image8_get(mlx->img8, i, j);
			if (vec == NULL)
				ft_perror("ft_draw_img8: Invalid color data.");
			color = ft_convert_rgb(vec);
			ft_pixel_draw(mlx->image, j, i, color);
			ft_vec_del(vec);
		}
	}
}
