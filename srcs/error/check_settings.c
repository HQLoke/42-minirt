/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:48 by hloke             #+#    #+#             */
/*   Updated: 2022/05/12 10:34:58 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Ambient lighting
*/
void	check_ambient(char **info, int line_num, t_list **err)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(err, ft_lstnew("More than 1 ambience", line_num));
	if (ft_array_size(info) != 3)
	{
		ft_lstadd_back(err, ft_lstnew("A [Ambient lighting ratio] "
				"[RGB colors]", line_num));
		return ;
	}
	if (atof(info[1]) < 0.0 && atof(info[1]) > 1.0)
		ft_lstadd_back(err, ft_lstnew("Ambient lighting ratio in range "
				"[0.0, 1.0]", line_num));
	check_rgb(info[2], line_num, err);
}

/*
Camera
*/
void	check_camera(char **info, int line_num, t_list **err)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(err, ft_lstnew("More than 1 camera", line_num));
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(err, ft_lstnew("C [Viewpoint x,y,z] [3D normalized "
				"orientation vector] [Horizontal field of view in degrees]",
				line_num));
		return ;
	}
	check_xyz(info[1], line_num, err);
	check_vector(info[2], line_num, err);
	if (atof(info[3]) < 0.0 && atof(info[3]) > 180.0)
		ft_lstadd_back(err, ft_lstnew("Horizontal FOV in range [0, 180] "
				"degrees", line_num));
}

/*
Light
*/
void	check_light(char **info, int line_num, t_list **err)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(err, ft_lstnew("More than 1 light source", line_num));
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(err, ft_lstnew("L [Lightpoint x,y,z] [Light brightness "
				"ratio] [RGB colors]", line_num));
		return ;
	}
	check_xyz(info[1], line_num, err);
	if (atof(info[2]) < 0.0 && atof(info[2]) > 1.0)
		ft_lstadd_back(err, ft_lstnew("Light brightness ratio in range "
				"[0.0, 1.0]", line_num));
	check_rgb(info[3], line_num, err);
}
