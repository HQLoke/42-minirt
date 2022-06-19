/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:13:30 by hloke             #+#    #+#             */
/*   Updated: 2022/06/17 15:54:27 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	ft_mlx_key(int keycode, t_mlx *mlx)
{
	if (keycode == w)
	{	
		t_light *holder = mlx->lights->content;
		holder->centre->data[0] += 1;
		holder->centre->data[1] += 1;
		holder->centre->data[2] += 1;

		t_img		*img = NULL;
		img = ft_render(mlx->cam, mlx->ambient, mlx->lights, \
		mlx->objs);
		t_img8		*img8 = NULL;
		img8 = ft_image_2_image8(img);
	}
	else if (keycode == s)
	{

	}
	else if (keycode == a)
	{

	}
	else if (keycode == d)
	{
		
	}



	if (keycode == esc)
		ft_mlx_del(mlx);
	return (0);
}
