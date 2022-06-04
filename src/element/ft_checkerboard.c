/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:13:38 by weng              #+#    #+#             */
/*   Updated: 2022/06/04 17:28:30 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

/* return a checkerboard colour on a sphere, given a point on the local view */
t_vec	*ft_sphere_checkerboard(t_obj *sp, t_vec *point)
{
	int		steps;
	double	angle;
	double	theta;
	double	phi;

	steps = (2 * M_PI * sp->dimension->data[0]) / 0.5;
	steps = steps - (steps % 2);
	angle = 360.0 / steps * M_PI / 180;
	theta = acos(point->data[2] / sp->dimension->data[0]);
	phi = atan2(point->data[1], point->data[0]);
	steps = (int)(theta / angle) + (int)(phi / angle) + (point->data[1] < 0);
	if (steps % 2 == 0)
		return (ft_vec3_new(0.75, 0.75, 0.75));
	else
		return (ft_vec3_new(0.25, 0.25, 0.25));
}
