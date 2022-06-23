/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:22:27 by hloke             #+#    #+#             */
/*   Updated: 2022/06/23 22:43:48 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/* 
 * Display string at coordinates (10, 20).
 * Coordinates are not included in the argument for simplication.
 */
void	ft_display_string(t_mlx *mlx, int color, const char *str)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 20, color, (char *) str);
}

void	ft_display_update(t_mlx *mlx)
{
	t_img	*img;

	if (mlx->obj_o == NULL)
		mlx->obj_o = mlx->objs;
	if (mlx->light_o == NULL)
		mlx->light_o = mlx->lights;
	img = ft_render(mlx->cam, mlx->ambient, mlx->lights, mlx->objs);
	ft_image8_del(mlx->img8);
	mlx->img8 = ft_image_2_image8(img);
	ft_image_del(img);
	ft_draw_image(mlx);
	ft_mlx_image_put(mlx, mlx->image, 0, 0);
	if (mlx->select == CAMERA)
		ft_display_string(mlx, 0xFFFFFF, "Camera");
	else if (mlx->select == LIGHT)
		ft_display_string(mlx, 0xFFFFFF, "Light");
	else if (mlx->select == OBJECT)
		ft_display_string(mlx, 0xFFFFFF, "Object");
}
