/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:15:54 by hloke             #+#    #+#             */
/*   Updated: 2022/06/10 14:55:07 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
This function serves two purposes
One is to check if data size is equal to size, returns 1 if false
Two is to check if each data value is within min/max, returns 2 if false
Returns 0 if all true
Remember to free the arr in the caller function
*/
int	ft_check_float(char **data, size_t size, double min, double max)
{
	if (ft_array_size(data) != size)
		return (1);
	while (*data != NULL)
	{
		if (ft_atof(*data) < min || ft_atof(*data) > max)
			return (2);
		data += 1;
	}	
	return (0);
}
