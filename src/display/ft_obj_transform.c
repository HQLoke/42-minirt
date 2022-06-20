/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:45:02 by hloke             #+#    #+#             */
/*   Updated: 2022/06/19 19:14:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_obj_rotate_x(t_obj *obj, double theta)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_rotate_x(theta);
	ft_mat_mul(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_rotate_y(t_obj *obj, double theta)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_rotate_y(theta);
	ft_mat_mul(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_rotate_z(t_obj *obj, double theta)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_rotate_z(theta);
	ft_mat_mul(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_scale(t_obj *obj, double scale)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_scale(scale);
	ft_mat_mul(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}

void	ft_obj_translate(t_obj *obj, double dx, double dy, double dz)
{
	t_mat	*transform;

	if (obj == NULL)
		return ;
	transform = ft_affine_translate(dx, dy, dz);
	ft_mat_mul(obj->to_world, transform);
	ft_mat_del(transform);
	ft_mat_del(obj->fr_world);
	obj->fr_world = ft_mat_affine_inverse(ft_mat_copy(obj->to_world));
}