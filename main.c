/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/06/15 20:48:26 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include <stdlib.h>

static int	teach_them(void)
{
	printf("Usage: ./minirt [scene file in format *.rt]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (teach_them());

	t_light		*ambient = NULL;
	t_list		*lights = NULL;
	t_list		*objs = NULL;
	t_cam		*cam = NULL;
	cam = ft_parse_scene(argv[1], &ambient, &lights, &objs);
	t_img		*img = NULL;
	img = ft_render(cam, ambient, lights, objs);
	t_img8		*img8 = NULL;
	img8 = ft_image_2_image8(img);
	
	t_window	*window;
	window = ft_calloc(1, sizeof(t_window));
	window->img8 = img8;
	
	ft_window_start(window);
	ft_window_run(window);
	return (0);
}
