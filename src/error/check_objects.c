/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:39 by hloke             #+#    #+#             */
/*   Updated: 2022/05/12 10:33:49 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Sphere
*/
void	check_sphere(char **info, int line_num, t_list **err)
{
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(err, ft_lstnew("sp [Sphere center x,y,z] [Sphere "
				"diameter] [RGB colors]", line_num));
		return ;
	}
	check_xyz(info[1], line_num, err);
	if (atof(info[2]) <= 0.0)
		ft_lstadd_back(err, ft_lstnew("Sphere diameter cannot be less/equal "
				"zero", line_num));
	check_rgb(info[3], line_num, err);
}

/*
Plane
*/
void	check_plane(char **info, int line_num, t_list **err)
{
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(err, ft_lstnew("pl [x,y,z] [3D normalized orientation "
				"vector] [RGB colors]", line_num));
		return ;
	}
	check_xyz(info[1], line_num, err);
	check_vector(info[2], line_num, err);
	check_rgb(info[3], line_num, err);
}

/*
Cylinder
*/
void	check_cylinder(char **info, int line_num, t_list **err)
{
	if (ft_array_size(info) != 6)
	{
		ft_lstadd_back(err, ft_lstnew("cy [x,y,z] [3D normalized orientation "
				"vector] [Cylinder diameter] [Cylinder height] [RGB colors]", \
		line_num));
		return ;
	}
	check_xyz(info[1], line_num, err);
	check_vector(info[2], line_num, err);
	if (atof(info[3]) <= 0.0)
		ft_lstadd_back(err, ft_lstnew("Cylinder diameter cannot be less/equal "
				"zero", line_num));
	if (atof(info[4]) <= 0.0)
		ft_lstadd_back(err, ft_lstnew("Cylinder height cannot be less/equal "
				"zero", line_num));
	check_rgb(info[5], line_num, err);
}
