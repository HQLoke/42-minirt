/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:55:51 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 11:15:46 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "element.h"
# include "image.h"
# include "minirt.h"
# include "mlx.h"
# include "parse.h"

/* 
 * MAC version
 * Keycodes for esc, qwerty keyboard, arrow keys and number pads 
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
	right = 124,
	one = 18,
	two = 19,
	three = 20,
	four = 21,
	five = 23,
	six = 22,
	seven = 26,
	eight = 28,
	nine = 25
};

/* structure for minilibx image */
typedef struct s_image
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

/* structure for minilibx variables. */
typedef struct s_mlx
{
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	t_light *ambient;
	t_list  *lights;
	t_list  *objs;
	t_cam   *cam;
	t_img8	*img8;
	t_image	*image;
}	t_mlx;

//* ft_display.c
void	ft_display_update(t_mlx *mlx);

//* ft_draw.c
void	ft_draw_image(t_mlx *mlx);

//* ft_image.c
t_image	*ft_mlx_image_new(void *mlx_ptr, int width, int height);
void	ft_mlx_image_del(t_image *image);
void	ft_mlx_image_put(t_mlx *mlx, t_image *image, int x, int y);

//* ft_obj_transform.c
void	ft_obj_rotate_x(t_obj *obj, double theta);
void	ft_obj_rotate_y(t_obj *obj, double theta);
void	ft_obj_rotate_z(t_obj *obj, double theta);
void	ft_obj_scale(t_obj *obj, double scale);
void	ft_obj_translate(t_obj *obj, double dx, double dy, double dz);

//* ft_mlx_key.c
int		ft_mlx_key(int keycode, t_mlx *mlx);

//* ft_mlx.c
t_mlx	*ft_mlx_new(int width, int height);
int		ft_mlx_del(t_mlx *mlx);

#endif