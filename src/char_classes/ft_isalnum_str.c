/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <abeauvoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 05:01:40 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 17:58:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isalnum_str(const char *s)
{
	while (ft_isalnum(*s))
		++s;
	return (*s == '\0');
}

int		ft_isalnum_nstr(const char *s, size_t n)
{
	while (n-- > 0 && ft_isalnum(*s))
		++s;
	return (n == 0);
}
