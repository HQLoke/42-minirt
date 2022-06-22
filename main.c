/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/06/22 17:27:24 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>

/* Run minilibx */
int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	errno = 0;
	if (argc != 2)
		ft_perror("Usage: ./minirt [scene file in format *.rt]", EINVAL);
	mlx = ft_mlx_new(400, 300);
	mlx->cam = ft_parse_scene(argv[1], &mlx->ambient, &mlx->lights, &mlx->objs);
	ft_mlx_init(mlx);
	mlx->image = ft_mlx_image_new(mlx->mlx_ptr, 1920, 1080);
	mlx_hook(mlx->win_ptr, 17, 17, ft_mlx_del, mlx);
	mlx_key_hook(mlx->win_ptr, ft_mlx_key, mlx);
	ft_display_update(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
