/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:44:30 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/17 06:30:32 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

inline int			ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (uc == ' '
			|| uc == '\f'
			|| uc == '\n'
			|| uc == '\r'
			|| uc == '\t'
			|| uc == '\v');
}