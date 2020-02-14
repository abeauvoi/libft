/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:38:38 by abeauvoi          #+#    #+#             */
/*   Updated: 2020/02/13 19:52:16 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_base(int64_t nb, uint8_t base)
{
	uint64_t	tmp;

	tmp = (nb < 0 ? -nb : nb);
	if (nb < 0)
		ft_putchar('-');
	if (tmp >= base)
		ft_putnbr_base(tmp / base, base);
	ft_putchar(XDIGITS_UPCASE[tmp % base]);
}
