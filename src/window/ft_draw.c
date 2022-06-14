/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:22:27 by hloke             #+#    #+#             */
/*   Updated: 2022/06/14 12:52:25 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

/*
 * Given an 8 bit image, draw the image pixel by pixel
 */
int	ft_draw_img8(t_window *window)
{
	size_t	i;
	size_t	j;
	double	color;
	t_vec	*vec;
	t_img8	*img;

	img = window->img;
	if (img == NULL)
		
	i = -1;
	while (++i < img->row)
	{
		j = -1;
		while (++j < img->col)
		{
			vec = ft_image8_get(img, i, j);
			color = vec->data[0] * vec->data[1] * vec->data[2];
			mlx_pixel_put(window->mlx, window->mlx_win, j, i, (int)color);
		}
	}
	return (1);
}
