/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:06:59 by hloke             #+#    #+#             */
/*   Updated: 2022/05/25 11:23:07 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Return the size of a NULL terminated array of pointers.
*/
size_t	ft_array_size(const void *array)
{
	const void	**arr;
	size_t		num;

	arr = (const void **)array;
	num = 0;
	if (arr != NULL)
	{
		while (arr[num] != NULL)
			++num;
	}
	return (num);
}
