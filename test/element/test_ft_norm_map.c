/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_norm_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:27:02 by weng              #+#    #+#             */
/*   Updated: 2022/06/08 16:46:57 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_sphere(void)
{
	t_cam	*cam;
	t_light	*ambient;
	t_light	*light;
	t_list	*lights;
	t_obj	*sphere;
	t_list	*objs;
	t_opt	opt;
	t_img	*img;

	cam = ft_camera_new(
			ft_vec4_new(0, 0, 5, 1), ft_vec4_new(0, 0, 1, 0), 70);
	ambient = ft_ambient_new(0.1, ft_vec3_new(1, 1, 1));
	lights = NULL;
	light = ft_point_new(ft_vec4_new(5, 0, 5, 1), .8, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&lights, ft_lstnew(light, 0));
	objs = NULL;
	opt.colour = ft_vec3_new(0.9, 0.9, 0.9);
	opt.disruption = 0;
	opt.norm_map = "../map/golfball.ppm";
	sphere = ft_sphere_new(ft_vec4_new(0, 0, 0, 1), 1, &opt);
	ft_lstadd_back(&objs, ft_lstnew(sphere, 0));
	img = ft_render(cam, ambient, lights, objs);
	if (ft_image_2_ppm(img, "test_sphere_norm_map.ppm", 6) == 0)
		printf("ft_sphere_norm_map: Error!\n");
	else
		printf("ft_sphere_norm_map: OK\n");
	ft_camera_del(cam);
	ft_light_del(ambient);
	ft_lstclear(&lights, (void (*)(void *)) ft_light_del);
	ft_lstclear(&objs, (void (*)(void *)) ft_obj_del);
	ft_image_del(img);
}

int	main(void)
{
	test_sphere();
	return (0);
}
