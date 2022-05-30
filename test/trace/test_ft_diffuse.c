/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_diffuse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:05:44 by weng              #+#    #+#             */
/*   Updated: 2022/05/30 14:30:37 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_hit_obj(void)
{
	t_obj	*obj1;
	t_obj	*obj2;
	t_obj	*obj_min;
	t_list	*objs;
	t_ray	*ray;
	t_vec	point;
	t_vec	norm;

	point.data = NULL;
	norm.data = NULL;
	objs = NULL;
	obj1 = ft_sphere_new(ft_vec4_new(10, 0, 0, 1), 1, ft_vec3_new(1, 1, 1));
	obj2 = ft_sphere_new(ft_vec4_new(5, 0, 0, 1), 1, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&objs, ft_lstnew(obj1, 0));
	ft_lstadd_back(&objs, ft_lstnew(obj2, 0));
	ray = ft_ray_new(ft_vec4_new(0, 0, 0, 1), ft_vec4_new(1, 0, 0, 0));
	obj_min = ft_hit_objs(ray, objs, &point, &norm);
	if (obj_min != obj2)
		printf("ft_hit_objs: Error!\n");
	else
		printf("ft_hit_objs: OK\n");
	ft_lstclear(&objs, (void (*)(void *)) ft_obj_del);
	ft_ray_del(ray);
	free(point.data);
	free(norm.data);
}

void	test_hit_light(void)
{
	t_light	*light;
	t_ray	*ray;
	t_list	*objs;
	t_obj	*obj;

	light = ft_point_new(ft_vec4_new(5, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	ray = ft_ray_new(ft_vec4_new(0, 0, 0, 1), ft_vec4_new(1, 0, 0, 0));
	objs = NULL;
	obj = ft_sphere_new(ft_vec4_new(10, 0, 0, 1), 1, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&objs, ft_lstnew(obj, 0));
	if (ft_hit_light(light, ray, objs) == 0)
		printf("ft_hit_light: Error!\n");
	else
		printf("ft_hit_light: OK\n");
	ft_light_del(light);
	ft_ray_del(ray);
	ft_lstclear(&objs, (void (*)(void *)) ft_obj_del);
}

void	test_hit_light_false(void)
{
	t_light	*light;
	t_ray	*ray;
	t_list	*objs;
	t_obj	*obj;

	light = ft_point_new(ft_vec4_new(5, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	ray = ft_ray_new(ft_vec4_new(0, 0, 0, 1), ft_vec4_new(1, 0, 0, 0));
	objs = NULL;
	obj = ft_sphere_new(ft_vec4_new(4, 0, 0, 1), 1, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&objs, ft_lstnew(obj, 0));
	if (ft_hit_light(light, ray, objs) == 1)
		printf("ft_hit_light blocked: Error!\n");
	else
		printf("ft_hit_light blocked: OK\n");
	ft_light_del(light);
	ft_ray_del(ray);
	ft_lstclear(&objs, (void (*)(void *)) ft_obj_del);
}

void	test_light_intensity(void)
{
	t_light	*light;
	t_vec	*point;
	t_vec	*norm;
	t_vec	*intensity;
	t_vec	*target;
	double	factor;

	light = ft_point_new(ft_vec4_new(5, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	point = ft_vec4_new(0, 0, 0, 1);
	norm = ft_vec4_new(1, 0, 0, 0);
	factor = light->param->data[0]
			+ light->param->data[1] * 5
			+ light->param->data[2] * 5 * 5;
	target = ft_vec_mul_scalar(ft_vec_copy(light->colour), 1 / factor);
	intensity = ft_light_intensity(light, NULL, point, norm);
	if (eq_vec(target, intensity) == 0)
		printf("ft_light_intensity: Error!\n");
	else
		printf("ft_light_intensity: OK\n");
	ft_light_del(light);
	ft_vec_del(point);
	ft_vec_del(norm);
	ft_vec_del(intensity);
	ft_vec_del(target);
}

void	test_sum_intensity(void)
{
	t_list	*light;
	t_light	*ambient;
	t_light	*l1;
	t_light *l2;
	t_light *l3;
	t_vec	*point;
	t_vec	*norm;
	t_vec	*intensity;
	t_vec	*target;
	double	factor;

	light = NULL;
	ambient = ft_ambient_new(0.2, ft_vec3_new(1, 1, 1));
	l1 = ft_point_new(ft_vec4_new(5, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	l2 = ft_point_new(ft_vec4_new(10, 10, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	l3 = ft_point_new(ft_vec4_new(-10, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&light, ft_lstnew(ambient, 0));
	ft_lstadd_back(&light, ft_lstnew(l1, 0));
	ft_lstadd_back(&light, ft_lstnew(l2, 0));
	ft_lstadd_back(&light, ft_lstnew(l3, 0));
	point = ft_vec4_new(0, 0, 0, 1);
	norm = ft_vec4_new(1, 0, 0, 0);
	factor = 0.2;
	factor += 1 / (l1->param->data[0]
			+ l1->param->data[1] * 5
			+ l1->param->data[2] * 5 * 5);
	factor += 1 / (l2->param->data[0]
			+ l2->param->data[1] * 10 * sqrt(2)
			+ l2->param->data[2] * 10 * 10 * 2) * cos(M_PI / 4);
	target = ft_vec_mul_scalar(ft_vec_copy(l1->colour), factor);
	intensity = ft_sum_intensities(light, NULL, point, norm);
	if (eq_vec(target, intensity) == 0)
		printf("ft_sum_intensities: Error!\n");
	else
		printf("ft_sum_intensities: OK\n");
	ft_lstclear(&light, (void (*)(void *)) ft_light_del);
	ft_vec_del(point);
	ft_vec_del(norm);
	ft_vec_del(intensity);
	ft_vec_del(target);
}

void	test_diffuse(void)
{
	t_list	*light;
	t_light	*ambient;
	t_light	*l1;
	t_obj	*obj;
	t_vec	*point;
	t_vec	*norm;
	t_hit	hit;
	t_vec	*intensity;
	t_vec	*target;
	double	factor;

	light = NULL;
	ambient = ft_ambient_new(0.2, ft_vec3_new(1, 1, 1));
	l1 = ft_point_new(ft_vec4_new(5, 0, 0, 1), 0.2, ft_vec3_new(1, 1, 1));
	ft_lstadd_back(&light, ft_lstnew(ambient, 0));
	ft_lstadd_back(&light, ft_lstnew(l1, 0));
	obj = ft_sphere_new(
			ft_vec4_new(-1, 0, 0, 1), 1, ft_vec3_new(0.1, 0.3, 0.5));
	point = ft_vec4_new(0, 0, 0, 1);
	norm = ft_vec4_new(1, 0, 0, 0);
	factor = 0.2;
	factor += 1 / (l1->param->data[0]
			+ l1->param->data[1] * 5
			+ l1->param->data[2] * 5 * 5);
	target = ft_vec_mul_scalar(ft_vec_copy(l1->colour), factor);
	target = ft_vec_mul_elem(target, obj->colour);
	hit.obj = obj;
	hit.point = point;
	hit.norm = norm;
	intensity = ft_diffuse(&hit, NULL, light);
	if (eq_vec(target, intensity) == 0)
		printf("ft_diffuse: Error!\n");
	else
		printf("ft_diffuse: OK\n");
	ft_lstclear(&light, (void (*)(void *)) ft_light_del);
	ft_obj_del(obj);
	ft_vec_del(point);
	ft_vec_del(norm);
	ft_vec_del(intensity);
	ft_vec_del(target);
}

int	main(void)
{
	test_hit_obj();
	test_hit_light();
	test_hit_light_false();
	test_light_intensity();
	test_sum_intensity();
	test_diffuse();
	return (0);
}