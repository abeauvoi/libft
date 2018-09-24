/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:38:38 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/09/16 04:15:13 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_base(long int nb, unsigned char base)
{
	unsigned long int	tmp;

	tmp = (nb < 0 ? -nb : nb);
	if (nb < 0)
		ft_putchar('-');
	if (tmp >= base)
		ft_putnbr_base(tmp / base, base);
	ft_putchar(XDIGITS_UPCASE[tmp % base]);
}
