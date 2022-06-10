/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:22:21 by weng              #+#    #+#             */
/*   Updated: 2022/06/10 16:46:34 by weng             ###   ########.fr       */
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

int	main(void)
{
	test_open_scene();
	return (0);
}
