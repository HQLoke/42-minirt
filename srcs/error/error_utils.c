/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:00:03 by hloke             #+#    #+#             */
/*   Updated: 2022/05/11 20:16:35 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Returns true if in range, else returns false
*/
bool	check_float_range(double value, double min, double max)
{
	if (value >= min && value <= max)
		return (true);
	return (false);
}

/*
Given a 2D array, return the number of elements in the array
*/
size_t	ft_array_size(char **array)
{
	size_t	num;

	num = 0;
	if (array != NULL)
	{
		while (array[num] != NULL)
			num += 1;
	}
	return (num);
}

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
