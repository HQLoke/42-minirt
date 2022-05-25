/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:32:55 by hloke             #+#    #+#             */
/*   Updated: 2022/05/25 15:23:23 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Handles the integral component of a number as a double, and moves
 * the pointer to the unhandled part of the string. */
static double	ft_atof_integral(const char **nptr)
{
	double	retval;
	int		sign;

	retval = 0;
	sign = 1;
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '+' || **nptr == '-')
		++(*nptr);
	while (ft_isdigit(**nptr) == 1)
	{
		retval = retval * 10 + (**nptr - '0');
		++(*nptr);
	}
	return (sign * retval);
}

/*
Converts string to floating number
*/
double	ft_atof(const char *nptr)
{
	double	retval;
	double	decimal;
	int		sign;

	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		++nptr;
	retval = ft_atof_integral(&nptr);
	if (*nptr == '.')
	{
		decimal = 0.1;
		while (ft_isdigit(*(++nptr)) == 1)
		{
			retval += (*nptr - '0') * decimal;
			decimal /= 10;
		}
	}
	if (*nptr++ == 'e')
		return (sign * retval * pow(10, ft_atof_integral(&nptr)));
	else
		return (sign * retval);
}
