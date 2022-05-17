/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:55 by hloke             #+#    #+#             */
/*   Updated: 2022/05/17 11:18:22 by hloke            ###   ########.fr       */
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
	int		len;
	
	retval = (double)ft_atoi(str);
	while (*str != '\0' && *str != '.')
		str += 1;
	if (*str == '.')
		str += 1;
	tmp = (double)ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		tmp /= 10;
	return (retval + tmp);
}
