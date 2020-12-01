/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:41:55 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/12/01 21:58:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	while (*alst)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		(del)(tmp->content);
		free(tmp);
	}
	free(*alst);
	*alst = NULL;
}
