/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:27:23 by hloke             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/06/11 11:05:59 by weng             ###   ########.fr       */
=======
/*   Updated: 2022/06/14 11:15:09 by hloke            ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>

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
	// ft_error(argv[1]);

	t_window window;
	ft_window_start(&window);
	ft_window_run(&window);
	return (0);
}
