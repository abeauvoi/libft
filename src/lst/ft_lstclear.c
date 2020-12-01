/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:16:50 by mac               #+#    #+#             */
/*   Updated: 2020/12/01 22:34:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*prev;

	ptr = *lst;
	while (ptr != NULL)
	{
		del(ptr->content);
		prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
	*lst = NULL;
}
