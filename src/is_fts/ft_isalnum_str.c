/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <abeauvoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 05:01:40 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/01/15 05:30:18 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool		is_alnum_str(const char *s)
{
	while (ft_isalnum(*s))
		++s;
	return (*s == '\0');
}

t_bool		is_alnum_strn(const char *s, size_t n)
{
	while (n-- && ft_isalnum(*s))
		++s;
	return (n == 0);
}
