/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:55:51 by hloke             #+#    #+#             */
/*   Updated: 2022/06/15 21:36:40 by hloke            ###   ########.fr       */
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

/*
 * Keycodes for qwerty keyboard and movement pad
 */
enum e_keycode
{
	esc = 53,
	q = 12,
	w = 13,
	e = 14,
	r = 15,
	t = 17,
	y = 16,
	u = 32,
	i = 34,
	o = 31,
	p = 35,
	a = 0,
	s = 1,
	d = 2,
	f = 3,
	g = 5,
	h = 4,
	j = 38,
	k = 40,
	l = 37,
	z = 6,
	x = 7,
	c = 8,
	v = 9,
	b = 11,
	n = 45,
	m = 46,
	up = 126,
	down = 125,
	left = 123,
	right = 124
};

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img8	*img8;
}	t_window;

//* ft_draw.c
void	ft_draw_img8(t_window *window, t_img8 *img);
void	ft_draw_colored_screen(t_window *window, t_img8 *img, int color);

//* ft_key.c
int		ft_key(int keycode, t_window *window);

//* ft_loop.c
int		ft_loop(t_window *window);

//* ft_window.c
void	ft_window_start(t_window *window);
int		ft_window_end(t_window *window);
void	ft_window_run(t_window *window);

#endif