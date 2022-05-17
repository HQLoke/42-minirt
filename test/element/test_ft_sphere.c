/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:14:10 by weng              #+#    #+#             */
/*   Updated: 2022/05/17 15:59:38 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

void	test_new(void)
{
	t_obj	*sphere;
	t_mat	*identity;

	sphere = ft_sphere_new(
			ft_vec_new(4, 1.0, 2.0, 3.0, 1.0),
			ft_vec_new(1, 5.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
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
	t_vec	point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	sphere = ft_sphere_new(ft_vec_new(4, 4.0, 0.0, 0.0, 1.0),
			ft_vec_new(1, 1.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	ray = ft_ray_new(ft_vec_new(4, 2.0, 2.0, 0.0, 1.0),
			ft_vec_new(4, 1.0, -1.0, 0.0, 0.0));
	ft_sphere_intersect(sphere, ray, &point, &norm);
	target_p = ft_vec_new(4, 4 - pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 1.0);
	target_n = ft_vec_new(4, -pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	if (eq_vec(&point, target_p) == 0 || eq_vec(&norm, target_n) == 0)
		printf("ft_sphere_intersect: Error!\n");
	else
		printf("ft_sphere_intersect: OK\n");
	ft_obj_del(sphere);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	free(point.data);
	free(norm.data);
}

void	test_no_intersect(void)
{
	t_obj	*sphere;
	t_ray	*ray;
	t_vec	point;
	t_vec	norm;

	point.data = NULL;
	norm.data = NULL;
	sphere = ft_sphere_new(ft_vec_new(4, 4.0, 0.0, 0.0, 1.0),
			ft_vec_new(1, 1.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	ray = ft_ray_new(ft_vec_new(4, 2.0, 2.0, 0.0, 1.0),
			ft_vec_new(4, -1.0, 1.0, 0.0, 0.0));
	if (ft_sphere_intersect(sphere, ray, &point, &norm) == 1)
		printf("ft_sphere_intersect no intersect: Error!\n");
	else
		printf("ft_sphere_intersect no intersect: OK\n");
	ft_obj_del(sphere);
	ft_ray_del(ray);
	free(point.data);
	free(norm.data);
}

void	test_normal(void)
{
	t_obj	*sphere;
	t_vec	*point;
	t_vec	*target;
	t_vec	norm;

	sphere = ft_sphere_new(
			ft_vec_new(4, 0.0, 0.0, 0.0, 1.0),
			ft_vec_new(1, 1.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	point = ft_vec_new(4, -pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 1.0);
	target = ft_vec_new(4, -pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	ft_sphere_normal(sphere, point, &norm);
	if (eq_vec(&norm, target) == 0 && eq_double(ft_vec_len(&norm), 1) == 0)
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
