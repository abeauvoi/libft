/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:49:26 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 18:34:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	(del)((*alist)->content, (*alist)->content_size);
	free(*alist);
	*alist = NULL;
}
