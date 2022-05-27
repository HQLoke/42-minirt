/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:12:30 by weng              #+#    #+#             */
/*   Updated: 2022/05/27 11:06:04 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

/* Created a new empty image. */
t_img8	*ft_image8_new(size_t row, size_t col)
{
	t_img8	*img;

	if (row == 0 || col == 0)
		return (NULL);
	img = malloc(sizeof(t_img8));
	if (img != NULL)
	{
		img->row = row;
		img->col = col;
		img->data = ft_calloc(row * col * 3, sizeof(unsigned char));
		if (img->data == NULL)
		{
			ft_image8_del(img);
			return (NULL);
		}
	}
	return (img);
}

/* Delete an image */
void	ft_image8_del(t_img8 *img)
{
	if (img == NULL)
		return ;
	free(img->data);
	free(img);
}

/* Update a pixel (i, j) of image 'img' with 'colour'. The component of
 * colour is assume to be within [0, 1].
 */
int	ft_image8_set(t_img8 *img, size_t i, size_t j, t_vec *colour)
{
	size_t	k;

	if (i >= img->row || j >= img->col)
		return (0);
	k = -1;
	while (++k < 3)
	{
		img->data[(i * img->col + j) * 3 + k]
			= (int)(colour->data[k] * 255.9999);
	}
	return (1);
}

/* Return the pixel (i, j) of image 'img' as a vector. The component of
 * colour will be in the range [0, 1] */
t_vec	*ft_image8_get(t_img8 *img, size_t i, size_t j)
{
	t_vec	*vec;
	size_t	k;

	if (i >= img->row || j >= img->col)
		return (NULL);
	vec = ft_vec3_new(0, 0, 0);
	k = -1;
	while (++k < 3)
		vec->data[k] = img->data[(i * img->col + j) * 3 + k] / 255.999;
	return (vec);
}

/* Convert a double precision image to an 8 bit image. */
t_img8	*ft_image_2_image8(t_img *img)
{
	t_img8	*retval;
	size_t	i;

	retval = ft_image8_new(img->row, img->col);
	i = img->row * img->col * 3;
	while (i-- > 0)
		retval->data[i] = (int)(img->data[i] * 255.9999);
	return (retval);
}
