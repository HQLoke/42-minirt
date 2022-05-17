/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:45:06 by weng              #+#    #+#             */
/*   Updated: 2022/05/17 15:06:19 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

void	test_new(void)
{
	t_obj	*plane;
	t_vec	*point;
	t_vec	*norm;

	point = ft_vec_new(4, 0.0, 1.0, 2.0, 1.0);
	norm = ft_vec_new(4, 3.0, 4.0, 5.0, 0.0);
	plane = ft_plane_new(
			ft_vec_copy(point),
			ft_vec_copy(norm),
			ft_vec_new(3, 0.0, 0.0, 0.0));
	norm->data[3] = -norm->data[0] * point->data[0]
		- norm->data[1] * point->data[1]
		- norm->data[2] * point->data[2];
	if (eq_vec(norm, plane->dimension) == 0)
		printf("ft_plane_new: Error!\n");
	else
		printf("ft_plane_new: OK\n");
	ft_obj_del(plane);
	ft_vec_del(point);
	ft_vec_del(norm);
}

void	test_intersect(void)
{
	t_obj	*plane;
	t_ray	*ray;
	t_vec	point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	target_p = ft_vec_new(4, 1.0, 1.0, 0.0, 1.0);
	target_n = ft_vec_new(4, 1.0, 1.0, 0.0, 0.0);
	plane = ft_plane_new(
			ft_vec_copy(target_p),
			ft_vec_copy(target_n),
			ft_vec_new(3, 1.0, 2.0, 3.0));
	ray = ft_ray_new(
			ft_vec_new(4, 0.0, 0.0, 0.0, 1.0),
			ft_vec_new(4, 1.0, 1.0, 0.0, 0.0));
	ft_plane_intersect(plane, ray, &point, &norm);
	if (eq_vec(&point, target_p) == 0 || eq_vec(&norm, target_n) == 0)
		printf("ft_plane_intersect: Error!\n");
	else
		printf("ft_plane_intersect: OK\n");
	ft_obj_del(plane);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	free(point.data);
	free(norm.data);
}

void	test_no_intersect(void)
{
	t_obj	*plane;
	t_ray	*ray;
	t_vec	point;
	t_vec	norm;
	t_vec	*target_p;
	t_vec	*target_n;

	target_p = ft_vec_new(4, 1.0, 1.0, 0.0, 1.0);
	target_n = ft_vec_new(4, 1.0, 1.0, 0.0, 0.0);
	point.data = NULL;
	norm.data = NULL;
	plane = ft_plane_new(
			ft_vec_copy(target_p),
			ft_vec_copy(target_n),
			ft_vec_new(3, 1.0, 2.0, 3.0));
	ray = ft_ray_new(
			ft_vec_new(4, 0.0, 0.0, 0.0, 1.0),
			ft_vec_new(4, -1.0, -1.0, 0.0, 0.0));
	if (ft_plane_intersect(plane, ray, &point, &norm) == 1)
		printf("ft_plane_intersect no intersect: Error!\n");
	else
		printf("ft_plane_intersect no intersect: OK\n");
	ft_obj_del(plane);
	ft_ray_del(ray);
	ft_vec_del(target_p);
	ft_vec_del(target_n);
	free(point.data);
	free(norm.data);
}

int	main(void)
{
	test_new();
	test_intersect();
	test_no_intersect();
	return (0);
}
