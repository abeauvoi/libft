/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:12:25 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 18:38:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWER_BOUND (' ')
#define UPPER_BOUND ('~' - LOWER_BOUND)

int		ft_isprint(int c)
{
	return ((unsigned char)(c - LOWER_BOUND) <= UPPER_BOUND);
}
