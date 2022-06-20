/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:22:27 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 13:32:13 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_display_update(t_mlx *mlx)
{
	t_img	*img;

	img = ft_render(mlx->cam, mlx->ambient, mlx->lights, mlx->objs);
	ft_image8_del(mlx->img8);
	mlx->img8 = ft_image_2_image8(img);
	ft_image_del(img);
	ft_draw_image(mlx);
	ft_mlx_image_put(mlx, mlx->image, 0, 0);
}
