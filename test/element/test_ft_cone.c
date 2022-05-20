/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:40:32 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 15:34:43 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

void	test_new(void)
{
	t_obj	*cone;
	t_mat	*identity;

	cone = ft_cone_new(
			ft_vec4_new(1, 2, 3, 1),
			ft_vec4_new(4, 5, 6, 0),
			10,
			ft_vec3_new(0, 0, 0));
	identity = ft_mat_identity(4);
	ft_mat_mul(cone->fr_world, cone->to_world);
	if (eq_mat(identity, cone->fr_world) == 0 || cone->type != CONE)
		printf("ft_cone_new: Error!\n");
	else
		printf("ft_cone_new: OK\n");
	ft_obj_del(cone);
	ft_mat_del(identity);
}

void	test_intersect(void)
{
	t_obj	*cone;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	point = ft_vec_new(4);
	norm.data = NULL;
	cone = ft_cone_new(ft_vec4_new(8, 0, 0, 1),
			ft_vec4_new(0, 0, 1, 0),
			100,
			ft_vec3_new(0, 0, 0));
	ray = ft_ray_new(ft_vec4_new(4, 4, 2, 1),
			ft_vec4_new(1, -1, 0, 0));
	cone->intersect(cone, ray, point, &norm);
	target_p = ft_vec4_new(8 - pow(2, 0.5), pow(2, 0.5), 2, 1.0);
	target_n = ft_vec4_new(-pow(2, 0.5), pow(2, 0.5), -2, 0.0);
	target_n = ft_vec_normalise(target_n);
	if (eq_vec(point, target_p) == 0 || eq_vec(&norm, target_n) == 0)
		printf("ft_cone_intersect: Error!\n");
	else
		printf("ft_cone_intersect: OK\n");
	ft_obj_del(cone);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	ft_vec_del(point);
	free(norm.data);
}

void	test_no_intersect(void)
{
	t_obj	*cone;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;

	point = ft_vec_new(4);
	norm.data = NULL;
	cone = ft_cone_new(ft_vec4_new(4, 0, 0, 1),
			ft_vec4_new(0, 0, 1, 0),
			100,
			ft_vec3_new(0, 0, 0));
	ray = ft_ray_new(ft_vec4_new(2, 2, 0, 1),
			ft_vec4_new(-1, 1, 0, 0));
	if (cone->intersect(cone, ray, point, &norm) == 1)
		printf("ft_cone_intersect no intersect: Error!\n");
	else
		printf("ft_cone_intersect no intersect: OK\n");
	ft_obj_del(cone);
	ft_ray_del(ray);
	ft_vec_del(point);
	free(norm.data);
}

void	test_normal(void)
{
	t_obj	*cone;
	t_vec	*point;
	t_vec	*target;
	t_vec	norm;

	norm.data = NULL;
	cone = ft_cone_new(
			ft_vec4_new(0, 0, 0, 1),
			ft_vec4_new(0, 0, 1, 0),
			100,
			ft_vec3_new(0, 0, 0));
	point = ft_vec4_new(-pow(2, 0.5), pow(2, 0.5), 2, 1.0);
	target = ft_vec4_new(-pow(2, 0.5), pow(2, 0.5), -2, 0.0);
	target = ft_vec_normalise(target);
	cone->normal(cone, NULL, point, &norm);
	if (eq_vec(&norm, target) == 0 || eq_double(ft_vec_len(&norm), 1) == 0)
		printf("ft_cone_normal: Error!\n");
	else
		printf("ft_cone_normal: OK\n");
	ft_obj_del(cone);
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
