/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:41:28 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/08/01 14:08:36 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void 		*ft_realloc(void *ptr, size_t size)
{
	void 	*realloc;

	if (!size && ptr)
	{
		if (!(realloc = malloc(1)))
			return (NULL);
		free(ptr);
		return (realloc);
	}
	if (!(realloc = malloc(size)))
		return (NULL);
	ft_memcpy(realloc, ptr, size);
	free(ptr);
	return (realloc);
}
