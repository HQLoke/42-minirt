/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:28:12 by weng              #+#    #+#             */
/*   Updated: 2022/05/10 23:54:42 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* Returns true if two doubles are nearly equal in value, false otherwise. */
int	eq_double(double a, double b)
{
	return (fabs(a - b) <= (DBL_EPSILON * fabs(a + b)));
}
