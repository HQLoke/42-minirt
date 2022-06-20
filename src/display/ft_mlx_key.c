/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 15:35:56 by weng             ###   ########.fr       */
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
	if (keycode == MAC_W || keycode == WIN_W)
		ft_obj_rotate_x(mlx->objs->content, -M_PI / 36);
	else if (keycode == MAC_S || keycode == WIN_S)
		ft_obj_rotate_x(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_A || keycode == WIN_A)
		ft_obj_rotate_y(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_D || keycode == WIN_D)
		ft_obj_rotate_y(mlx->objs->content, -M_PI / 36);
	else if (keycode == MAC_Q || keycode == WIN_Q)
		ft_obj_rotate_z(mlx->objs->content, M_PI / 36);
	else if (keycode == MAC_E || keycode == WIN_E)
		ft_obj_rotate_z(mlx->objs->content, -M_PI / 36);
	ft_display_update(mlx);
}

/*
 * Command keys for translation:
 * Up:			Move along +ve y
 * Down:		Move along -ve y
 * Left:		Move along -ve x
 * Right:		Move along +ve x
 * PageUp:		Move along +ve z
 * PageDown:	Move along -ve z
 */
static void	ft_mlx_key_translate(int keycode, t_mlx *mlx)
{
	if (keycode == WIN_PAGEUP)
		ft_obj_translate(mlx->objs->content, 0, 0, 1);
	else if (keycode == WIN_PAGEDOWN)
		ft_obj_translate(mlx->objs->content, 0, 0, -1);
	else if (keycode == MAC_UP || keycode == WIN_UP)
		ft_obj_translate(mlx->objs->content, 0, 1, 0);
	else if (keycode == MAC_DOWN || keycode == WIN_DOWN)
		ft_obj_translate(mlx->objs->content, 0, -1, 0);
	else if (keycode == MAC_LEFT || keycode == WIN_LEFT)
		ft_obj_translate(mlx->objs->content, -1, 0, 0);
	else if (keycode == MAC_RIGHT || keycode == WIN_RIGHT)
		ft_obj_translate(mlx->objs->content, 1, 0, 0);
	ft_display_update(mlx);
}

/*
 * Command keys for camera rotation:
 * T: Clockwise around x-axis
 * G: Counter-clockwise around x-axis
 * F: Clockwise around y-axis
 * H: Counter-clockwise around y-axis
 * R: Clockwise around z-axis
 * Y: Counter-clockwise around z-axis
 */
static void	ft_mlx_cam_rotate(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_T || keycode == WIN_T)
		ft_cam_rotate_x(mlx->cam, M_PI / 36);
	else if (keycode == MAC_G || keycode == WIN_G)
		ft_cam_rotate_x(mlx->cam, -M_PI / 36);
	else if (keycode == MAC_F || keycode == WIN_F)
		ft_cam_rotate_y(mlx->cam, M_PI / 36);
	else if (keycode == MAC_H || keycode == WIN_H)
		ft_cam_rotate_y(mlx->cam, -M_PI / 36);
	else if (keycode == MAC_R || keycode == WIN_R)
		ft_cam_rotate_z(mlx->cam, -M_PI / 36);
	else if (keycode == MAC_Y || keycode == WIN_Y)
		ft_cam_rotate_z(mlx->cam, M_PI / 36);
	ft_display_update(mlx);
}

/*
 * Command keys for translation:
 * I:	Move along +ve y
 * K:	Move along -ve y
 * J:	Move along -ve x
 * L:	Move along +ve x
 * U:	Move along +ve z
 * O:	Move along -ve z
 */
static void	ft_mlx_cam_translate(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_U || keycode == WIN_U)
		ft_cam_translate(mlx->cam, 0, 0, 1);
	else if (keycode == MAC_O || keycode == WIN_O)
		ft_cam_translate(mlx->cam, 0, 0, -1);
	else if (keycode == MAC_I || keycode == WIN_I)
		ft_cam_translate(mlx->cam, 0, 1, 0);
	else if (keycode == MAC_K || keycode == WIN_K)
		ft_cam_translate(mlx->cam, 0, -1, 0);
	else if (keycode == MAC_J || keycode == WIN_J)
		ft_cam_translate(mlx->cam, -1, 0, 0);
	else if (keycode == MAC_L || keycode == WIN_L)
		ft_cam_translate(mlx->cam, 1, 0, 0);
	ft_display_update(mlx);
}

int	ft_mlx_key(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_ESC || keycode == WIN_ESC)
		ft_mlx_del(mlx);
	else if (keycode == MAC_Q || keycode == MAC_W || keycode == MAC_E
		|| keycode == MAC_A || keycode == MAC_S || keycode == MAC_D
		|| keycode == WIN_Q || keycode == WIN_W || keycode == WIN_E
		|| keycode == WIN_A || keycode == WIN_S || keycode == WIN_D)
		ft_mlx_key_rotate(keycode, mlx);
	else if (keycode == MAC_UP || keycode == MAC_DOWN
		|| keycode == MAC_LEFT || keycode == MAC_RIGHT
		|| keycode == WIN_PAGEUP || keycode == WIN_PAGEDOWN
		|| keycode == WIN_UP || keycode == WIN_DOWN
		|| keycode == WIN_LEFT || keycode == WIN_RIGHT)
		ft_mlx_key_translate(keycode, mlx);
	else if (keycode == MAC_R || keycode == MAC_T || keycode == MAC_Y
		|| keycode == MAC_F || keycode == MAC_G || keycode == MAC_H
		|| keycode == WIN_R || keycode == WIN_T || keycode == WIN_Y
		|| keycode == WIN_F || keycode == WIN_G || keycode == WIN_H)
		ft_mlx_cam_rotate(keycode, mlx);
	else if (keycode == MAC_U || keycode == MAC_I || keycode == MAC_O
		|| keycode == MAC_J || keycode == MAC_K || keycode == MAC_L
		|| keycode == WIN_U || keycode == WIN_I || keycode == WIN_O
		|| keycode == WIN_J || keycode == WIN_K || keycode == WIN_L)
		ft_mlx_cam_translate(keycode, mlx);
	return (0);
}
