/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:48 by hloke             #+#    #+#             */
/*   Updated: 2022/05/11 19:55:48 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Ambient lighting
*/
void	check_ambient(char **info, int line_num, t_list **error)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(error, ft_lstnew("More than 1 ambience", line_num));
	if (ft_array_size(info) != 3)
	{
		ft_lstadd_back(error,
			ft_lstnew("A [Ambient lighting ratio] [RGB colors]", line_num));
		return ;
	}
}

/*
Camera
*/
void	check_camera(char **info, int line_num, t_list **error)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(error, ft_lstnew("More than 1 camera", line_num));
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(error,
			ft_lstnew("C [Viewpoint x,y,z] [3D normalized orientation vector] \
				[FOV: Horizontal field of view in degrees]", line_num));
		return ;
	}
}

/*
Light
*/
void	check_light(char **info, int line_num, t_list **error)
{
	static int	count;

	count += 1;
	if (count > 1)
		ft_lstadd_back(error, ft_lstnew("More than 1 light source", line_num));
	if (ft_array_size(info) != 4)
	{
		ft_lstadd_back(error,
			ft_lstnew("L [Lightpoint x,y,z] [Light brightness ratio] \
				[RGB colors]", line_num));
		return ;
	}
}
