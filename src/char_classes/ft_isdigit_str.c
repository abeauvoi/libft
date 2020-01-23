/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <abeauvoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 05:05:10 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 17:48:10 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isdigit_str(const char *s)
{
	while (ft_isdigit(*s))
		++s;
	return (*s == '\0');
}

int		ft_isdigit_nstr(const char *s, size_t n)
{
	while (n-- > 0 && ft_isdigit(*s))
		++s;
	return (n == 0);
}
