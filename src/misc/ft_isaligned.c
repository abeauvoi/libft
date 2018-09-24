/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isaligned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 05:17:37 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 08:34:51 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline bool		ft_isaligned(const void *ptr, unsigned char alignment)
{
	return (((unsigned char)ptr & (alignment - 1)) == 0);
}
