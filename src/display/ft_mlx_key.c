/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 11:32:42 by weng             ###   ########.fr       */
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
	if (keycode == w)
		ft_obj_rotate_x(mlx->objs->content, -M_PI / 36);
	else if (keycode == s)
		ft_obj_rotate_x(mlx->objs->content, M_PI / 36);
	else if (keycode == a)
		ft_obj_rotate_y(mlx->objs->content, M_PI / 36);
	else if (keycode == d)
		ft_obj_rotate_y(mlx->objs->content, -M_PI / 36);
	else if (keycode == q)
		ft_obj_rotate_z(mlx->objs->content, M_PI / 36);
	else if (keycode == e)
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
	if (keycode == up)
		ft_obj_translate(mlx->objs->content, 0, -1, 0);
	else if (keycode == down)
		ft_obj_translate(mlx->objs->content, 0, 1, 0);
	else if (keycode == left)
		ft_obj_translate(mlx->objs->content, -1, 0, 0);
	else if (keycode == right)
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
	if (keycode == n)
		ft_obj_scale(mlx->objs->content, 1.1);
	else if (keycode == m)
		ft_obj_scale(mlx->objs->content, 1.0 / 1.1);
	ft_display_update(mlx);
}

int	ft_mlx_key(int keycode, t_mlx *mlx)
{
	if (keycode == esc)
		ft_mlx_del(mlx);
	else if (keycode == q || keycode == w || keycode == e
		|| keycode == a || keycode == s || keycode == d)
		ft_mlx_key_rotate(keycode, mlx);
	else if (keycode == up || keycode == down
		|| keycode == left || keycode == right)
		ft_mlx_key_translate(keycode, mlx);
	else if (keycode == n || keycode == m)
		ft_mlx_key_scale(keycode, mlx);
	return (0);
}
