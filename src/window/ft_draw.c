/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:22:27 by hloke             #+#    #+#             */
/*   Updated: 2022/06/16 11:47:44 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

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
void	ft_draw_img8(t_window *window, t_img8 *img)
{
	size_t	i;
	size_t	j;
	int		color;
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
			mlx_pixel_put(window->mlx, window->mlx_win, j, i, color);
		}
	}
}

/*
 * @color = in 0xFFFFFF format
 * If an object is rotated or translated, draw a screen with specified color
 * before printing a new image.
 */
void	ft_draw_colored_screen(t_window *window, t_img8 *img, int color)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < img->row)
	{
		j = -1;
		while (++j < img->col)
			mlx_pixel_put(window->mlx, window->mlx_win, j, i, color);
	}
}
