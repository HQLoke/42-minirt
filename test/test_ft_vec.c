/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:32:53 by weng              #+#    #+#             */
/*   Updated: 2022/05/10 16:19:03 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_new(void)
{
	t_vec	*vec;
	size_t	i;

	vec = ft_vec3_new(1, 2.3, 45.6);
	printf("size = %ld\n", vec->size);
	i = 0;
	while (i < vec->size)
		printf("%f ", vec->data[i++]);
	printf("\n");
	ft_vec_del(vec);
}

int	main(void)
{
	test_new();
	return (0);
}
