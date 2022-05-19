/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:40:32 by weng              #+#    #+#             */
/*   Updated: 2022/05/19 23:30:58 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

void	test_new(void)
{
	t_obj	*cylinder;
	t_mat	*identity;

	cylinder = ft_cylinder_new(
			ft_vec_new(4, 1.0, 2.0, 3.0, 1.0),
			ft_vec_new(4, 4.0, 5.0, 6.0, 0.0),
			ft_vec_new(2, 5.0, 10.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	identity = ft_mat_identity(4);
	ft_mat_mul(cylinder->fr_world, cylinder->to_world);
	if (eq_mat(identity, cylinder->fr_world) == 0)
		printf("ft_cylinder_new: Error!\n");
	else
		printf("ft_cylinder_new: OK\n");
	ft_obj_del(cylinder);
	ft_mat_del(identity);
}

void	test_intersect(void)
{
	t_obj	*cylinder;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	point = ft_vec_new(4);
	norm.data = NULL;
	cylinder = ft_cylinder_new(ft_vec_new(4, 8.0, 0.0, 0.0, 1.0),
			ft_vec_new(4, 0.0, 0.0, 1.0, 0.0),
			ft_vec_new(2, 2.0, 100.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	ray = ft_ray_new(ft_vec_new(4, 4.0, 4.0, 0.0, 1.0),
			ft_vec_new(4, 1.0, -1.0, 0.0, 0.0));
	ft_cylinder_intersect(cylinder, ray, point, &norm);
	target_p = ft_vec_new(4, 8 - pow(2, 0.5), pow(2, 0.5), 0.0, 1.0);
	target_n = ft_vec_new(4, -pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	if (eq_vec(point, target_p) == 0 || eq_vec(&norm, target_n) == 0)
		printf("ft_cylinder_intersect: Error!\n");
	else
		printf("ft_cylinder_intersect: OK\n");
	ft_obj_del(cylinder);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	ft_vec_del(point);
	free(norm.data);
}

void	test_no_intersect(void)
{
	t_obj	*cylinder;
	t_ray	*ray;
	t_vec	*point;
	t_vec	norm;

	point = ft_vec_new(4);
	norm.data = NULL;
	cylinder = ft_cylinder_new(ft_vec_new(4, 4.0, 0.0, 0.0, 1.0),
			ft_vec_new(4, 0.0, 0.0, 1.0, 0.0),
			ft_vec_new(2, 1.0, 100.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	ray = ft_ray_new(ft_vec_new(4, 2.0, 2.0, 0.0, 1.0),
			ft_vec_new(4, -1.0, 1.0, 0.0, 0.0));
	if (ft_cylinder_intersect(cylinder, ray, point, &norm) == 1)
		printf("ft_cylinder_intersect no intersect: Error!\n");
	else
		printf("ft_cylinder_intersect no intersect: OK\n");
	ft_obj_del(cylinder);
	ft_ray_del(ray);
	ft_vec_del(point);
	free(norm.data);
}

void	test_normal(void)
{
	t_obj	*cylinder;
	t_vec	*point;
	t_vec	*target;
	t_vec	norm;

	norm.data = NULL;
	cylinder = ft_cylinder_new(
			ft_vec_new(4, 0.0, 0.0, 0.0, 1.0),
			ft_vec_new(4, 0.0, 0.0, 1.0, 0.0),
			ft_vec_new(2, 2.0, 100.0),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	point = ft_vec_new(4, -pow(2, 0.5), pow(2, 0.5), 0.0, 1.0);
	target = ft_vec_new(4, -pow(2, 0.5) / 2, pow(2, 0.5) / 2, 0.0, 0.0);
	ft_cylinder_normal(cylinder, point, &norm);
	if (eq_vec(&norm, target) == 0 || eq_double(ft_vec_len(&norm), 1) == 0)
		printf("ft_cylinder_normal: Error!\n");
	else
		printf("ft_cylinder_normal: OK\n");
	ft_obj_del(cylinder);
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
