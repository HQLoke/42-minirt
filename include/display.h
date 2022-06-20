/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:55:51 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 15:41:50 by hloke            ###   ########.fr       */
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
	MAC_ESC = 53,
	MAC_Q = 12,
	MAC_W = 13,
	MAC_E = 14,
	MAC_R = 15,
	MAC_T = 17,
	MAC_Y = 16,
	MAC_U = 32,
	MAC_I = 34,
	MAC_O = 31,
	MAC_P = 35,
	MAC_A = 0,
	MAC_S = 1,
	MAC_D = 2,
	MAC_F = 3,
	MAC_G = 5,
	MAC_H = 4,
	MAC_J = 38,
	MAC_K = 40,
	MAC_L = 37,
	MAC_Z = 6,
	MAC_X = 7,
	MAC_C = 8,
	MAC_V = 9,
	MAC_B = 11,
	MAC_N = 45,
	MAC_M = 46,
	MAC_UP = 126,
	MAC_DOWN = 125,
	MAC_LEFT = 123,
	MAC_RIGHT = 124,
	MAC_ONE = 18,
	MAC_TWO = 19,
	MAC_THREE = 20,
	MAC_FOUR = 21,
	MAC_FIVE = 23,
	MAC_SIX = 22,
	MAC_SEVEN = 26,
	MAC_EIGHT = 28,
	MAC_NINE = 25
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
	t_light	*ambient;
	t_list	*lights;
	t_list	*objs;
	t_cam	*cam;
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
