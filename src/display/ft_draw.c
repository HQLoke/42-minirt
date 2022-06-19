/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:22:27 by hloke             #+#    #+#             */
/*   Updated: 2022/06/19 09:28:00 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

//* Draw a pixel to an image.
void	ft_draw_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (image == NULL || x < 0 || y < 0 || x > image->width || y > image->height)
		return ;
	dst = image->data + (y * image->size_line + x * (image->bpp / 8));
	*((unsigned int *) dst) = color;
}

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

/*
 * Given an 8 bit image, draw the image pixel by pixel
 */
void	ft_draw_image(t_mlx *mlx, t_img8 *img)
{
	size_t	i;
	size_t	j;
	char	color;
	t_vec	*vec;

	if (img == NULL)
		ft_perror("ft_draw_img8: No image file found.");
	i = -1;
	while (++i < img->row)
	{
		j = -1;
		while (++j < img->col)
		{
			vec = ft_image8_get(img, i, j);
			if (vec == NULL)
				ft_perror("ft_draw_img8: Invalid color data.");
			color = ft_convert_rgb(vec);
			ft_draw_pixel(mlx->image, i, j, color);
		}
	}
}