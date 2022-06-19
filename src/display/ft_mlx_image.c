/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:36:18 by hloke             #+#    #+#             */
/*   Updated: 2022/06/17 15:53:49 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/* Creates a new image */
t_image	*ft_mlx_image_new(void *mlx_ptr, int width, int height)
{
	t_image	*image;

	image = calloc(1, sizeof(t_image));
	if (image != NULL)
	{
		image->mlx_ptr = mlx_ptr;
		image->img_ptr = mlx_new_image(mlx_ptr, width, height);
		image->data = mlx_get_data_addr(image->img_ptr, &image->bpp, \
		&image->size_line, &image->endian);
		image->width = width;
		image->height = height;
	}
	return (image);
}

/* Free the memory associated with an image. */
void	ft_mlx_image_del(t_image *image)
{
	mlx_destroy_image(image->mlx_ptr, image->img_ptr);
	free(image);
}

void	ft_mlx_image_put(t_image *image, t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(image->mlx_ptr, mlx->win_ptr, image->img_ptr, x, y);
	mlx->image = image;
}
