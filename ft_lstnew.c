/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:23:49 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/10 19:26:51 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void *content, size_t content_size, t_bool mode)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (mode == FT_LSTNEW_CPY)
			new->content = ft_memcpy(ft_memalloc(content_size),
					content, content_size);
		else
			new->content = content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
