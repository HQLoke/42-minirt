/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/23 11:35:37 by hloke            ###   ########.fr       */
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
	if ((keycode == MAC_W || keycode == WIN_W) && mlx->select == OBJECT)
		ft_obj_rotate_x(mlx->current_obj->content, -M_PI / 36);
	else if ((keycode == MAC_W || keycode == WIN_W) && mlx->select == CAMERA)
		ft_cam_rotate_x(mlx->cam, M_PI / 36);
	else if ((keycode == MAC_S || keycode == WIN_S) && mlx->select == OBJECT)
		ft_obj_rotate_x(mlx->current_obj->content, M_PI / 36);
	else if ((keycode == MAC_S || keycode == WIN_S) && mlx->select == CAMERA)
		ft_cam_rotate_x(mlx->cam, -M_PI / 36);
	else if ((keycode == MAC_A || keycode == WIN_A) && mlx->select == OBJECT)
		ft_obj_rotate_y(mlx->current_obj->content, -M_PI / 36);
	else if ((keycode == MAC_A || keycode == WIN_A) && mlx->select == CAMERA)
		ft_cam_rotate_y(mlx->cam, M_PI / 36);
	else if ((keycode == MAC_D || keycode == WIN_D) && mlx->select == OBJECT)
		ft_obj_rotate_y(mlx->current_obj->content, M_PI / 36);
	else if ((keycode == MAC_D || keycode == WIN_D) && mlx->select == CAMERA)
		ft_cam_rotate_y(mlx->cam, -M_PI / 36);
	else if ((keycode == MAC_Q || keycode == WIN_Q) && mlx->select == OBJECT)
		ft_obj_rotate_z(mlx->current_obj->content, M_PI / 36);
	else if ((keycode == MAC_Q || keycode == WIN_Q) && mlx->select == CAMERA)
		ft_cam_rotate_z(mlx->cam, -M_PI / 36);
	else if ((keycode == MAC_E || keycode == WIN_E) && mlx->select == OBJECT)
		ft_obj_rotate_z(mlx->current_obj->content, -M_PI / 36);
	else if ((keycode == MAC_E || keycode == WIN_E) && mlx->select == CAMERA)
		ft_cam_rotate_z(mlx->cam, M_PI / 36);
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
	if ((keycode == MAC_T || keycode == WIN_T) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, 0, 1, 0);
	else if ((keycode == MAC_T || keycode == WIN_T) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, 0, 1, 0);
	else if ((keycode == MAC_G || keycode == WIN_G) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, 0, -1, 0);
	else if ((keycode == MAC_G || keycode == WIN_G) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, 0, -1, 0);
	else if ((keycode == MAC_F || keycode == WIN_F) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, -1, 0, 0);
	else if ((keycode == MAC_F || keycode == WIN_F) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, -1, 0, 0);
	else if ((keycode == MAC_H || keycode == WIN_H) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, 1, 0, 0);
	else if ((keycode == MAC_H || keycode == WIN_H) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, 1, 0, 0);
	else if ((keycode == MAC_R || keycode == WIN_R) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, 0, 0, 1);
	else if ((keycode == MAC_R || keycode == WIN_R) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, 0, 0, 1);
	else if ((keycode == MAC_Y || keycode == WIN_Y) && mlx->select == OBJECT)
		ft_obj_translate(mlx->current_obj->content, 0, 0, -1);
	else if ((keycode == MAC_Y || keycode == WIN_Y) && mlx->select == CAMERA)
		ft_cam_translate(mlx->cam, 0, 0, -1);
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
	else if (keycode == MAC_C || keycode == MAC_O || keycode == MAC_Z
		|| keycode == MAC_X || keycode == WIN_C || keycode == WIN_O
		|| keycode == WIN_Z || keycode == WIN_X)
		ft_elem_selection(keycode, mlx);
	return (0);
}
