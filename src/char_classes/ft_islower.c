/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:06:35 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/11/18 18:02:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWER_BOUND ('a')
#define UPPER_BOUND ('z' - LOWER_BOUND)

inline int	ft_islower(int c)
{
	return ((unsigned char)(c - LOWER_BOUND) <= UPPER_BOUND);
}
