/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:11:03 by weng              #+#    #+#             */
/*   Updated: 2022/06/11 14:29:07 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/* Parse a line into a camera object
 * Specification: C centre orientation fov
 */
t_cam	*ft_parse_camera(char **arr)
{
	static int	count = 0;
	t_vec		*ctr;
	t_vec		*orient;
	t_vec		*fov;
	t_cam		*cam;

	if (++count > 1)
		ft_perror("ft_parse_camera: More than one camera is defined.");
	if (ft_array_size(arr) != 4)
		ft_perror("ft_parse_camera: Invalid number of parameters");
	ctr = ft_parse_vector(arr[1], 3, -INFINITY, INFINITY);
	ctr = ft_vec_append(ctr, 1);
	orient = ft_parse_vector(arr[2], 3, -1, 1);
	orient = ft_vec_append(orient, 0);
	fov = ft_parse_vector(arr[3], 1, 0, 180);
	cam = ft_camera_new(ctr, orient, fov->data[0]);
	ft_array_del(arr, free);
	ft_vec_del(fov);
	return (cam);
}
