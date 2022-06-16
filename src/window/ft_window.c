/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:46:48 by hloke             #+#    #+#             */
/*   Updated: 2022/06/15 13:49:06 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	ft_window_start(t_window *window)
{
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, window->img8->col, \
	window->img8->row, "minirt");
}

int	ft_window_end(t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	printf("Minirt is exiting.\n");
	exit (EXIT_SUCCESS);
	return (0);
}

void	ft_window_run(t_window *window)
{
	mlx_hook(window->mlx_win, 17, 17, ft_window_end, window);
	mlx_key_hook(window->mlx_win, ft_key, window);
	mlx_loop_hook(window->mlx, ft_loop, window);
	mlx_loop(window->mlx);
}
