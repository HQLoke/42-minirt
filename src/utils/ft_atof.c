/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:55 by hloke             #+#    #+#             */
/*   Updated: 2022/05/24 10:29:46 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Converts string to floating number
*/
double	ft_atof(const char *nptr)
{
	double	retval;
	int		decimal;
	int		sign;

	retval = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr != '\0' && *nptr != '.')
	{
		retval *= 10;
		retval += *nptr - '0';
		nptr += 1;
	}
	retval *= sign;
	if (*nptr == '.')
		nptr += 1;
	decimal = 1;
	while (ft_isdigit(*nptr) == 1)
	{
		if (retval > 0)
			retval += ((*nptr - '0') / pow(10, decimal));
		else
			retval -= ((*nptr - '0') / pow(10, decimal));
		decimal += 1;
		nptr += 1;
	}
	if (*nptr == 'e')
		nptr += 1;
	int mul = 0;
	while (ft_isdigit(*nptr) == 1)
	{
		mul *= 10;
		mul += *nptr - '0';
		nptr += 1;
	}
	while (mul-- > 0)
		retval *= 10;
	return (retval);
}
