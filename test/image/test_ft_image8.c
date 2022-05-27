/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_image8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:40:34 by weng              #+#    #+#             */
/*   Updated: 2022/05/27 11:06:04 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	test_new(void)
{
	t_img8	*img;
	size_t	i;
	int		retval;

	retval = 1;
	img = ft_image8_new(10, 20);
	if (img->row != 10 || img->col != 20)
		retval = 0;
	i = -1;
	while (++i < img->row * img->col * 3)
	{
		if (img->data[i] != 0)
		{
			retval = 0;
			break ;
		}
	}
	if (retval != 1)
		printf("ft_image8_new: Error!\n");
	else
		printf("ft_image8_new: OK\n");
	ft_image8_del(img);
}

void	test_set(void)
{
	t_img8	*img;
	t_vec	*colour;
	size_t	i;
	size_t	j;
	int		retval;

	i = 1;
	j = 2;
	img = ft_image8_new(10, 20);
	colour = ft_vec3_new(0, 0.5, 1);
	retval = ft_image8_set(img, i, j, colour);
	if (retval == 0
		|| img->data[(i * img->col + j) * 3 + 0] != 0
		|| img->data[(i * img->col + j) * 3 + 1] != 127
		|| img->data[(i * img->col + j) * 3 + 2] != 255)
		printf("ft_image8_set: Error!\n");
	else
		printf("ft_image8_set: OK\n");
	ft_image8_del(img);
	ft_vec_del(colour);
}

void	test_get(void)
{
	t_img8	*img;
	t_vec	*colour;
	t_vec	*output;
	size_t	i;
	size_t	j;

	i = 1;
	j = 2;
	img = ft_image8_new(10, 20);
	colour = ft_vec3_new(1, 2, 3);
	ft_image8_set(img, i, j, colour);
	output = ft_image8_get(img, i, j);
	if (fabs(colour->data[0] - output->data[0]) > 0.003
		|| fabs(colour->data[1] - output->data[1]) > 0.003
		|| fabs(colour->data[2] - output->data[2]) > 0.003)
		printf("ft_image8_get: Error!\n");
	else
		printf("ft_image8_get: OK\n");
	ft_image8_del(img);
	ft_vec_del(colour);
	ft_vec_del(output);
}

void	test_convert(void)
{
	t_img	*img;
	t_img8	*img_bit;		
	t_vec	*colour;
	size_t	i;
	size_t	j;

	i = 1;
	j = 2;
	img = ft_image_new(10, 20);
	colour = ft_vec3_new(0, 0.5, 1);
	ft_image_set(img, i, j, colour);
	img_bit = ft_image_2_image8(img);
	if (img_bit->data[(i * img_bit->col + j) * 3 + 0] != 0
		|| img_bit->data[(i * img_bit->col + j) * 3 + 1] != 127
		|| img_bit->data[(i * img_bit->col + j) * 3 + 2] != 255)
		printf("ft_image_2_image8: Error!\n");
	else
		printf("ft_image_2_image8: OK\n");
	ft_image_del(img);
	ft_image8_del(img_bit);
	ft_vec_del(colour);
}

int	main(void)
{
	test_new();
	test_set();
	test_convert();
	return (0);
}
