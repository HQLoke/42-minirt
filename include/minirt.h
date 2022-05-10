/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:27:06 by weng              #+#    #+#             */
/*   Updated: 2022/05/10 17:04:06 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vec
{
	size_t	size;
	double	*data;
}	t_vec;

// ft_vec.c
t_vec	*ft_vec_new(size_t n, ...);
t_vec	*ft_vec3_new(double x, double y, double z);
void	ft_vec_del(t_vec *vec);

#endif
