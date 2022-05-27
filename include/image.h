/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:13:04 by weng              #+#    #+#             */
/*   Updated: 2022/05/27 11:05:28 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "linalg.h"

/* struct for an image */
typedef struct s_img
{
	size_t	row;
	size_t	col;
	double	*data;
}	t_img;

typedef struct s_img8
{
	size_t			row;
	size_t			col;
	unsigned char	*data;
}	t_img8;

// ft_image.c -- image related functions
t_img	*ft_image_new(size_t row, size_t col);
void	ft_image_del(t_img *img);
int		ft_image_set(t_img *img, size_t i, size_t j, t_vec *colour);
t_vec	*ft_image_get(t_img *img, size_t i, size_t j);

// ft_image8.c -- 8 bit image related functions
t_img8	*ft_image8_new(size_t row, size_t col);
void	ft_image8_del(t_img8 *img);
int		ft_image8_set(t_img8 *img, size_t i, size_t j, t_vec *colour);
t_vec	*ft_image8_get(t_img8 *img, size_t i, size_t j);
t_img8	*ft_image_2_image8(t_img *img);

#endif
