/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/06/16 15:03:06 by weng             ###   ########.fr       */
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

/* Run minilibx */
void	ft_run(t_cam *cam, t_light *ambient, t_list *lights, t_list *objs)
{
	t_img		*img;
	t_img8		*img8;
	t_window	*window;

	img = ft_render(cam, ambient, lights, objs);
	img8 = ft_image_2_image8(img);
	window = ft_calloc(1, sizeof(t_window));
	window->img8 = img8;
	ft_window_start(window);
	ft_window_run(window);
}

int	main(int argc, char **argv)
{
	t_light		*ambient;
	t_list		*lights;
	t_list		*objs;
	t_cam		*cam;

	if (argc != 2)
		return (teach_them());
	ambient = NULL;
	lights = NULL;
	objs = NULL;
	cam = ft_parse_scene(argv[1], &ambient, &lights, &objs);
	ft_run(cam, ambient, lights, objs);
	return (0);
}
