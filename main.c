/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
/*   Updated: 2022/05/10 20:41:44 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	teach_them(void)
{
	printf("Usage: ./minirt [scene in format *.rt]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (teach_them());
	return (0);
}
