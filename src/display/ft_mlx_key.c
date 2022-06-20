/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 13:05:00 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/*
 * Command keys for rotation:
 * W: Clockwise around x-axis
 * S: Counter-clockwise around x-axis
 * A: Clockwise around y-axis
 * D: Counter-clockwise around y-axis
 * Q: Clockwise around z-axis
 * E: Counter-clockwise around z-axis
 */
static void	ft_mlx_key_rotate(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_W)
		ft_obj_rotate_x(mlx->objs->content, -M_PI / 36);
	else if (keycode == MAC_S)
		ft_obj_rotate_x(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_A)
		ft_obj_rotate_y(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_D)
		ft_obj_rotate_y(mlx->objs->content, -M_PI / 36);
	else if (keycode == MAC_Q)
		ft_obj_rotate_z(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_E)
		ft_obj_rotate_z(mlx->objs->content, -M_PI / 36);
	ft_display_update(mlx);
}

/*
 * Command keys for translation:
 *    Up: Move up   
 *  Down: Move down
 *  Left: Move left
 * Right: Move right
 */
static void	ft_mlx_key_translate(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_UP)
		ft_obj_translate(mlx->objs->content, 0, -1, 0);
	else if (keycode == MAC_DOWN)
		ft_obj_translate(mlx->objs->content, 0, 1, 0);
	else if (keycode == MAC_LEFT)
		ft_obj_translate(mlx->objs->content, -1, 0, 0);
	else if (keycode == MAC_RIGHT)
		ft_obj_translate(mlx->objs->content, 1, 0, 0);
	ft_display_update(mlx);
}

/*
 * Command keys for scaling:
 * N: Zoom out
 * M: Zoom in
 */
static void	ft_mlx_key_scale(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_N)
		ft_obj_scale(mlx->objs->content, 1.1);
	else if (keycode == MAC_M)
		ft_obj_scale(mlx->objs->content, 1.0 / 1.1);
	ft_display_update(mlx);
}

int	ft_mlx_key(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_ESC)
		ft_mlx_del(mlx);
	else if (keycode == MAC_Q || keycode == MAC_W || keycode == MAC_E
		|| keycode == MAC_A || keycode == MAC_S || keycode == MAC_D)
		ft_mlx_key_rotate(keycode, mlx);
	else if (keycode == MAC_UP || keycode == MAC_DOWN
		|| keycode == MAC_LEFT || keycode == MAC_RIGHT)
		ft_mlx_key_translate(keycode, mlx);
	else if (keycode == MAC_N || keycode == MAC_M)
		ft_mlx_key_scale(keycode, mlx);
	return (0);
}
