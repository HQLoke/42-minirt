/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/06/11 11:05:59 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	teach_them(void)
{
	printf("Usage: ./minirt [scene file in format *.rt]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (teach_them());
	(void) argv;
	return (0);
}
