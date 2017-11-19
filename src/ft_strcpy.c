/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:34:41 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/14 16:36:37 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(char *dst, const char *src)
{
	char	*d;

	d = dst;
	while ((*d++ = *src++) != 0)
		;
	return (dst);
}