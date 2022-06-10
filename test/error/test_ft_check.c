/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:22:21 by weng              #+#    #+#             */
/*   Updated: 2022/06/10 17:28:29 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	test_open_scene(void)
{
	int	fd;

	fd = ft_open_scene("../scenes/simple.rt");
	printf("ft_open_scene: OK\n");
	close(fd);
}

void	test_split_scene(void)
{
	char **arr;

	arr = ft_split_scene("a\t\tb\tc\t\t");
	if (ft_array_size(arr) != 5)
		printf("ft_split_scene: Error!\n");
	else
		printf("ft_split_scene: OK\n");
	ft_array_del(arr, free);
}

int	main(void)
{
	test_open_scene();
	test_split_scene();
	return (0);
}
