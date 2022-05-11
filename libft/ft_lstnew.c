/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:26 by weng              #+#    #+#             */
/*   Updated: 2022/05/11 11:25:10 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a new element. The variable
'content' is initialized with the value of the parameter 'content'. The
variable 'next' is initialized to NULL.
*/
t_list	*ft_lstnew(void *content, int type)
{
	t_list	*retval;

	retval = (t_list *) malloc(sizeof(t_list));
	if (retval != NULL)
	{
		retval->content = content;
		retval->type = type;
		retval->next = NULL;
	}
	return (retval);
}
