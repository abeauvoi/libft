/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:07:43 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 18:38:39 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWER_BOUND ('A')
#define UPPER_BOUND ('Z' - LOWER_BOUND)

int	ft_isupper(int c)
{
	return ((unsigned char)(c - LOWER_BOUND) <= UPPER_BOUND);
}
