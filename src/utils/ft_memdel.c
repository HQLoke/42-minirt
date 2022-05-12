/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:06:39 by hloke             #+#    #+#             */
/*   Updated: 2022/05/12 09:06:51 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 
Free any double pointer of any data type
Must typecast using (void **)
*/
void	ft_memdel(void **ptr)
{
	int	i;

	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i] != NULL)
		{
			free (ptr[i]);
			i += 1;
		}
		free (ptr);
	}
}
