/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ppm_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:31:43 by weng              #+#    #+#             */
/*   Updated: 2022/05/28 22:32:14 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	test_image8_2_ppm6(void)
{
	t_img8	*img;

	img = ft_image8_new(100, 200);
	ft_memset(img->data, 255, img->row * img->col * 3);
	if (ft_image8_2_ppm6(img, "test_p6.ppm") == 0)
		printf("ft_image8_2_ppm6: Error!\n");
	else
		printf("ft_image8_2_ppm6: OK\n");
	ft_image8_del(img);
}

int	main(void)
{
	test_image8_2_ppm6();
	return (0);
}
