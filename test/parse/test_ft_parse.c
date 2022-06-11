/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:20:34 by weng              #+#    #+#             */
/*   Updated: 2022/06/11 14:32:02 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	test_camera(void)
{
	char	**arr;
	t_cam	*cam;

	arr = ft_split("C    0,0,0    0,0,-1    60", ' ');
	cam = ft_parse_camera(arr);
	if (cam == NULL)
		printf("ft_parse_camera: Error!\n");
	else
		printf("ft_parse_camera: OK\n");
	ft_camera_del(cam);
}

int	main(void)
{
	test_camera();
	return (0);
}
