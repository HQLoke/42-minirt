/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:47:02 by hloke             #+#    #+#             */
/*   Updated: 2022/05/23 10:49:20 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Converts string to long number
*/
long	ft_atol(const char *s)
{
	int		i;
	long	retval;
	long	sign;

	i = 0;
	sign = 1;
	retval = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		retval = retval * 10 + s[i] - '0';
		i++;
	}
	return (retval * sign);
}
