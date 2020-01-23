/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:17:20 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/12/05 22:34:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char			*ft_strncat(char *dst, const char *src, size_t n)
{
	return (ft_strncpy(dst + ft_strlen(dst), src, n));
}
