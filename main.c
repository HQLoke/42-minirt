/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/06/19 10:34:02 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>

static int	teach_them(void)
{
	printf("Usage: ./minirt [scene file in format *.rt]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (teach_them());

	t_mlx	*mlx = NULL;
	mlx = ft_mlx_new(400, 300);
	mlx->cam = ft_parse_scene(argv[1], &mlx->ambient, \
	&mlx->lights, &mlx->objs);
	t_img		*img = NULL;
	img = ft_render(mlx->cam, mlx->ambient, mlx->lights, \
	mlx->objs);
	t_img8		*img8 = NULL;
	img8 = ft_image_2_image8(img);
	mlx->img8 = img8;
	mlx->image = ft_mlx_image_new(mlx->mlx_ptr, mlx->width, mlx->height);
	
	ft_draw_image(mlx, mlx->img8);
	mlx_hook(mlx->win_ptr, 17, 17, ft_mlx_del, mlx);
	mlx_key_hook(mlx->win_ptr, ft_mlx_key, mlx);
	ft_mlx_image_put(mlx->image, mlx->mlx_ptr, 0, 0);
	mlx_loop_hook(mlx->mlx_ptr, ft_mlx_loop, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}


