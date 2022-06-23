/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/23 16:58:05 by weng             ###   ########.fr       */
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
	const int	keys[] = {
		MAC_W, MAC_S, MAC_A, MAC_D, MAC_E, MAC_Q,
		WIN_W, WIN_S, WIN_A, WIN_D, WIN_E, WIN_Q};
	static void	(*cam_func[])(t_cam *, double) = {
		ft_cam_rotate_x, ft_cam_rotate_y, ft_cam_rotate_z};
	static void	(*obj_func[])(t_obj *, double) = {
		ft_obj_rotate_x, ft_obj_rotate_y, ft_obj_rotate_z};
	int			i;

	i = -1;
	while (++i < 6)
	{
		if (keycode == keys[i] || keycode == keys[i + 6])
		{
			if (mlx->select == CAMERA)
				cam_func[i / 2](mlx->cam, (-1 + (i % 2) * 2) * M_PI / 36);
			else if (mlx->select == OBJECT)
				obj_func[i / 2](mlx->current_obj->content,
					(-1 + (i % 2) * 2) * M_PI / 36);
		}
	}
	ft_display_update(mlx);
}

/*
 * Command keys for translation:
 * T: Move along +ve y
 * G: Move along -ve y
 * F: Move along -ve x
 * H: Move along +ve x
 * R: Move along +ve z
 * Y: Move along -ve z
 */
static void	ft_mlx_key_translate(int keycode, t_mlx *mlx)
{
	const int	keys[] = {
		MAC_F, MAC_H, MAC_G, MAC_T, MAC_Y, MAC_R,
		WIN_F, WIN_H, WIN_G, WIN_T, WIN_Y, WIN_R};
	int			i;

	i = -1;
	while (++i < 6)
	{
		if (keycode == keys[i] || keycode == keys[i + 6])
		{
			if (mlx->select == CAMERA)
				ft_cam_translate(mlx->cam,
					-(i % 6 == 0) + (i % 6 == 1),
					-(i % 6 == 2) + (i % 6 == 3),
					-(i % 6 == 4) + (i % 6 == 5));
			else if (mlx->select == OBJECT)
				ft_obj_translate(mlx->current_obj->content,
					-(i % 6 == 0) + (i % 6 == 1),
					-(i % 6 == 2) + (i % 6 == 3),
					-(i % 6 == 4) + (i % 6 == 5));
		}
	}
	ft_display_update(mlx);
}

/*
 * Command keys for scaling:
 * N: Zoom out
 * M: Zoom in
 */
static void	ft_mlx_key_scale(int keycode, t_mlx *mlx)
{
	t_obj	*obj;
	t_vec	*dimension;

	obj = mlx->current_obj->content;
	dimension = obj->dimension;
	if (mlx->select != OBJECT || dimension == NULL)
		return ;
	if (keycode == MAC_N || keycode == WIN_N)
		ft_vec_mul_scalar(dimension, 1.1);
	else if (keycode == MAC_M || keycode == WIN_M)
		ft_vec_mul_scalar(dimension, 1.0 / 1.1);
	ft_display_update(mlx);
}

/*
 * Command for element selection
 * C:	Switch to camera mode
 * O:	Switch to object mode
 * Z:	Change to first object
 * X:	Change to next object
 */
static void	ft_elem_selection(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_C || keycode == WIN_C)
		mlx->select = CAMERA;
	else if (keycode == MAC_O || keycode == WIN_O)
		mlx->select = OBJECT;
	else if (keycode == MAC_Z || keycode == WIN_Z)
		mlx->current_obj = mlx->objs;
	else if (keycode == MAC_X || keycode == WIN_X)
	{
		if (mlx->current_obj->next != NULL)
			mlx->current_obj = mlx->current_obj->next;
	}
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
	else if (keycode == MAC_R || keycode == MAC_T || keycode == MAC_Y
		|| keycode == MAC_F || keycode == MAC_G || keycode == MAC_H
		|| keycode == WIN_R || keycode == WIN_T || keycode == WIN_Y
		|| keycode == WIN_F || keycode == WIN_G || keycode == WIN_H)
		ft_mlx_key_translate(keycode, mlx);
	else if (keycode == MAC_N || keycode == MAC_M
		|| keycode == WIN_N || keycode == WIN_M)
		ft_mlx_key_scale(keycode, mlx);
	else if (keycode == MAC_C || keycode == MAC_O || keycode == MAC_Z
		|| keycode == MAC_X || keycode == WIN_C || keycode == WIN_O
		|| keycode == WIN_Z || keycode == WIN_X)
		ft_elem_selection(keycode, mlx);
	return (0);
}
