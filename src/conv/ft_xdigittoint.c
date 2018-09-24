/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xdigittoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:20:27 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 07:20:21 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_xdigittoint(char c)
{
	int	d;

	d = c - '0';
	if ((unsigned char)d < 10)
		return (d);
	d = c - 'a';
	if ((unsigned char)d < 6)
		return (d + 10);
	d = c - 'A';
	if ((unsigned char)d < 6)
		return (d + 10);
	return (-1);
}
