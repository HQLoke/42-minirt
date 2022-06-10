/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:34:22 by hloke             #+#    #+#             */
/*   Updated: 2022/06/11 01:01:55 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/* Print error and exit the program with error code 1. */
void	ft_perror(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}
