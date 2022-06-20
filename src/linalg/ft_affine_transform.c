/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affine_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:58:17 by weng              #+#    #+#             */
/*   Updated: 2022/06/20 15:27:42 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

/* Calculate the rotation matrix 'A', given an orientation vector, such
 * that
 * A [0] = [x]
 *   [0]   [y]
 *   [1]   [z]
 *   [0]   [0]
 * where x, y & z are the corresponding values of the orientation vector.
 * Reference: https://math.stackexchange.com/questions/180418/
 * calculate-rotation-matrix-to-align-vector-a-to-vector-b-in-3d/897677#897677
 */
t_mat	*ft_affine_rotate(t_vec *orient)
{
	t_mat	*rotate;
	t_mat	*v;
	t_mat	*v2;

	if (eq_double(orient->data[2], -1) == 1)
		return (ft_affine_rotate_x(M_PI));
	v = ft_mat_empty(4, 4);
	v->data[0][2] = orient->data[0];
	v->data[1][2] = orient->data[1];
	v->data[2][0] = -orient->data[0];
	v->data[2][1] = -orient->data[1];
	v2 = ft_mat_mul(ft_mat_copy(v), v);
	v2 = ft_mat_mul_scalar(v2, 1 / (1 + orient->data[2]));
	rotate = ft_mat_identity(4);
	rotate = ft_mat_add(rotate, v);
	rotate = ft_mat_add(rotate, v2);
	ft_mat_del(v);
	ft_mat_del(v2);
	return (rotate);
}

/* Calculate the transformation matrix, given local z-axis orientation,
 * a centre and orientation. */
t_mat	*ft_affine_transform(double theta, t_vec *centre, t_vec *orient)
{
	t_mat	*transform;
	t_mat	*rotate_theta;
	t_mat	*rotate;

	if (eq_double(ft_vec_len(orient), 1) == 0)
		ft_perror("Orientation vector is not a unit vector.");
	transform = ft_affine_translate(
			centre->data[0], centre->data[1], centre->data[2]);
	rotate_theta = ft_affine_rotate_z(theta);
	rotate = ft_mat_mul(ft_affine_rotate(orient), rotate_theta);
	transform = ft_mat_mul(transform, rotate);
	ft_mat_del(rotate_theta);
	ft_mat_del(rotate);
	return (transform);
}
