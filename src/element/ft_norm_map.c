/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:12:33 by weng              #+#    #+#             */
/*   Updated: 2022/06/08 15:37:55 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* Generate a norm map based on a given pathname. The normal map is normalised
 * as unit vectors to remove any rounding effects during importing. */
t_img	*ft_norm_map(const char *pathname)
{
	t_img	*img;
	t_vec	vec;
	size_t	i;

	if (pathname == NULL)
		return (NULL);
	img = ft_ppm_2_image(pathname);
	i = img->row * img->col * 3;
	while (i-- > 0)
		img->data[i] = 2 * img->data[i] - 1;
	vec.size = 3;
	i = -1;
	while (++i < img->row * img->col)
	{
		vec.data = &img->data[i * 3];
		ft_vec_normalise(&vec);
	}
	return (img);
}

/* Return the normal map on a sphere */
t_vec	*ft_sphere_norm_map(t_obj *sp, t_vec *point, t_vec *norm)
{
	double	theta;
	double	phi;
	t_vec	*colour;
	t_vec	*bump;
	t_mat	*transform;

	theta = acos(point->data[2] / sp->dimension->data[0]);
	phi = atan2(point->data[1], point->data[0]);
	colour = ft_image_get(sp->norm_map,
			(int)(theta / M_PI * sp->norm_map->row),
			(int)((phi / M_PI / 2 + 0.5) * sp->norm_map->col));
	bump = ft_vec4_new(colour->data[0], colour->data[1], colour->data[2], 0);
	transform = ft_affine_rotate(norm);
	bump = ft_mat_mul_vec(transform, bump);
	ft_vec_swap(norm, bump);
	ft_vec_del(colour);
	ft_vec_del(bump);
	ft_mat_del(transform);
	return (norm);
}
