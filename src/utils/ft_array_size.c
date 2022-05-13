/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:06:59 by hloke             #+#    #+#             */
/*   Updated: 2022/05/12 09:07:09 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
