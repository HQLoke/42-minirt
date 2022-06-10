/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:06:39 by hloke             #+#    #+#             */
/*   Updated: 2022/06/10 14:55:11 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/* 
Deletes the elements pointed to by the pointers in a NULL terminated
array of pointers 'ptr' using the function 'del', free the array itself.
*/
void	ft_memdel(void *ptr, void (*del)(void *))
{
	void	**elem;

	if (ptr == NULL)
		return ;
	if (del != NULL)
	{
		elem = ptr;
		while (*elem != NULL)
			del(*elem++);
	}
	free(ptr);
}
