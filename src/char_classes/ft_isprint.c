/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:12:25 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 17:57:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWER_BOUND (' ')
#define UPPER_BOUND ('~' - LOWER_BOUND)

inline int		ft_isprint(int c)
{
	return ((unsigned char)(c - LOWER_BOUND) <= UPPER_BOUND);
}
