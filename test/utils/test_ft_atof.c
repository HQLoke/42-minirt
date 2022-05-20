/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:50 by weng              #+#    #+#             */
/*   Updated: 2022/05/20 16:48:58 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_atof(void)
{
	const char	input[][100] = {
		"-1",
		"-999",
		"0.0",
		"-0.0",
		"9.90000000",
		"-9.90000000",
		"9.900000500",
		"-9.900000500",
		"3.14159265359",
		"-3.14159265359",
		"2147483647.214748",
		"-2147483648.214748",
		"2147483647.00000000",
		"-2147483648.00000000",
		"2147483647.2147483647",
		"-2147483648.2147483648"};
	int			n;
	double		target;
	double		val;
	int			retval;

	retval = 1;
	n = sizeof(input) / sizeof(input[0]);
	while (n-- > 0)
	{
		target = atof(input[n]);
		val = ft_atof(input[n]);
		if (eq_double(target, val) == 0)
		{
			printf("ft_atof: Error for input %s\n", input[n]);
			printf("   atof output = %.16e\n", target);
			printf("ft_atof output = %.16e\n\n", val);
			retval = 0;
		}
	}
	if (retval == 1)
		printf("ft_atof: OK\n");
}

int	main(void)
{
	test_atof();
	return (0);
}
