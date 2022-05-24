/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:52:36 by hloke             #+#    #+#             */
/*   Updated: 2022/05/24 15:14:09 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minirt.h>

int	main(void)
{
	int		i;
	char	**info;
	char	**spec;
	void	(*f[6])(char **, int, t_list**);

	info = ft_split(line, ' ');
	spec = ft_split("A C L sp pl cy", ' ');
	f[0] = check_ambient;
	f[1] = check_camera;
	f[2] = check_light;
	f[3] = check_sphere;
	f[4] = check_plane;
	f[5] = check_cylinder;
	i = 0;
	while (spec[i] != NULL)
	{
		if (ft_strcmp(info[0], spec[i]) == 0)
		{
			f[i](info, line_num, error);
			break ;
		}
		i += 1;	
	}
	if (i == 6)
		ft_lstadd_back(error, ft_lstnew("Invalid type identifier", line_num));
	ft_memdel((void **)info);
	ft_memdel((void **)spec);
}
