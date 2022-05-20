/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:14:10 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 14:08:00 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

void	test_new(void)
{
	t_obj	*sphere;
	t_mat	*identity;

	sphere = ft_sphere_new(ft_vec4_new(1, 2, 3, 1), 5, ft_vec3_new(0, 0, 0));
	identity = ft_mat_identity(4);
	ft_mat_mul(sphere->fr_world, sphere->to_world);
	if (eq_mat(identity, sphere->fr_world) == 0)
		printf("ft_sphere_new: Error!\n");
	else
		printf("ft_sphere_new: OK\n");
	ft_obj_del(sphere);
	ft_mat_del(identity);
}

void	test_intersect(void)
{
	t_obj	*sphere;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	point = ft_vec_new(4);
	norm.data = NULL;
	sphere = ft_sphere_new(ft_vec4_new(8, 0, 0, 1), 2, ft_vec3_new(0, 0, 0));
	ray = ft_ray_new(ft_vec4_new(4, 4, 0, 1), ft_vec4_new(1, -1, 0, 0));
	sphere->intersect(sphere, ray, point, &norm);
	target_p = ft_vec4_new(8 - pow(2, 0.5), pow(2, 0.5), 0.0, 1.0);
	target_n = ft_vec4_new(-pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	if (eq_vec(point, target_p) == 0 || eq_vec(&norm, target_n) == 0)
		printf("ft_sphere_intersect: Error!\n");
	else
		printf("ft_sphere_intersect: OK\n");
	ft_obj_del(sphere);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	ft_vec_del(point);
	free(norm.data);
}

void	test_no_intersect(void)
{
	t_obj	*sphere;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;

	point = ft_vec_new(4);
	norm.data = NULL;
	sphere = ft_sphere_new(ft_vec4_new(4, 0, 0, 1), 1, ft_vec3_new(0, 0, 0));
	ray = ft_ray_new(ft_vec4_new(2, 2, 0, 1), ft_vec4_new(-1, 1, 0, 0));
	if (sphere->intersect(sphere, ray, point, &norm) == 1)
		printf("ft_sphere_intersect no intersect: Error!\n");
	else
		printf("ft_sphere_intersect no intersect: OK\n");
	ft_obj_del(sphere);
	ft_ray_del(ray);
	ft_vec_del(point);
	free(norm.data);
}

void	test_normal(void)
{
	t_obj	*sphere;
	t_vec	*point;
	t_vec	*target;
	t_vec	norm;

	norm.data = NULL;
	sphere = ft_sphere_new(ft_vec4_new(0, 0, 0, 1), 2, ft_vec3_new(0, 0, 0));
	point = ft_vec4_new(-pow(2, 0.5), pow(2, 0.5), 0.0, 1.0);
	target = ft_vec4_new(-pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	sphere->normal(sphere, NULL, point, &norm);
	if (eq_vec(&norm, target) == 0 || eq_double(ft_vec_len(&norm), 1) == 0)
		printf("ft_sphere_normal: Error!\n");
	else
		printf("ft_sphere_normal: OK\n");
	ft_obj_del(sphere);
	ft_vec_del(point);
	ft_vec_del(target);
	free(norm.data);
}

int	main(void)
{
	test_new();
	test_intersect();
	test_no_intersect();
	test_normal();
	return (0);
}
