/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:55 by hloke             #+#    #+#             */
/*   Updated: 2022/05/18 13:49:20 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Converts string to floating number
*/
double	ft_atof(const char *str)
{
	double	retval;
	double	tmp;
	char	*temp;
	int		len;

	retval = (double)ft_atoi(str);
	while (*str != '\0' && *str != '.')
		str += 1;
	if (*str == '.')
		str += 1;
	len = ft_strlen(str);
	if (len > 6)
	{
		len = 7;
		temp = ft_substr(str, 0, 7);
		tmp = (double)ft_atoi(temp);
		free(temp);
	}
	else
		tmp = (double)ft_atoi(str);
	while (len--)
		tmp /= 10;
	if (retval < 0)
		return (retval - tmp);
	return (retval + tmp);
}
