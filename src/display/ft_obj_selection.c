/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:23:11 by hloke             #+#    #+#             */
/*   Updated: 2022/06/21 22:05:02 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_obj_selection(int keycode, t_mlx *mlx)
{
	if (keycode == MAC_Z || keycode == WIN_Z)
		mlx->current_obj = mlx->objs;
	else if (keycode == MAC_X || keycode == WIN_X)
	{
		if (mlx->current_obj->next != NULL)
			mlx->current_obj = mlx->current_obj->next;
	}
}
