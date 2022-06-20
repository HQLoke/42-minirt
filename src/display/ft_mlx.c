/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:46:48 by hloke             #+#    #+#             */
/*   Updated: 2022/06/16 15:48:58 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_mlx	*ft_mlx_new(int width, int height)
{
	t_mlx	*mlx;

	mlx = calloc(1, sizeof(t_mlx));
	if (mlx != NULL)
	{
		mlx->width = width;
		mlx->height = height;
		mlx->mlx_ptr = mlx_init();
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, "MINIRT");
		mlx->ambient = NULL;
		mlx->lights = NULL;
		mlx->objs = NULL;
		mlx->cam = NULL;
		mlx->image = NULL;
	}
	return (mlx);
}

int	ft_mlx_del(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	printf("Minirt is exiting.\n");
	system("leaks minirt");
	exit (EXIT_SUCCESS);
	return (0);
}