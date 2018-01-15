/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <abeauvoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 05:05:10 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/01/15 05:30:18 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bool		is_digit_str(const char *s)
{
	while (ft_isdigit(*s))
		++s;
	return (*s == '\0');
}

t_bool		is_digit_nstr(const char *s, size_t n)
{
	while (n-- && ft_isdigit(*s))
		++s;
	return (n == 0);
}
