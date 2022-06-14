/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:55:51 by hloke             #+#    #+#             */
/*   Updated: 2022/06/14 12:51:41 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "image.h"
# include "mlx.h"

enum e_size
{
	width = 400,
	height = 300
};

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img8	*img;
}	t_window;

//* ft_draw.c
int		ft_draw_img8(t_window *window);

//* ft_key.c
int		ft_key(void);

//* ft_update.c

//* ft_window.c
void	ft_window_start(t_window *window);
void	ft_window_run(t_window *window);

#endif