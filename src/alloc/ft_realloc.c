/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:41:28 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 09:14:56 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void 		*ft_realloc(void *ptr, size_t size)
{
	void 	*realloc;

	if (size == 0 && ptr != NULL)
	{
		if ((realloc = malloc(1)) == NULL)
			return (NULL);
		free(ptr);
		return (realloc);
	}
	if ((realloc = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(realloc, ptr, size);
	free(ptr);
	return (realloc);
}
