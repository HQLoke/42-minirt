/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:26:22 by hloke             #+#    #+#             */
/*   Updated: 2022/06/15 21:34:16 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	ft_loop(t_window *window)
{
	ft_draw_img8(window, window->img8);
	return (1);
}