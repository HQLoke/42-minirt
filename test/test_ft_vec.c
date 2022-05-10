/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:32:53 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 00:09:08 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_new(void)
{
	t_vec	*vec;

	vec = ft_vec3_new(1, 2.3, 45.6);
	if (vec->size != 3
		|| eq_double(1, vec->data[0]) == 0
		|| eq_double(2.3, vec->data[1]) == 0
		|| eq_double(45.6, vec->data[2]) == 0)
		printf("ft_vec3_new: Error!\n");
	else
		printf("ft_vec3_new: OK\n");
	ft_vec_del(vec);
}

int	main(void)
{
	test_new();
	return (0);
}
