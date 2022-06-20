/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:45:02 by hloke             #+#    #+#             */
/*   Updated: 2022/06/20 17:07:28 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_obj_rotate_x(t_obj *obj, double theta)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_rotate_x(theta);
	obj->orient = ft_mat_mul_vec(transform, obj->orient);
	ft_mat_del(transform);
	ft_mat_del(obj->to_world);
	ft_mat_del(obj->fr_world);
	obj->to_world = ft_affine_transform(
			obj->rotate_z, obj->centre, obj->orient);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_rotate_y(t_obj *obj, double theta)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_rotate_y(theta);
	obj->orient = ft_mat_mul_vec(transform, obj->orient);
	ft_mat_del(transform);
	ft_mat_del(obj->to_world);
	ft_mat_del(obj->fr_world);
	obj->to_world = ft_affine_transform(
			obj->rotate_z, obj->centre, obj->orient);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_rotate_z(t_obj *obj, double theta)
{
	if (obj == NULL)
		return ;
	obj->rotate_z += theta;
	ft_mat_del(obj->to_world);
	ft_mat_del(obj->fr_world);
	obj->to_world = ft_affine_transform(
			obj->rotate_z, obj->centre, obj->orient);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_translate(t_obj *obj, double dx, double dy, double dz)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_translate(dx, dy, dz);
	transform = ft_mat_mul(transform, obj->to_world);
	ft_mat_swap(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}
